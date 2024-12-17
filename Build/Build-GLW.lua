project "GLW"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
    staticruntime "off"
    location "../Solution/"

    --- OUTPUT
    targetdir "%{wks.location}/bin/%{cfg.buildcfg}/"
	debugdir "%{wks.location}/bin/%{cfg.buildcfg}/"
	objdir "%{wks.location}/bin-int/%{prj.name}-%{cfg.buildcfg}"

    defines "_CRT_SECURE_NO_WARNINGS"

    links { "GLEW" }

    includedirs {
		"%{IncludeDirs.Glw}/",
		"%{IncludeDirs.Glm}/",
		"%{IncludeDirs.Glew}/include/"
	}
	
	externalincludedirs { 
		"%{IncludeDirs.Glw}/",
		"%{IncludeDirs.Glm}/",
		"%{IncludeDirs.Glew}/include/"
	}

	pchheader "__glw_pch.h"

	files { 
		"%{IncludeDirs.Glw}/**.h", 
		"%{IncludeDirs.Glw}/**.cpp" 
	}

	--- WINDOWS
    filter "system:windows"
		systemversion "latest"
		defines "WINDOWS"
		flags "MultiProcessorCompile"

	    pchsource "../GLW/__glw_pch.cpp"

	--- CONFIGURATIONS
	filter "configurations:Debug"
		defines { "DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines { "DIST" }
		runtime "Release"
		optimize "On"
		symbols "Off"
