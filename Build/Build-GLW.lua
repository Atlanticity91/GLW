project "GLW"
	kind "StaticLib"
	language "C++"
	staticruntime "off"
	location "%{OutputDirs.Solution}"

	--- OUTPUT
	targetdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	debugdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	objdir "%{OutputDirs.BinInt}/%{prj.name}-%{cfg.buildcfg}"

	--- GLOBAL INCLUDES
	includedirs {
		"%{IncludeDirs.Glw}GLW/",
		"%{IncludeDirs.Glm}",
		"%{IncludeDirs.Glew}include/"
	}

	externalincludedirs { 
		"%{IncludeDirs.Glw}GLW/",
		"%{IncludeDirs.Glm}",
		"%{IncludeDirs.Glew}include/"
	}

	--- PRECOMPILED HEADER
	pchheader "__glw_pch.h"

	--- GLOBAL SOURCE FILES
	files { 
		"%{IncludeDirs.Glw}GLW/**.h", 
		"%{IncludeDirs.Glw}GLW/**.cpp" 
	}

	--- GLOBAL LINK
	links { "GLEW" }

	--- LINUX
	filter "system:linux"
		systemversion "latest"

		--- WINDOWS SPECIFIC DEFINES
		defines { "LINUX" }

	--- WINDOWS
	filter "system:windows"
		systemversion "latest"
		cppdialect "C++20"
		flags { "MultiProcessorCompile" }

		--- WINDOWS SPECIFIC DEFINES
		defines { 
			"WINDOWS",
			"_CRT_SECURE_NO_WARNINGS"
		}

		--- PRECOMPILED SOURCE
		pchsource "../GLW/__glw_pch.cpp"

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
