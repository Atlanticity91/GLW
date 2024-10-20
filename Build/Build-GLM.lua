project "GLM"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	location "../Thirdparty/"

	files { 
		"../Thirdparty/GLM/glm/**.h", 
		"../Thirdparty/GLM/glm/**.hpp" 
	}
