cmake_minimum_required(VERSION 3.26)

# set the project name and version
project(VerovioJNI VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (WIN32)
	set (SWIG d:/opt/swig/bin/swig.exe)
endif()

set(VEROVIO_HOME D:/opt/verovio/maw/verovio)
set(JAVA_BINDING_HOME ${VEROVIO_HOME}/bindings/java)

set(VEROVIO_JNI_WRAPPER verovio_wrap.cxx)

add_custom_command(OUTPUT ${JAVA_BINDING_HOME}/swig/${VEROVIO_JNI_WRAPPER}
#make certain target directory exists
	COMMAND $ENV{MAVEN_HOME}/bin/mvn -Dmaven.test.skip=true -f ${JAVA_BINDING_HOME} clean package
	COMMAND ${SWIG} -c++ -java -package org.rismch.verovio -outdir ../src/main/java/org/rismch/verovio verovio.i
	DEPENDS ${JAVA_BINDING_HOME}/swig/verovio.i
	WORKING_DIRECTORY ${JAVA_BINDING_HOME}/swig
)


if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE Debug)
endif()
set (CMAKE_VERBOSE_MAKEFILE 1)
set (CMAKE_BUILD_TYPE debug)

file(GLOB verovio_SRC "${VEROVIO_HOME}/src/*.cpp")
file(GLOB libmei_DIST_SRC "${VEROVIO_HOME}/libmei/dist/*.cpp")
file(GLOB libmei_ADDONS_SRC "${VEROVIO_HOME}/libmei/addons/*.cpp") 

set(all_SRC
	${verovio_SRC}
	${libmei_DIST_SRC}
	${libmei_ADDONS_SRC}
	${VEROVIO_HOME}/src/pugi/pugixml.cpp
	${VEROVIO_HOME}/src/midi/Binasc.cpp
	${VEROVIO_HOME}/src/midi/MidiEvent.cpp
	${VEROVIO_HOME}/src/midi/MidiEventList.cpp
	${VEROVIO_HOME}/src/midi/MidiFile.cpp
	${VEROVIO_HOME}/src/midi/MidiMessage.cpp
	${VEROVIO_HOME}/src/hum/humlib.cpp
	${VEROVIO_HOME}/src/json/jsonxx.cc
	${VEROVIO_HOME}/src/crc/crc.cpp
	${JAVA_BINDING_HOME}/swig/${VEROVIO_JNI_WRAPPER}
)


#set (JAVA_TARGET_LIB_PATH ../target/classes/META-INF/lib)
#add_custom_command(
#	TARGET verovio_jni.dll POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E copy
#			${CMAKE_CURRENT_BINARY_DIR}/verovio_jni.dll
#			${JAVA_TARGET_LIB_PATH}
#)

include_directories (
	$ENV{JAVA_HOME}/include
	$ENV{JAVA_HOME}/include/win32
	${VEROVIO_HOME}/include
	${VEROVIO_HOME}/include/win32
	${VEROVIO_HOME}/include/crc
	${VEROVIO_HOME}/include/hum
	${VEROVIO_HOME}/include/json
	${VEROVIO_HOME}/include/midi
	${VEROVIO_HOME}/include/pugi
	${VEROVIO_HOME}/include/vrv
	${VEROVIO_HOME}/include/zip
	${VEROVIO_HOME}/libmei/addons
	${VEROVIO_HOME}/libmei/dist
)	



if (MSVC)
	if (CMAKE_BUILD_TYPE EQUAL Debug)
		set (PDB_NAME VerovioJni)
		set (PDB_OUTPUT_DIRECTORY .)
	endif()
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
	add_compile_definitions(-DNO_PAE_SUPPORT) 	#regex different under Windoes
	add_compile_definitions(-DNO_HUMDRUM_SUPPORT)
	add_compile_options(/DEBUG)
	add_compile_options(/W2) 				#warning level
	add_compile_options(/std:c++20)
	add_compile_options(/LDd)				#debug DLL
	add_compile_options(/wd4244)			#suppress warning about possible loss of precision
endif()

add_library(VerovioJni SHARED ${all_SRC})
option (BUILD_AS_LIBRARY "Build the application as a shared library" ON)
message (STATUS "**** Building verovio_jni shared library ****")

add_custom_command(
	TARGET VerovioJni
	POST_BUILD
	COMMAND $ENV{MAVEN_HOME}/bin/mvn -f ${JAVA_BINDING_HOME} clean package
	COMMENT "Running Maven"
)
