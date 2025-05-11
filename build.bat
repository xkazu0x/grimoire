@echo off

:: unpack arguments
for %%a in (%*) do set "%%a=1"
if not "%release%"=="1" set debug=1
if "%debug%"=="1"   set release=0 && echo [debug mode]
if "%release%"=="1" set debug=0 && echo [release mode]

:: compile line definitions
set cl_common=  /I..\src\ /nologo /FC
set cl_debug=   call cl /Od /Ob1 /Zi /DBUILD_DEBUG=1 %cl_common%
set cl_release= call cl /O2 /DBUILD_DEBUG=0 %cl_common%
set cl_link=    /link
set cl_out=     /out:

:: choose compile lines
if "%debug%"=="1"   set compile=%cl_debug%
if "%release%"=="1" set compile=%cl_release%

:: prep directories
if not exist build mkdir build

:: build
pushd build
%compile% ..\src\grimoire_main.cpp %libs% %cl_link% %cl_out%grimoire.exe || exit /b 1
popd
