#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Splendid
{
	class SPLENDID_API Log
	{
		public:
			static void Initialize();

			inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_EngineLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
			
			static const std::string SIMPLE_LOG_PATTERN;			
	};
}

// HINT: Using Macros allows us to strip these defines on specific platforms
#define SP_CORE_FATAL(...) ::Splendid::Log::GetEngineLogger()->fatal(__VA_ARGS__)
#define SP_CORE_ERROR(...) ::Splendid::Log::GetEngineLogger()->error(__VA_ARGS__)
#define SP_CORE_WARN(...)  ::Splendid::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define SP_CORE_INFO(...)  ::Splendid::Log::GetEngineLogger()->info(__VA_ARGS__)
#define SP_CORE_DEBUG(...) ::Splendid::Log::GetEngineLogger()->debug(__VA_ARGS__)

#define SP_FATAL(...) ::Splendid::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define SP_ERROR(...) ::Splendid::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_WARN(...)  ::Splendid::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_INFO(...)  ::Splendid::Log::GetClientLogger()->info(__VA_ARGS__)
#define SP_DEBUG(...) ::Splendid::Log::GetClientLogger()->debug(__VA_ARGS__)