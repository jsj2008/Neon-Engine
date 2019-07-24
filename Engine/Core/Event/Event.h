#pragma once

#include "Core/Config.h"

#include "stdafx.h"

namespace Neon
{
	namespace Event
	{
		enum EventType
		{
			EventDefault,
			WindowResize, WindowClose,
			MousePress, MouseRelease, MouseMove,
			KeyPress, KeyRelease
		};

		class NEON_API Event
		{
		public:
			virtual EventType GetEventType() { return EventType::EventDefault; }
			virtual const char* GetEventName() { return "Event"; }

		private:
			EventType m_eventType;
		};
	}
}


