#pragma once

#include "Config.h"
#include "World/Component/Component.h"

namespace Neon 
{
	namespace System
	{
		class NEON_API System
		{
		public:
			System() = default;

			virtual void Init() = 0;
			virtual void Update() = 0;

			virtual ~System() = default;
		};
		
	}
}