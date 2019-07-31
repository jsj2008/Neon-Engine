#pragma once

#include "Core/Config.h"
#include "ISystem.h"

namespace Neon
{
	namespace Application
	{
		class NEON_API CoreContext
		{
		public:
			CoreContext() = default;

			void Update() const;

			template <typename T>
			T* GetSystem();

		private:
			std::vector<System::System> mSystems;
		};
	}
}