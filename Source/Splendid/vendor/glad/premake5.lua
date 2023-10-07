---------------------------------------------
---------------- Engine ---- ----------------
---------------------------------------------
group "Dependencies"
project "glad"
	kind "staticLib" --dll file
	language "C"

	targetdir ("bin/" .. outputDirectory .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDirectory .. "/%{prj.name}")

	files
	{
		"include/glad/glad.h",
		"include/khr/khrplatform.h",

		"src/glad.c",
		
	}

	includedirs
	{
		"include"
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"		

    filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"
		symbols "off"