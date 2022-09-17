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


//Assertions
//Check a condition and log a message + break the debugger
#ifdef SP_ENABLE_ASSERTION
	#define SP_CORE_ASSERT(x, ...) { if(!(x)) {SP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SP_CORE_ASSERT(x, ...)
#endif


//Helpers
#define BIT(x) (1 << x)