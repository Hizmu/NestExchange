#pragma once
#include <spdlog/spdlog.h>

#define NESTEXCHANGE_DEFAULT_LOGGER_NAME "nestlogger"

#define NEST_TRACE(...) if(spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)!= nullptr)  \
	{spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__);}
#define NEST_INFO(...) if(spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)!= nullptr)  \
	{spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)->info(__VA_ARGS__);}
#ifdef NEST_DEBUG
#define NEST_DEBUG_INFO(...) if(spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)!= nullptr) \
	{spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)-info(__VA_ARGS__);}
#endif
#define NEST_WARNING(...) if(spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)!= nullptr)  \
	{spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)->warn(__VA_ARGS__);}
#define NEST_ERROR(...) if(spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)!= nullptr)  \
	{spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)->error(__VA_ARGS__);}
#define NEST_FATAL(...) if(spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)!= nullptr)  \
	{spdlog::get(NESTEXCHANGE_DEFAULT_LOGGER_NAME)->critical(__VA_ARGS__);}
