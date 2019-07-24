#include "stdafx.h"
#include "Log.h"

namespace Neon
{
	std::shared_ptr<spdlog::logger> Log::m_logger;

	void Log::Init()
	{
		m_logger = spdlog::stdout_color_mt("Console");

		m_logger->set_pattern("%^[%T] %n : %v%$");
	}

	void Log::Trace(const std::string& message)
	{
		m_logger->trace(message);
	}

	void Log::Info(const std::string& message)
	{
		m_logger->info(message);
	}

	void Log::Warn(const std::string& message)
	{
		m_logger->warn(message);
	}

	void Log::Critical(const std::string& message)
	{
		m_logger->critical(message);
	}
}