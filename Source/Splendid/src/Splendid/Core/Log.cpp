#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"


namespace Splendid
{
	const std::string Log::SIMPLE_LOG_PATTERN = "%^[%T] %n: %v%$";

	std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Initialize()
	{
		spdlog::set_pattern(SIMPLE_LOG_PATTERN);
		s_EngineLogger = spdlog::stdout_color_mt("SPLENDID");
		s_EngineLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}