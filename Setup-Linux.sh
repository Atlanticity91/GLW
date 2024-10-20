#!/bin/bash

pushd ..

echo === GLW Setup ===

GLW/Build/Premake/Linux/premake5 --cc=clang --file=GLW/Build/Build.lua gmake2

popd
