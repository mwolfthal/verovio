@echo off
setlocal

rem ============================================
rem values to set for environment
rem shoudn't need to change anything else
rem ============================================
@set VEROVIO_HOME=D:\opt\verovio
@set SWIG_EXE=D:\opt\swig\bin\swig.exe
@set VCVARS_CMD=e:\bin\vcvars64_2022
@set CMAKE_EXE="C:\Program Files\CMake\bin\cmake.exe"

rem ============================================
rem system tools
rem ============================================
@set WHERE=where.exe
@set ECHO=echo
@set PUSHD=pushd
@set POPD=popd

rem ============================================
rem root paths
rem ============================================
@set VEROVIO_JAVA_HOME=%VEROVIO_HOME%\bindings\java
@set BUILD_DIR=%VEROVIO_JAVA_HOME%\build
@set LIB_DEST_DIR=%VEROVIO_JAVA_HOME%\lib

rem ============================================
rem find mvn or use mvnw
rem ============================================
@set MAVEN=mvn.cmd
@%WHERE% /q %MAVEN%
IF ERRORLEVEL 1 (
    @echo %MAVEN% is not in the PATH, exiting.
    goto exit)
%ECHO% Found Maven as %MAVEN%.

rem ============================================
rem java
rem ============================================
@set JAVA=java.exe
@%WHERE% /q %JAVA%
IF ERRORLEVEL 1 (
    %ECHO% %JAVA% is not in the PATH, exiting.
    goto exit)
%ECHO% Found java as %JAVA%.
)
@set JAVA_GENERATED_SOURCE_DIR=%VEROVIO_JAVA_HOME%\src\main\java\org\rismch\verovio\generated
@set JAVA_GENERATED_PACKAGE=org.rismch.verovio.generated

rem ============================================
rem code generation with swig
rem ============================================
@set SWIG_CONFIG_DIR=%VEROVIO_JAVA_HOME%\swig
@set SWIG_CONFIG_FILE=%SWIG_CONFIG_DIR%\verovio.i
@set VEROVIO_JNI_WRAPPER=%SWIG_CONFIG_DIR%\verovio_wrap.cxx

rem ============================================
rem library build definition
rem ============================================
@set CMAKE_CONFIG_DIR=%VEROVIO_JAVA_HOME%\cmake
@set CMAKE_GENERATOR="NMake Makefiles"

rem ============================================
rem just print the variables
if "%1"=="variables" goto variables
rem ============================================

rem ============================================
rem pre-build setup
rem ============================================
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

rem ============================================
rem generate the source
rem ============================================
%PUSHD% %SWIG_CONFIG_DIR%
%SWIG_EXE% -c++ -java -package %JAVA_GENERATED_PACKAGE% ^
    -outdir %JAVA_GENERATED_SOURCE_DIR% %SWIG_CONFIG_FILE%
%POPD%

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
set VEROVIO_SO_DIR=%LIB_DEST_DIR%
call %MAVEN% -f %VEROVIO_JAVA_HOME% clean package test
goto exit

:variables
@%ECHO% ====== editable paths ======
@%ECHO% VEROVIO_HOME=%VEROVIO_HOME%
@%ECHO% VEROVIO_JAVA_HOME=%VEROVIO_JAVA_HOME%
@%ECHO% BUILD_DIR=%BUILD_DIR%
@%ECHO% CMAKE_CONFIG_DIR=%CMAKE_CONFIG_DIR%
@%ECHO% LIB_DEST_DIR=%LIB_DEST_DIR%
@%ECHO% SWIG_CONFIG_DIR=%SWIG_CONFIG_DIR%
@%ECHO% ====== maven ======
@%ECHO% MAVEN=%MAVEN%
@%ECHO% JAVA_GENERATED_SOURCE_DIR=%JAVA_GENERATED_SOURCE_DIR%
@%ECHO% ====== swig ======
@%ECHO% SWIG_EXE=%SWIG_EXE%
@%ECHO% JAVA_GENERATED_PACKAGE=%JAVA_GENERATED_PACKAGE%
@%ECHO% SWIG_CONFIG_FILE=%SWIG_CONFIG_FILE%
@%ECHO% VEROVIO_JNI_WRAPPER=%VEROVIO_JNI_WRAPPER%
@%ECHO% ====== cmake ======
@%ECHO% VCVARS_CMD=%VCVARS_CMD%
@%ECHO% CMAKE_EXE=%CMAKE_EXE%
@%ECHO% CMAKE_GENERATOR=%CMAKE_GENERATOR%
:exit
endlocal