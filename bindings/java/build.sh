#! /bin/bash

# ============================================
# set the repo base
# ============================================
VEROVIO_SOURCE=
if [ "X${VEROVIO_SOURCE}" == "X" ]; then
  echo "!! VEROVIO_SOURCE is not set !!";
  exit 1;
else
  echo -- VEROVIO_SOURCE is ${VEROVIO_SOURCE} --
fi

MAVEN=$(which mvn 2>/dev/null)
if [ "X${MAVEN}" == "X" ]; then
    echo "!! Maven (mvn) not found !!";
    exit 1;
else
    echo -- Maven is ${MAVEN} --
fi

JAVA=$(which java  2>/dev/null)
if [ "X{JAVA}" == "X" ]; then
    echo "!! java not found !!";
    exit 1;
else
  echo -- Java is ${JAVA}
fi

# ============================================
# values to set for environment
# shoudn't need to change anything else
# NOTE: JAVA_HOME must be set in environment
# NOTE: gcc must be in the path
# ============================================
SWIG=/opt/swig/bin/swig
CMAKE=/usr/bin/cmake
CMAKE_GENERATOR="Unix Makefiles"
PWD=/usr/bin/pwd
MKDIR=/bin/mkdir
RM=/bin/rm

# ============================================
# root paths
# ============================================
VEROVIO_JAVA_HOME=${VEROVIO_SOURCE}/bindings/java
BUILD_DIR=${VEROVIO_JAVA_HOME}/build
LIB_DEST_DIR=${VEROVIO_JAVA_HOME}/lib

# ============================================
# maven
# ============================================
JAVA_GENERATED_SOURCE_DIR=${VEROVIO_JAVA_HOME}/src/main/java/org/rismch/verovio/generated
JAVA_GENERATED_PACKAGE=org.rismch.verovio.generated

# ============================================
# code generation with swig
# ============================================
SWIG_CONFIG_DIR=${VEROVIO_JAVA_HOME}/swig
SWIG_CONFIG_FILE=${SWIG_CONFIG_DIR}/verovio.i
VEROVIO_JNI_WRAPPER=${SWIG_CONFIG_DIR}/verovio_wrap.cxx

# ============================================
# library build definition
# ============================================
CMAKE_CONFIG_DIR=${VEROVIO_JAVA_HOME}/cmake
# ============================================
# just print the variables
if [ "$1" = "variables" ]; then
{
    echo ====== editable paths ======
    echo VEROVIO_SOURCE=${VEROVIO_SOURCE}
    echo VEROVIO_JAVA_HOME=${VEROVIO_JAVA_HOME}
    echo BUILD_DIR=${BUILD_DIR}
    echo CMAKE_CONFIG_DIR=${CMAKE_CONFIG_DIR}
    echo LIB_DEST_DIR=${LIB_DEST_DIR}
    echo SWIG_CONFIG_DIR=${SWIG_CONFIG_DIR}
    echo ====== maven ======
    echo MAVEN=${MAVEN}
    echo JAVA_GENERATED_SOURCE_DIR=${JAVA_GENERATED_SOURCE_DIR}
    echo ====== swig ======
    echo SWIG=${SWIG}
    echo JAVA_GENERATED_PACKAGE=${JAVA_GENERATED_PACKAGE}
    echo SWIG_CONFIG_FILE=${SWIG_CONFIG_FILE}
    echo VEROVIO_JNI_WRAPPER=${}VEROVIO_JNI_WRAPPER}
    echo ====== cmake ======
    echo CMAKE=${CMAKE}
    echo CMAKE_GENERATOR=${CMAKE_GENERATOR}
    if [ "X${SAVEDDIR}" != "$(${PWD})" ]; then
        cd "${SAVEDDIR}" || exit 1;
    fi
    exit 0
}
fi

# ============================================
# pre-build setup
# ============================================
if [ ! -d $BUILD_DIR ]; then ${MKDIR} $BUILD_DIR; fi
if [ ! -d $LIB_DEST_DIR ]; then ${MKDIR} $LIB_DEST_DIR; fi
if [ -f $VEROVIO_JNI_WRAPPER ]; then rm -f $VEROVIO_JNI_WRAPPER; fi
${MAVEN} -f ${VEROVIO_JAVA_HOME} clean
${RM} -f $LIB_DEST_DIR/*
${RM} -f $JAVA_GENERATED_SOURCE_DIR/*.java

# ============================================
# generate the source
# ============================================
cd ${SWIG_CONFIG_DIR} || exit 1
${SWIG} -c++ -java -package ${JAVA_GENERATED_PACKAGE} \
    -outdir ${JAVA_GENERATED_SOURCE_DIR} ${SWIG_CONFIG_FILE}
cd ${VEROVIO_JAVA_HOME} || exit 1

# ============================================
# generate the build definition
# CMake paths set in environment variables
# require forward slashes
# ============================================
${CMAKE} --fresh -DVEROVIO_SOURCE=${VEROVIO_SOURCE} \
    -DVEROVIO_JNI_WRAPPER=${VEROVIO_JNI_WRAPPER} \
    -DLIB_DEST_DIR=${LIB_DEST_DIR} \
    -S$CMAKE_CONFIG_DIR -B${BUILD_DIR} -G"${CMAKE_GENERATOR}"

# ============================================
# build the library
# ============================================
$CMAKE --build $BUILD_DIR

# ============================================
# build and test the toolkit
# ============================================
export VEROVIO_SO_DIR=${LIB_DEST_DIR}
$MAVEN -f ${VEROVIO_JAVA_HOME} clean package test

exit 0