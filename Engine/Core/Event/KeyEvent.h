#pragma once

#include "Event.h"

namespace Neon
{
	namespace Event
	{
		class KeyPressed : public Event
		{
		public:
			KeyPressed(int keycode, bool repeatCount) : key(keycode), repeat(repeatCount) {}
			EventType GetEventType() override { return EventType::KeyPress; }
			const char* GetEventName() override { return "KeyPress"; }

		public:
			const int key;
			const bool repeat;
		};

		class KeyReleased : public Event
		{
		public:
			KeyReleased(int keycode) : key(keycode) {}
			EventType GetEventType() override { return EventType::KeyRelease; }
			const char* GetEventName() override { return "KeyRelease"; }

		public:
			const int key;
		};
	}
}