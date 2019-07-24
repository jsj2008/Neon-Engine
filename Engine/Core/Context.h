#pragma once

#include "Config.h"

#include "stdafx.h"

namespace Neon
{
	namespace Application
	{
		class NEON_API Context
		{
		public:
			Context() = default;

			virtual void Init() {};

			virtual void SwapBuffers() {};
		};
	}
}