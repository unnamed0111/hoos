workspace "Hoos"
	architecture "x64"
	startproject "Sandbox"

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
IncludeDir["Glad"] = "Hoos/vendor/Glad/include"
IncludeDir["ImGui"] = "Hoos/vendor/imgui"

include "Hoos/vendor/GLFW"
include "Hoos/vendor/Glad"
include "Hoos/vendor/imgui"

project "Hoos"
	location "Hoos"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"HS_PLATFORM_WINDOWS",
			"HS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "HS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HS_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HS_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		systemversion "latest"

		defines
		{
			"HS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HS_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HS_DIST"
		runtime "Release"
		optimize "On"