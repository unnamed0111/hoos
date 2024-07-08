workspace "Hoos"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hoos/vendor/GLFW/include"

include "Hoos/vendor/GLFW"

project "Hoos"
	location "Hoos"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-init/" .. outputdir .. "/%{prj.name}")

	pchheader "hspch.h"
	pchsource "Hoos/src/hspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HS_PLATFORM_WINDOWS",
			"HS_BUILD_DLL"
		}

		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}

	filter "configurations:Debug"
		defines "HS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HS_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-init/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hoos/vendor/spdlog/include",
		"Hoos/src"
	}

	links
	{
		"Hoos"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HS_DIST"
		optimize "On"