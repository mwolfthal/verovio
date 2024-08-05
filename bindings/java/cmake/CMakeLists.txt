cmake_minimum_required(VERSION 3.26)
set(PROJECT_NAME VerovioJni)
# set the project name and version
project(${PROJECT_NAME} VERSION 1.0)

# specify the C++ standard
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)
MESSAGE (VEROVIO_HOME = ${VEROVIO_HOME})
MESSAGE (VEROVIO_JNI_WRAPPER = ${VEROVIO_JNI_WRAPPER})
MESSAGE (LIB_DEST_DIR = ${LIB_DEST_DIR})

if (WIN32)
	set (VEROVIO_SHARED_LIBRARY ${PROJECT_NAME}.dll)
	set (JNI_INCLUDE_DIR $ENV{JAVA_HOME}/include/win32)
else()
	set (VEROVIO_SHARED_LIBRARY lib${PROJECT_NAME}.so)
	set (JNI_INCLUDE_DIR $ENV{JAVA_HOME}/include/linux)
endif()

 set (VEROVIO_BINDINGS_DIR ${VEROVIO_HOME}/bindings)

if (NOT WIN32)
     execute_process(
        COMMAND ${VEROVIO_HOME}/tools/get_git_commit.sh
        WORKING_DIRECTORY ${VEROVIO_BINDINGS_DIR}
        OUTPUT_VARIABLE GIT_COMMIT)
endif()

if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE Debug)
endif()
set (CMAKE_VERBOSE_MAKEFILE 1)
set (CMAKE_BUILD_TYPE debug)

file(GLOB verovio_SRC "${VEROVIO_HOME}/src/*.cpp")
file(GLOB libmei_DIST_SRC "${VEROVIO_HOME}/libmei/dist/*.cpp")
file(GLOB libmei_ADDONS_SRC "${VEROVIO_HOME}/libmei/addons/*.cpp") 

set (all_SRC
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
	${VEROVIO_JNI_WRAPPER}
)

include_directories (
	$ENV{JAVA_HOME}/include
	${JNI_INCLUDE_DIR}
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
	#add_compile_definitions(-DNO_PAE_SUPPORT) 	#regex different under Windows
	add_compile_definitions(-DNO_HUMDRUM_SUPPORT)
	add_compile_options(/DEBUG)
	add_compile_options(/W2) 				#warning level
	add_compile_options(/std:c++20)
	add_compile_options(/LDd)				#debug DLL
	add_compile_options(/wd4244)			#suppress warning about possible loss of precision
endif()

add_library(${PROJECT_NAME} SHARED ${all_SRC})
option (BUILD_AS_LIBRARY "Build the application as a shared library" ON)
message (STATUS "**** Building verovio_jni shared library ****")

if (MSVC)
    set (LIBS
        ${VEROVIO_SHARED_LIBRARY}
        ${PROJECT_NAME}.pdb
        ${PROJECT_NAME}.lib
    )
else()
    set (LIBS ${VEROVIO_SHARED_LIBRARY}
    )
endif()

# copy the library files
foreach(file_i ${LIBS})
    add_custom_command(
	    TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E remove -f ${LIB_DEST_DIR}/${file_i}
	    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${file_i} ${LIB_DEST_DIR}
	    COMMENT "Copying library files"
    )
endforeach(file_i)
