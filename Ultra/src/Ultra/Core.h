#pragma once

#ifdef ULT_PLATFORM_WINDOWS
	#ifdef ULT_BUILD_DLL
		#define ULT_API __declspec(dllexport)
	#else
		#define ULT_API __declspec(dllimport)
	#endif
#else
	
#endif