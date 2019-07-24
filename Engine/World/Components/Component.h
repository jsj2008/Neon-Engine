#pragma once

#include "Core/Config.h"

namespace Neon
{
	namespace Component
	{
		struct NEON_API ComponentCounter 
		{
			static int familyCounter;
		};

		template <typename ComponentType>
		struct Component 
		{
			static inline int family() 
			{
				static int family = ComponentCounter::familyCounter++;
				return family;
			}
		};

		template <typename ComponentType>
		static int GetComponentFamily() 
		{
			return Component<typename std::remove_const<ComponentType>::type>::family();
		}
	}
}