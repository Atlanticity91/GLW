--- TOOL INCLUDES
include "Premake/CSExtensions.lua"
include "Premake/VSExtensions.lua"
include "Build-Dependencies.lua"

--- PROJECT CONFIGURATION
workspace "Micro Solution"
   architecture "x64"
   startproject "GLW"
   location "../"
   configurations { 
      "Debug", 
      "Release",
      "Dist" 
   }

   --- WINDOWS
   filter "system:windows"
      --- WORKSPACE-WIDE BUILD OPTIONS FOR MSVC
      buildoptions { 
         "/EHsc", 
         "/Zc:preprocessor", 
         "/Zc:__cplusplus" 
      }

   --- THIRDPARTY PROJECTS
   group "Thirdparty"
      include "Thirdparty/Build-GLEW.lua"
      include "Thirdparty/Build-GLM.lua"
   group ""

   --- MAIN PROJECT
   include "Build-GLW.lua"
   