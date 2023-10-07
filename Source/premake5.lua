workspace "Splendid"
    architecture "x64"

    configurations
    {
        "Debug", --Debug code
        "Release", --Debug with optimization turned on
        "Distributable" --Everything stripped without logging
    }

    startproject "Sandbox"

outputDirectory = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" --eg. debug-windows-x64

-- Dependencies
IncludeDir = {}
IncludeDir["GLFW"] = "Splendid/vendor/GLFW/include"
IncludeDir["glad"] = "Splendid/vendor/glad/include"

--includes the Premake files
include "Splendid/vendor/GLFW" 
include "Splendid/vendor/glad" 

---------------------------------------------
---------------- Engine ---- ----------------
---------------------------------------------
group "Engine"
project "Splendid"
    location "Splendid"
    kind "SharedLib" --dll file
    language "C++"

    targetdir ("bin/" .. outputDirectory .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDirectory .. "/%{prj.name}")

    pchheader "splendidpch.h"
    pchsource "Splendid/src/splendidpch.cpp"

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
        "%{IncludeDir.glad}"
    }

    links
    {
        "GLFW",
        "glad",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SP_PLATFORM_WINDOWS",
            "SP_BUILD_DLL",
            "GLFW_INCLUDE_NONE" 
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDirectory .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines
        {
            "SP_DEBUG", 
            "SP_ENABLE_ASSERTION"
        }
        symbols "On"
		buildoptions "/MDd"

    filter "configurations:Release"
        defines "SP_RELEASE"
        optimize "On"
		buildoptions "/MDd"

    filter "configurations:Distributable"
        defines "SP_DIST"
        optimize "On"
		buildoptions "/MD"


---------------------------------------------
---------------- Application ----------------
---------------------------------------------
group "Samples"
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp" --exe file
    language "C++"

    targetdir ("bin/" .. outputDirectory .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDirectory .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Splendid/vendor/spdlog/include",
        "Splendid/src"
    }

    links
    {
        "Splendid"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SP_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "SP_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SP_RELEASE"
        optimize "On"

    filter "configurations:Distributable"
        defines "SP_DIST"
        optimize "On"