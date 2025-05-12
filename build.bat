@echo off

:: unpack arguments
for %%a in (%*) do set "%%a=1"
if not "%msvc%"=="1" if not "%clang%"=="1" set msvc=1
if not "%release%"=="1" set debug=1
if "%debug%"=="1"   set release=0 && echo [debug mode]
if "%release%"=="1" set debug=0 && echo [release mode]
if "%msvc%"=="1"    set clang=0 && echo [msvc compile]
if "%clang%"=="1"   set msvc=0 && echo [clang compile]

:: compile line definitions
set cl_common=  /I..\src\ /nologo /FC
set cl_debug=   call cl /Od /Ob1 /Zi /DBUILD_DEBUG=1 %cl_common%
set cl_release= call cl /O2 /DBUILD_DEBUG=0 %cl_common%
set cl_link=    /link
set cl_out=     /out:

set clang_common=  -I..\src\ -gcodeview -fdiagnostics-absolute-paths -Wall -Wno-missing-braces -Wno-unused-function -Wno-writable-strings
set clang_debug=   call clang++ -g -O0 -DBUILD_DEBUG=1 %clang_common%
set clang_release= call clang++ -g -O2 -DBUILD_DEBUG=0 %clang_common%
set clang_link=    
set clang_out=     -o

:: choose compile lines
if "%msvc%"=="1" set compile_debug=%cl_debug%
if "%msvc%"=="1" set compile_release=%cl_release%
if "%msvc%"=="1" set compile_link=%cl_link%
if "%msvc%"=="1" set compile_out=%cl_out%

if "%clang%"=="1" set compile_debug=%clang_debug%
if "%clang%"=="1" set compile_release=%clang_release%
if "%clang%"=="1" set compile_link=%clang_link%
if "%clang%"=="1" set compile_out=%clang_out%

if "%debug%"=="1"   set compile=%compile_debug%
if "%release%"=="1" set compile=%compile_release%

:: prep directories
if not exist build mkdir build

:: build
pushd build
%compile% ..\src\grimoire_main.cpp %compile_link% %compile_out%grimoire.exe || exit /b 1
popd
