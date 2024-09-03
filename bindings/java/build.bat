@echo off
setlocal

rem ===============================================
rem system tools
rem ===============================================
@set WHERE=where.exe
@set ECHO=echo
@set PUSHD=pushd
@set POPD=popd
@set ERRORLEVEL=0

rem ===============================================
rem values to be defined for the local environment
rem ===============================================

rem ===============================================
rem the source repository
rem ===============================================
@set VEROVIO_SOURCE=D:\GitHub\mwolfthal\verovio
@set VEROVIO_SOURCE_ERROR=1

if "X%VEROVIO_SOURCE%" == "X" (
    @echo !! VEROVIO_SOURCE is not set !!
    @set ERRORLEVEL=%VEROVIO_SOURCE_ERROR%
    goto exit)
@echo -- VEROVIO_SOURCE is %VEROVIO_SOURCE% --
@set VEROVIO_JAVA_HOME=%VEROVIO_SOURCE%\bindings\java

rem ===============================================
rem java
rem if not in the environment
rem @set JAVA_HOME=
rem ===============================================
@set JAVA=%JAVA_HOME%\bin\java.exe

rem ===============================================
rem maven
rem if not in the environment
rem @set MAVEN_HOME=
rem or set MAVEN to %VEROVIO_JAVA_HOME%\mvnw.cmd
rem ===============================================
@set MAVEN=%MAVEN_HOME%\bin\mvn.cmd

rem ===============================================
rem swig code generator
rem ===============================================
@set SWIG_EXE=D:\opt\swig\bin\swig.exe

rem ===============================================
rem CMake generator - nmake or Visual Studio
rem VCVARS batch file sets the environment for nmake
rem The one included here is for Visual Studio 2022
rem ===============================================
@set VCVARS_CMD=%VEROVIO_JAVA_HOME%\vcvars64_2022.bat
@set CMAKE_EXE="C:\Program Files\CMake\bin\cmake.exe"
@set CMAKE_GENERATOR="NMake Makefiles"

rem ===============================================
rem shouldn't need to change anything below
rem ===============================================

rem ===============================================
rem paths based on the above
rem ===============================================
@set BUILD_DIR=%VEROVIO_JAVA_HOME%\build
@set LIB_DEST_DIR=%VEROVIO_JAVA_HOME%\lib
@set JAVA_GENERATED_SOURCE_DIR=%VEROVIO_JAVA_HOME%\src\main\java\org\rismch\verovio\generated
@set JAVA_GENERATED_PACKAGE=org.rismch.verovio.generated
@set CMAKE_CONFIG_DIR=%VEROVIO_JAVA_HOME%\cmake
@set SWIG_CONFIG_DIR=%VEROVIO_JAVA_HOME%\swig
@set SWIG_CONFIG_FILE=%SWIG_CONFIG_DIR%\verovio.i
@set VEROVIO_JNI_WRAPPER=%SWIG_CONFIG_DIR%\verovio_wrap.cxx

rem ===============================================
rem just print the variables
if "%1"=="variables" goto variables
rem ===============================================

rem ===============================================
rem pre-build setup
rem ===============================================
if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
    ) else (
    del /q %BUILD_DIR%\*
    for /d %%x in (%BUILD_DIR%\*) do @rd /s /q "%%x"
    )

if not exist %LIB_DEST_DIR% mkdir %LIB_DEST_DIR%
if exist %VEROVIO_JNI_WRAPPER% del %VEROVIO_JNI_WRAPPER%
call %MAVEN% -f %VEROVIO_JAVA_HOME% clean
del /Q %LIB_DEST_DIR%\*.*
del /Q %JAVA_GENERATED_SOURCE_DIR%\*.java
call %VCVARS_CMD%

rem ===============================================
rem generate the source
rem ===============================================
@echo -- Running swig ---
@%PUSHD% %SWIG_CONFIG_DIR%
@%SWIG_EXE% -c++ -java -package %JAVA_GENERATED_PACKAGE% ^
    -outdir %JAVA_GENERATED_SOURCE_DIR% %SWIG_CONFIG_FILE%
@%POPD%

rem ===============================================
rem Generate the build tools.
rem CMake paths require forward slashes.
rem ===============================================
@echo -- Generating build configuration ---
%CMAKE_EXE% --fresh -DVEROVIO_SOURCE=%VEROVIO_SOURCE:\=//% ^
    -DVEROVIO_JNI_WRAPPER=%VEROVIO_JNI_WRAPPER:\=//% ^
    -DLIB_DEST_DIR=%LIB_DEST_DIR:\=//% ^
    -S%CMAKE_CONFIG_DIR% -B%BUILD_DIR:\=//% -G%CMAKE_GENERATOR%

rem ===============================================
rem build the library
rem ===============================================
@echo -- running build ---
%CMAKE_EXE% --build %BUILD_DIR:\=//%

rem ===============================================
rem build and test the java toolkit facade
rem ===============================================
@echo -- Build and test jar ---
call %MAVEN% -f %VEROVIO_JAVA_HOME% clean package test
goto exit

:variables
@echo ====== paths ======
@echo VEROVIO_SOURCE=%VEROVIO_SOURCE%
@echo VEROVIO_JAVA_HOME=%VEROVIO_JAVA_HOME%
@echo BUILD_DIR=%BUILD_DIR%
@echo CMAKE_CONFIG_DIR=%CMAKE_CONFIG_DIR%
@echo LIB_DEST_DIR=%LIB_DEST_DIR%
@echo SWIG_CONFIG_DIR=%SWIG_CONFIG_DIR%
@echo ====== jave ======
@echo JAVA=%JAVA%
@echo ====== maven ======
@echo MAVEN=%MAVEN%
@echo JAVA_GENERATED_SOURCE_DIR=%JAVA_GENERATED_SOURCE_DIR%
@echo ====== swig ======
@echo SWIG_EXE=%SWIG_EXE%
@echo JAVA_GENERATED_PACKAGE=%JAVA_GENERATED_PACKAGE%
@echo SWIG_CONFIG_FILE=%SWIG_CONFIG_FILE%
@echo VEROVIO_JNI_WRAPPER=%VEROVIO_JNI_WRAPPER%
@echo ====== cmake ======
@echo VCVARS_CMD=%VCVARS_CMD%
@echo CMAKE_EXE=%CMAKE_EXE%
@echo CMAKE_GENERATOR=%CMAKE_GENERATOR%
:exit
echo Exiting with ERRORLEVEL %ERRORLEVEL%
exit /b %ERRORLEVEL%
endlocal

