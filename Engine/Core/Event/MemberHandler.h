#pragma once

#include "Event.h"
#include "MouseEvent.h"
#include "WindowEvent.h"
#include "KeyEvent.h"
#include "Core/Config.h"

#include "stdafx.h"

namespace Neon
{
	namespace Event
	{
		// The HandlerBase class is used as a generic base class for MemberHandler 
		class NEON_API HandlerBase
		{
		public:
			// Call the member function
			void exec(Event* evnt) {
				call(evnt);
			}
		private:
			// Implemented by MemberHandler
			virtual void call(Event* evnt) = 0;
		};


		template<class T, class EventType>
		class NEON_API MemberHandler : public HandlerBase
		{
		public:
			typedef void (T::* MemberFunction)(EventType*);

			MemberHandler(T* instance, MemberFunction memberFunction) : instance{ instance }, memberFunction{ memberFunction } {};

			void call(Event* evnt) {
				// Cast event to the correct type and call member function
				(instance->*memberFunction)(static_cast<EventType*>(evnt));
			}
		private:
			// Pointer to class instance
			T* instance;

			// Pointer to member function
			MemberFunction memberFunction;
		};
	}
}


