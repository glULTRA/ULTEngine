#pragma once

#ifdef ULT_PLATFORM_WINDOWS
	#ifdef ULT_BUILD_DLL
		#define ULT_API __declspec(dllexport)
	#else
		#define ULT_API __declspec(dllimport)
	#endif
#else
	#error ULT Supports windows for now!
#endif

#ifdef ULT_ENABLE_ASSERTS
	#define ULT_ASSERT(x, ...) {}
#else
	#define ULT_ASSERT(x, ...)
	#define ULT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)