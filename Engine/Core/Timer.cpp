#include "stdafx.h"
#include "Timer.h"
#include "Log.h"

namespace Neon
{
	std::chrono::high_resolution_clock Timer::clock;
	std::chrono::high_resolution_clock::time_point Timer::t1, Timer::t2;

	void Timer::Start()
	{
		t1 = clock.now();
	}

	void Timer::Stop(bool logResult, TimeMeasure type)
	{
		t2 = clock.now();

		switch (type)
		{
			case Microsecond:
			{
				std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
				Log::Info(std::to_string(duration.count()));
				break;
			}
			case Millisecond:
			{
				std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
				Log::Info(std::to_string(duration.count()));
				break;
			}
			case Second:
			{
				std::chrono::seconds duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1);
				Log::Info(std::to_string(duration.count()));
				break;
			}
		}
	}
}
