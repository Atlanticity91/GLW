project "GLEW"
	kind "StaticLib"
	language "C"
	cdialect "C17"
	staticruntime "off"
	location "../../Solution/"

	defines "GLEW_STATIC"

	targetdir "%{wks.location}/bin/%{cfg.buildcfg}/"
	debugdir "%{wks.location}/bin/%{cfg.buildcfg}/"
	objdir "%{wks.location}/bin-int/%{prj.name}-%{cfg.buildcfg}"

	files { 
		"%{IncludeDirs.Glew}/include/GL/**.h", 
		"%{IncludeDirs.Glew}/src/glew.c" 
	}

	includedirs "%{IncludeDirs.Glew}/include/"
	externalincludedirs "%{IncludeDirs.Glew}/include/"

	filter "system:windows"
		systemversion "latest"
		flags "MultiProcessorCompile" 

		defines { 
			"WINDOWS", 
			"WIN32_LEAN_AND_MEAN", 
			"_LIB" 
		}
		
		files "%{IncludeDirs.Glew}/build/glew.rc" 

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
