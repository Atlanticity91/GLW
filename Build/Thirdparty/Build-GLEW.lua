project "GLEW"
	kind "StaticLib"
	language "C"
	staticruntime "off"
	location "%{OutputDirs.Solution}"

	--- OUTPUT
	targetdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	debugdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	objdir "%{OutputDirs.BinInt}/%{prj.name}-%{cfg.buildcfg}"

	--- GLOBAL INCLUDES
	includedirs "%{IncludeDirs.Glew}include/"

	externalincludedirs "%{IncludeDirs.Glew}include/"

	--- GLOBAL DEFINES
	defines { "GLEW_STATIC" }

	--- GLOBAL SOURCE FILES
	files { 
		"%{IncludeDirs.Glew}include/GL/**.h", 
		"%{IncludeDirs.Glew}src/glew.c" 
	}

	--- WINDOWS
	filter "system:windows"
		systemversion "latest"
		cdialect "C17"
		flags { "MultiProcessorCompile" }

		--- WINDOWS SPECIFIC DEFINES
		defines { 
			"WINDOWS", 
			"WIN32_LEAN_AND_MEAN", 
			"_LIB" 
		}

		--- WINDOWS SPECIFIC SOURCE FILES
		files "%{IncludeDirs.Glew}/build/glew.rc" 

	--- CONFIGURATION
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

		--- DEFINES
		defines { "DEBUG" }

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		symbols "On"

		--- DEFINES 
		defines { "RELEASE" }

	filter "configurations:Dist"
		runtime "Release"
		optimize "On"
		symbols "Off"

		--- DEFINES 
		defines { "DIST" }
