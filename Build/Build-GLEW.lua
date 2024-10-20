project "GLEW"
	kind "StaticLib"
	language "C"
	cdialect "C17"
	staticruntime "off"
	location "../Thirdparty/"

	defines { "GLEW_STATIC" }

	targetdir "%{wks.location}/bin/"
	objdir "%{wks.location}/bin-int/%{prj.name}"

	files { 
		"../Thirdparty/GLEW/include/GL/**.h", 
		"../Thirdparty/GLEW/src/glew.c" 
	}

	includedirs {
		"%{wks.location}/Thirdparty/GLEW/include/"
	}
	externalincludedirs {
		"%{wks.location}/Thirdparty/GLEW/include/"
	}

	filter "system:windows"
		systemversion "latest"
		defines { "WINDOWS", "WIN32_LEAN_AND_MEAN", "_LIB" }
		flags { "MultiProcessorCompile" }
		files { "../Thirdparty/GLEW/build/glew.rc" }

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
