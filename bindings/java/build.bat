rem @echo off
setlocal

rem ============================================
rem values to set for environment
rem shoudn't need to change anything else
rem NOTE: JAVA_HOME must be set in environment
rem ============================================
set VEROVIO_HOME="D:\opt\verovio"
set MAVEN="%MAVEN_HOME%\bin\mvn"
set SWIG_EXE="D:\opt\swig\bin\swig.exe"
set VCVARS_CMD="e:\bin\vcvars64_2022"
set CMAKE_EXE="C:\Program Files\CMake\bin\cmake.exe"

rrem ============================================
rem root paths
rem ============================================
set VEROVIO_JAVA_HOME=%VEROVIO_HOME%\bindings\java
set BUILD_DIR=%VEROVIO_JAVA_HOME%\build
set LIB_DEST_DIR=%VEROVIO_JAVA_HOME%\lib

rem ============================================
rem maven
rem ============================================
set JAVA_GENERATED_SOURCE_DIR=%VEROVIO_JAVA_HOME%\src\main\java\org\rismch\verovio\generated
set JAVA_GENERATED_PACKAGE=org.rismch.verovio.generated

rem ============================================
rem code generation with swig
rem ============================================
set SWIG_CONFIG_DIR=%VEROVIO_JAVA_HOME%\swig
set SWIG_CONFIG_FILE=%SWIG_CONFIG_DIR%\verovio.i
set VEROVIO_JNI_WRAPPER=%SWIG_CONFIG_DIR%\verovio_wrap.cxx

rem ============================================
rem library build definition
rem ============================================
set CMAKE_CONFIG_DIR=%VEROVIO_JAVA_HOME%\cmake
set CMAKE_GENERATOR="NMake Makefiles"

rem ============================================
rem just print the variables
if "%1"=="variables" goto variables
rem ============================================

rem ============================================
rem pre-build setup
rem ============================================
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
if not exist %LIB_DEST_DIR% mkdir %LIB_DEST_DIR%
if exist %VEROVIO_JNI_WRAPPER% del %VEROVIO_JNI_WRAPPER%
call %MAVEN% clean
del /Q %LIB_DEST_DIR%\*.*
del /Q %JAVA_GENERATED_SOURCE_DIR%\*.java

rem ============================================
rem generate the source
rem ============================================
pushd %SWIG_CONFIG_DIR%
%SWIG_EXE% -c++ -java -package %JAVA_GENERATED_PACKAGE% ^
    -outdir %JAVA_GENERATED_SOURCE_DIR% %SWIG_CONFIG_FILE%
popd

rem ============================================
rem generate the build definition
rem CMake paths set in environment variables
rem require forward slashes
rem ============================================
call %VCVARS_CMD%
set NMAKE_EXE=nmake
%CMAKE_EXE% --fresh -DVEROVIO_HOME=%VEROVIO_HOME:\=//% ^
    -DVEROVIO_JNI_WRAPPER=%VEROVIO_JNI_WRAPPER:\=//% ^
    -DLIB_DEST_DIR=%LIB_DEST_DIR:\=//% ^
    -S%CMAKE_CONFIG_DIR% -B%BUILD_DIR:\=//% -G%CMAKE_GENERATOR%

rem ============================================
rem build the library
rem ============================================
%CMAKE_EXE% --build %BUILD_DIR:\=//%

rem ============================================
rem build and test the toolkit
rem ============================================
call %MAVEN% clean test
goto end

:variables
@echo ====== editable paths ======
@echo VEROVIO_HOME=%VEROVIO_HOME%
@echo VEROVIO_JAVA_HOME=%VEROVIO_JAVA_HOME%
@echo BUILD_DIR=%BUILD_DIR%
@echo CMAKE_CONFIG_DIR=%CMAKE_CONFIG_DIR%
@echo LIB_DEST_DIR=%LIB_DEST_DIR%
@echo SWIG_CONFIG_DIR=%SWIG_CONFIG_DIR%
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
:end
endlocal