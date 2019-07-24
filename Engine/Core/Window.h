#pragma once

#include "Config.h"
#include "Event/EventBus.h"

#include "stdafx.h"

namespace Neon
{
	namespace Application
	{
		class Context;
		
		class NEON_API Window
		{
		public:
			Window() = default;

			virtual void Update() {};

			virtual void* GetWindowHandle() { return nullptr; }

			virtual std::shared_ptr<Context> GetContext() { return nullptr; }

			virtual void SetVSync(bool value) {}

			virtual ~Window() = default;

		private:
			virtual void Init() {};

			virtual void Destroy() {};
		};

	}
}
