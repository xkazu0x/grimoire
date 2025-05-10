@echo off

set compile= call cl /Od /Ob1 /Zi /DBUILD_DEBUG=1 /I..\src\ /nologo /FC
set compile_link= /link
set compile_out= /out:

set libs= user32.lib

if not exist build mkdir build

pushd build
%compile% ..\src\grimoire_main.cpp %libs% %compile_link% %compile_out%grimoire.exe
popd
