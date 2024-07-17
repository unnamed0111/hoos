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

#ifdef HS_DEBUG
	#define HS_ENABLE_ASSERTS
#endif

#ifdef HS_ENABLE_ASSERTS
	#define HS_ASSERT(x, ...) { if(!(x)) { HS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HS_CORE_ASSERT(x, ...) { if(!(x)) {HS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HS_ASSERT(x, ...)
	#define HS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)