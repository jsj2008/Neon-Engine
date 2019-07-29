#pragma once

#include "Config.h"

// Libraries
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Neon
{
	class Log
	{
	public:
		Log() = default;

		static void Init();

		static void Trace(const std::string& message);
		static void Trace(int num) { Log::Trace(std::to_string(num)); }
		
		static void Info(const std::string& message);
		static void Info(int num) { Log::Info(std::to_string(num)); }
		
		static void Warn(const std::string& message);
		static void Warn(int num) { Log::Warn(std::to_string(num)); }
		
		static void Critical(const std::string& message);
		static void Critical(int num) { Log::Critical(std::to_string(num)); }

		~Log() { spdlog::shutdown(); }

	private:
		static std::shared_ptr<spdlog::logger> m_logger;
	};
}

