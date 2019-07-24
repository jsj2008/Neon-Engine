#pragma once

#include "Event.h"

#include "stdafx.h"

namespace Neon
{
	namespace Event
	{
		class WindowCloseEvent : public Event
		{
		public:
			EventType GetEventType() override { return EventType::WindowClose; }
			const char* GetEventName() override { return "WindowClose"; }
		};

		class WindowResizeEvent : public Event
		{
		public:
			EventType GetEventType() override { return EventType::WindowResize; }
			const char* GetEventName() override { return "WindowRelease"; }

		private:
			int new_width = 0;
			int new_height = 0;
		};
	}
}
