include "Premake/CSExtensions.lua"
include "Premake/VSExtensions.lua"
include "Build-Dependencies.lua"

workspace "OpenGL Wrapper"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "GLW"
   location "../"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

   group "Thirdparty"
      include "Thirdparty/Build-GLEW.lua"
      include "Thirdparty/Build-GLM.lua"
   group ""
   
   include "Build-GLW.lua"
   