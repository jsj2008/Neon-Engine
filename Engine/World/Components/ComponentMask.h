#pragma once

#include "Core/Config.h"
#include "Component.h"

namespace Neon
{
	namespace Component
	{
		class NEON_API ComponentMask 
		{
		private:
			unsigned int mask = 0;

		public:
			template <typename ComponentType>
			void AddComponent() 
			{
				mask |= (1 << GetComponentFamily<ComponentType>());
			}

			template <typename ComponentType>
			void RemoveComponent() 
			{
				mask &= ~(1 << GetComponentFamily<ComponentType>());
			}

			bool IsNewMatch(ComponentMask oldMask, ComponentMask systemMask);

			bool IsNoLongerMatched(ComponentMask oldMask, ComponentMask systemMask);

			bool Matches(ComponentMask systemMask);
		};
	}
}