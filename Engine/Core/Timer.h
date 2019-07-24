#pragma once

#include "Config.h"

#include "stdafx.h"

namespace Neon
{
	enum TimeMeasure { Microsecond, Millisecond, Second };
	
	class Timer
	{
	public:
		Timer() = default;

		void Start();

		void Stop(bool logResult = true, TimeMeasure type = TimeMeasure::Millisecond);

		~Timer() = default;

	private:
		static std::chrono::high_resolution_clock clock;
		static std::chrono::high_resolution_clock::time_point t1, t2;
	};

}

