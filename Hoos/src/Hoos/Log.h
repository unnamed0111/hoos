#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hoos {

	class HOOS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define HS_CORE_TRACE(...)	::Hoos::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define HS_CORE_INFO(...)	::Hoos::Log::GetCoreLogger()->info(__VA_ARGS__);
#define HS_CORE_WARN(...)	::Hoos::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define HS_CORE_ERROR(...)	::Hoos::Log::GetCoreLogger()->error(__VA_ARGS__);
#define HS_CORE_FATAL(...)	::Hoos::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client log macros
#define HS_TRACE(...)	::Hoos::Log::GetClientLogger()->trace(__VA_ARGS__);
#define HS_INFO(...)	::Hoos::Log::GetClientLogger()->info(__VA_ARGS__);
#define HS_WARN(...)	::Hoos::Log::GetClientLogger()->warn(__VA_ARGS__);
#define HS_ERROR(...)	::Hoos::Log::GetClientLogger()->error(__VA_ARGS__);
#define HS_FATAL(...)	::Hoos::Log::GetClientLogger()->fatal(__VA_ARGS__);