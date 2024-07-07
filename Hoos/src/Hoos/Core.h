#pragma once

#ifdef HS_PLATFORM_WINDOWS
	#ifdef HS_BUILD_DLL
		#define HOOS_API __declspec(dllexport)
	#else
		#define HOOS_API __declspec(dllimport)
	#endif
#else 
	#error Hoos only supports Windows!
#endif

#define BIT(x) (1 << x) 