@echo off

if not exist build\grimoire.exe call build

pushd build
call grimoire.exe
popd
