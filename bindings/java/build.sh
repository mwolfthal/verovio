#! /bin/bash

# ============================================
# system tools
# ============================================
WHICH=/usr/bin/which
ECHO=/usr/bin/echo
PWD=/usr/bin/pwd
MKDIR=/bin/mkdir
RM=/bin/rm

VEROVIO_ERROR=1
JAVA_ERROR=2
MAVEN_ERROR=3
GCC_ERROR=4
# ============================================
# values to be defined for the environment
# ============================================

# ============================================
# set the source repository if not in the
# environment
# VEROVIO_SOURCE=
# ============================================
if [ "X${VEROVIO_SOURCE}" == "X" ]; then
    ${ECHO} "!! VEROVIO_SOURCE is not set !!";
    exit ${VEROVIO_ERROR};
else
    ${ECHO} -- VEROVIO_SOURCE is "${VEROVIO_SOURCE}" --
fi
VEROVIO_JAVA_HOME=${VEROVIO_SOURCE}/bindings/java

# ============================================
# java
# JAVA_HOME=...
# PATH=${JAVA_HOME}/bin:${PATH}
# ============================================
JAVA=$(${WHICH} java 2>/dev/null)
if [ "X{JAVA}" == "X" ]; then
    ${ECHO} "!! java not found !!";
    exit ${JAVA_ERROR};
else
    ${ECHO} -- JAVA is "${JAVA}"
fi

# ============================================
# maven
# If maven is not installed then comment
# the below and set MAVEN to the wrapper
# $VEROVIO_JAVA_HOME/mvnw
# ============================================
MAVEN_CMD=mvn
MAVEN=$(${WHICH} ${MAVEN_CMD} 2>/dev/null)
if [ "X${MAVEN}" == "X" ]; then
    ${ECHO} "!! Maven (${MAVEN_CMD}) not found !!";
    exit ${MAVEN_ERROR};
else
    ${ECHO} -- MAVEN is "${MAVEN}" --
fi

# ============================================
# swig code generator
# ============================================
SWIG=/opt/swig/bin/swig

# ============================================
# cmake
# ============================================
CMAKE=/usr/bin/cmake
CMAKE_GENERATOR="Unix Makefiles"

# ============================================
# check gcc
# ============================================
GCC_CMD=gcc
GCC=$(${WHICH} ${GCC_CMD} 2>/dev/null)
if [ "X${GCC}" == "X" ]; then
    ${ECHO} "!! gcc (${GCC_CMD}) not found !!";
    exit ${GCC_ERROR};
else
    ${ECHO} -- GCC is "${GCC}" --
fi

# ============================================
# shouldn't need to change anything below
# ============================================

# ============================================
# paths based on the above
# ============================================
BUILD_DIR=${VEROVIO_JAVA_HOME}/build
LIB_DEST_DIR=${VEROVIO_JAVA_HOME}/lib
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
    ${ECHO} ====== paths ======
    ${ECHO} VEROVIO_SOURCE="${VEROVIO_SOURCE}"
    ${ECHO} VEROVIO_JAVA_HOME="${VEROVIO_JAVA_HOME}"
    ${ECHO} BUILD_DIR="${BUILD_DIR}"
    ${ECHO} LIB_DEST_DIR="${LIB_DEST_DIR}"
    ${ECHO} SWIG_CONFIG_DIR="${SWIG_CONFIG_DIR}"
    ${ECHO} ====== java ======
    ${ECHO} JAVA="${JAVA}"
    ${ECHO} ====== maven ======
    ${ECHO} MAVEN="${MAVEN}"
    ${ECHO} JAVA_GENERATED_SOURCE_DIR="${JAVA_GENERATED_SOURCE_DIR}"
    ${ECHO} ====== swig ======
    ${ECHO} SWIG=${SWIG}
    ${ECHO} JAVA_GENERATED_PACKAGE=${JAVA_GENERATED_PACKAGE}
    ${ECHO} SWIG_CONFIG_FILE="${SWIG_CONFIG_FILE}"
    ${ECHO} VEROVIO_JNI_WRAPPER="${VEROVIO_JNI_WRAPPER}"
    ${ECHO} ====== cmake ======
    ${ECHO} CMAKE=${CMAKE}
    ${ECHO} CMAKE_GENERATOR="${CMAKE_GENERATOR}"
    if [ "X${SAVEDDIR}" != "$(${PWD})" ]; then
        cd "${SAVEDDIR}" || exit 1;
    fi
    exit 0
}
fi

# ============================================
# pre-build setup
# ============================================
if [ ! -d ${BUILD_DIR} ]; then ${MKDIR} ${BUILD_DIR}; fi
if [ ! -d ${LIB_DEST_DIR} ]; then ${MKDIR} ${LIB_DEST_DIR}; fi
if [ -f ${VEROVIO_JNI_WRAPPER} ]; then ${RM} -f $VEROVIO_JNI_WRAPPER; fi
${MAVEN} -f ${VEROVIO_JAVA_HOME} clean
${RM} -f ${LIB_DEST_DIR}/*
${RM} -f ${JAVA_GENERATED_SOURCE_DIR}/*.java

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
${CMAKE} --fresh -DVEROVIO_SOURCE="${VEROVIO_SOURCE}" \
    -DVEROVIO_JNI_WRAPPER="${VEROVIO_JNI_WRAPPER}" \
    -DLIB_DEST_DIR=${LIB_DEST_DIR} \
    -S"$CMAKE_CONFIG_DIR" -B"${BUILD_DIR}" -G"${CMAKE_GENERATOR}"

# ============================================
# build the library
# ============================================
${CMAKE} --build "${BUILD_DIR}"

# ============================================
# build and test the toolkit
# ============================================
${MAVEN} -f "${VEROVIO_JAVA_HOME}" clean package test

exit 0