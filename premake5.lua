workspace "Ultra"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ultra"
	location "Ultra"
	language "C++"
	kind "SharedLib"
	targetdir ("bin/" .. outputdir .. "%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "%{prj.name}")

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0"

		postbuildcommands{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		optimize  "On"
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize  "On"
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize  "On"

project "SandBox"
	location "SandBox"
	language "C++"
	kind "ConsoleApp"

	targetdir ("bin/" .. outputdir .. "%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "%{prj.name}")

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0"

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		optimize  "On"
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize  "On"
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize  "On"