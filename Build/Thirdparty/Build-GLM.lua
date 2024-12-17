project "GLM"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	location "%{wks.location}/Solution/"

	files { 
		"%{IncludeDirs.Glm}/glm/**.h", 
		"%{IncludeDirs.Glm}/glm/**.hpp" 
	}
