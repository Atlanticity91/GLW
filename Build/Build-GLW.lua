project "GLW"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
    staticruntime "off"

    defines { "_CRT_SECURE_NO_WARNINGS" }

	files { "../include/**.h", "../src/**.cpp" }

	pchheader "__glw_pch.h"
    pchsource "../src/__glw_pch.cpp"

	targetdir "%{wks.location}/bin/"
	objdir "%{wks.location}/bin-int/%{prj.name}"

    links { "GLEW" }

	includedirs {
		"%{wks.location}/include/",
		"%{wks.location}/Thirdparty/GLM/",
		"%{wks.location}/Thirdparty/GLEW/include/"
	}
	externalincludedirs { 
		"%{wks.location}/include/",
		"%{wks.location}/Thirdparty/GLM/",
		"%{wks.location}/Thirdparty/GLEW/include/"
	}

    filter "system:windows"
		systemversion "latest"
		defines { "WINDOWS" }
		flags { "MultiProcessorCompile" }

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
