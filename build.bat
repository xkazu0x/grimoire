@echo off

if not exist build mkdir build

pushd build
cl ..\src\grimoire_main.cpp /link /out:grimoire.exe
popd
