#include "log.h"
#include "LogManager.h"
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <vector>

namespace NestExchange {
	

	void LogManager::Initialize()
	{
		auto consoleSink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();	
		consoleSink->set_pattern("%^[%T] %n:%v%$");

		std::vector<spdlog::sink_ptr>sinks{consoleSink};
		auto logger = std::make_shared<spdlog::logger>(NESTEXCHANGE_DEFAULT_LOGGER_NAME,sinks.begin(),sinks.end());
		logger->set_level(spdlog::level::trace);
		logger->flush_on(spdlog::level::trace);
		spdlog::register_logger(logger);
	}

	void LogManager::ShutDown()
	{
		spdlog::shutdown();

	}

}
