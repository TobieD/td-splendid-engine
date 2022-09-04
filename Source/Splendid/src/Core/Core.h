#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL	
		#define SPLENDID_API __declspec(dllexport)
	#else
		#define SPLENDID_API __declspec(dllimport)
	#endif
#else
	#error Splendid only has Windows support
#endif