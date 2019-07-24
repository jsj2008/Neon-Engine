#pragma once

#include "Event.h"

#include "stdafx.h"

namespace Neon
{
	namespace Event
	{
		class MouseMovedEvent : public Event
		{
		public:
			MouseMovedEvent(double x, double y) { MouseX = x; MouseY = y; }
			EventType GetEventType() override { return EventType::MouseMove; }
			const char* GetEventName() override { return "MouseMoved"; }

		public:
			double MouseX = 0;
			double MouseY = 0;
		};

		class MouseButtonPress : public Event
		{
		public:
			MouseButtonPress(int keycode) : key(keycode) {};
			EventType GetEventType() override { return EventType::MousePress; }
			const char* GetEventName() override { return "MousePressed"; }

		public:
			int key;
		};

		class MouseButtonRelease : public Event
		{
		public:
			MouseButtonRelease(int keycode) : key(keycode) {};
			EventType GetEventType() override { return EventType::MouseRelease; }
			const char* GetEventName() override { return "MouseRelease"; }

		public:
			int key;
		};
	}
}

