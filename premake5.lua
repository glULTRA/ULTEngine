workspace "Ultra"
	architecture  "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Ultra/vendor/GLFW/include"

include "Ultra/vendor/GLFW"

project "Ultra"
	location "Ultra"
	kind "SharedLib"
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
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib",
		"gdi32.lib",
		"shell32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines{
			"ULT_PLATFORM_WINDOWS",
			"ULT_BUILD_DLL"
		}

		postbuildcommands{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}
	filter "configurations:Debug"
		defines "ULT_DEBUG"
		buildoptions "/MDd"
		optimize  "On"
	filter "configurations:Release"
		defines "ULT_RELEASE"
		buildoptions "/MD"
		optimize  "On"
	filter "configurations:Dist"
		defines "ULT_DIST"
		buildoptions "/MD"
		optimize  "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
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
		staticruntime "On"
		systemversion "10.0"

		defines{
			"ULT_PLATFORM_WINDOWS"
		}

	links{
		"Ultra"
	}

	filter "configurations:Debug"
		defines "ULT_DEBUG"
		buildoptions "/MDd"
		optimize  "On"
	filter "configurations:Release"
		defines "ULT_RELEASE"
		buildoptions "/MD"
		optimize  "On"
	filter "configurations:Dist"
		defines "ULT_DIST"
		buildoptions "/MD"
		optimize  "On"