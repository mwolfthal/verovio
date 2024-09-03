cmake_minimum_required(VERSION 3.26)
set(PROJECT_NAME VerovioJni)
# set the project name and version
project(${PROJECT_NAME} VERSION 1.0)

# specify the C++ standard
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)
MESSAGE (VEROVIO_SOURCE = ${VEROVIO_SOURCE})
MESSAGE (VEROVIO_JNI_WRAPPER = ${VEROVIO_JNI_WRAPPER})
MESSAGE (LIB_DEST_DIR = ${LIB_DEST_DIR})
if (WIN32)
	set (VEROVIO_SHARED_LIBRARY ${PROJECT_NAME}.dll)
	set (JNI_INCLUDE_DIR $ENV{JAVA_HOME}/include/win32)
else()
	set (VEROVIO_SHARED_LIBRARY lib${PROJECT_NAME}.so)
	set (JNI_INCLUDE_DIR $ENV{JAVA_HOME}/include/linux)
endif()

set (VEROVIO_BINDINGS_DIR ${VEROVIO_SOURCE}/bindings)
set (GET_GIT_COMMIT get_git_commit)
if (NOT WIN32)
    MESSAGE (generating ${GET_GIT_COMMIT}.h)
    execute_process(
    COMMAND ${VEROVIO_SOURCE}/tools/${GET_GIT_COMMIT}.sh
    WORKING_DIRECTORY ${VEROVIO_BINDINGS_DIR}
    OUTPUT_VARIABLE GIT_COMMIT)
endif()

#if (NOT CMAKE_BUILD_TYPE)
#	set (CMAKE_BUILD_TYPE Debug)
#endif()
set (CMAKE_VERBOSE_MAKEFILE 1)

file(GLOB verovio_SRC "${VEROVIO_SOURCE}/src/*.cpp")
file(GLOB libmei_DIST_SRC "${VEROVIO_SOURCE}/libmei/dist/*.cpp")
file(GLOB libmei_ADDONS_SRC "${VEROVIO_SOURCE}/libmei/addons/*.cpp") 

set (all_SRC
	${verovio_SRC}
	${libmei_DIST_SRC}
	${libmei_ADDONS_SRC}
	${VEROVIO_SOURCE}/src/pugi/pugixml.cpp
	${VEROVIO_SOURCE}/src/midi/Binasc.cpp
	${VEROVIO_SOURCE}/src/midi/MidiEvent.cpp
	${VEROVIO_SOURCE}/src/midi/MidiEventList.cpp
	${VEROVIO_SOURCE}/src/midi/MidiFile.cpp
	${VEROVIO_SOURCE}/src/midi/MidiMessage.cpp
	${VEROVIO_SOURCE}/src/hum/humlib.cpp
	${VEROVIO_SOURCE}/src/json/jsonxx.cc
	${VEROVIO_SOURCE}/src/crc/crc.cpp
	${VEROVIO_JNI_WRAPPER}
)

include_directories (
	$ENV{JAVA_HOME}/include
	${JNI_INCLUDE_DIR}
	${VEROVIO_SOURCE}/include
	${VEROVIO_SOURCE}/include/win32
	${VEROVIO_SOURCE}/include/crc
	${VEROVIO_SOURCE}/include/hum
	${VEROVIO_SOURCE}/include/json
	${VEROVIO_SOURCE}/include/midi
	${VEROVIO_SOURCE}/include/pugi
	${VEROVIO_SOURCE}/include/vrv
	${VEROVIO_SOURCE}/include/zip
	${VEROVIO_SOURCE}/libmei/addons
	${VEROVIO_SOURCE}/libmei/dist
)	


add_compile_definitions(-DNO_ABC_SUPPORT)
add_compile_definitions(-DNO_DARMS_SUPPORT)
#add_compile_definitions(-DNO_HUMDRUM_SUPPORT)
#add_compile_definitions(-DNO_PAE_SUPPORT)

if (MSVC)
	if (CMAKE_BUILD_TYPE EQUAL Debug)
		set (PDB_NAME VerovioJni)
		set (PDB_OUTPUT_DIRECTORY .)
	endif()
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
	add_compile_options(/DEBUG)
	add_compile_options(/W2) 				#warning level
	add_compile_options(/std:c++20)
	add_compile_options(/LDd)				#debug DLL
	add_compile_options(/wd4244)			#suppress warning about possible loss of precision
	add_compile_options(/bigobj)            #too many sections in object file
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

install(TARGETS VerovioJni
        # shared libraries
        LIBRARY DESTINATION lib
)