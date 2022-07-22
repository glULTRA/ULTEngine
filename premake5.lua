workspace "Ultra"
	architecture  "x64"
	startproject "SandBox"
	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Ultra/vendor/GLFW/include"
IncludeDir["Glad"] = "Ultra/vendor/Glad/include"
IncludeDir["ImGui"] = "Ultra/vendor/ImGui"

include "Ultra/vendor/GLFW"
include "Ultra/vendor/Glad"
include "Ultra/vendor/ImGui"

project "Ultra"
	location "Ultra"
	kind "SharedLib"
	staticruntime "off"

	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ultpch.h"
	pchsource "Ultra/src/ultpch.cpp"
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"gdi32.lib",
		"shell32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

		defines{
			"ULT_PLATFORM_WINDOWS",
			"ULT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}
	filter "configurations:Debug"
		defines "ULT_DEBUG"
		runtime "Debug"
		optimize  "On"
	filter "configurations:Release"
		defines "ULT_RELEASE"
		runtime "Release"
		optimize  "On"
	filter "configurations:Dist"
		defines "ULT_DIST"
		runtime "Release"
		optimize  "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	staticruntime "off"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"Ultra/vendor/spdlog/include",
		"Ultra/src"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

		defines{
			"ULT_PLATFORM_WINDOWS"
		}

	links{
		"Ultra"
	}

	filter "configurations:Debug"
		defines "ULT_DEBUG"
		runtime "Debug"
		optimize  "On"
	filter "configurations:Release"
		defines "ULT_RELEASE"
		runtime "Release"
		optimize  "On"
	filter "configurations:Dist"
		defines "ULT_DIST"
		runtime "Release"
		optimize  "On"