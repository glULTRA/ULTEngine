#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Ultra {
	class ULT_API Log 
	{
	public:
		static void Init();

		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros.
#define ULT_CORE_ERROR(...)		Ultra::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ULT_CORE_WARN(...)		Ultra::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ULT_CORE_INFO(...)		Ultra::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ULT_CORE_TRACE(...)		Ultra::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ULT_CORE_CRITICAL(...)	Ultra::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define ULT_CORE_ASSERT(...)	Ultra::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros.
#define ULT_ERROR(...)			Ultra::Log::GetClientLogger()->error(__VA_ARGS__)
#define ULT_WARN(...)			Ultra::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ULT_INFO(...)			Ultra::Log::GetClientLogger()->info(__VA_ARGS__)
#define ULT_TRACE(...)			Ultra::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ULT_CRITICAL(...)		Ultra::Log::GetClientLogger()->critical(__VA_ARGS__)
