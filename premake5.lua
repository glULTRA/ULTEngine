workspace "Ultra"
	architecture  "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Ultra"
	location "Ultra"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/" .. outputdir .. "/%{prj.name}")

	pchheader "ultpch.h"
	pchsource "Ultra/src/ultpch.cpp"
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0"

		defines{
			"ULT_PLATFORM_WINDOWS",
			"ULT_BUILD_DLL"
		}

		postbuildcommands{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}
	filter "configurations:Debug"
		defines "ULT_DEBUG"
		optimize  "On"
	filter "configurations:Release"
		defines "ULT_RELEASE"
		optimize  "On"
	filter "configurations:Dist"
		defines "ULT_DIST"
		optimize  "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/" .. outputdir .. "/%{prj.name}")

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
		optimize  "On"
	filter "configurations:Release"
		defines "ULT_RELEASE"
		optimize  "On"
	filter "configurations:Dist"
		defines "ULT_DIST"
		optimize  "On"