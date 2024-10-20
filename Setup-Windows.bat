@echo off

set scriptpath=%~dp0

pushd ..
cls

echo === GLW Setup ===

IF EXIST GLW\GLW.sln del /f GLW\GLW.sln
IF EXIST GLW\bin rmdir /q /s GLW\bin
IF EXIST GLW\bin-int rmdir /q /s GLW\bin-int

GLW\Build\Premake\Windows\premake5.exe --file=GLW\Build\Build.lua vs2022

popd

pause
