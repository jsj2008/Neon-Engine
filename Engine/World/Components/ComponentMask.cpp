#include "stdafx.h"
#include "ComponentMask.h"

namespace Neon
{
	namespace Component
	{
		bool ComponentMask::IsNewMatch(ComponentMask oldMask, ComponentMask systemMask) {
			return Matches(systemMask) && !oldMask.Matches(systemMask);
		}

		bool ComponentMask::IsNoLongerMatched(ComponentMask oldMask, ComponentMask systemMask) {
			return oldMask.Matches(systemMask) && !Matches(systemMask);
		}

		bool ComponentMask::Matches(ComponentMask systemMask) { return ((mask & systemMask.mask) == systemMask.mask); }
	}
}