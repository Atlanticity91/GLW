workspace "OpenGL Wrapper"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "GLW"
   location "../"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

   group "Thirdparty"
      include "Build-GLEW.lua"
      include "Build-GLM.lua"
   group ""
   include "Build-GLW.lua"
   