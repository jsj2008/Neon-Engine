#pragma once

#include "Core/Config.h"
#include "Core/Window.h"
#include "glm/glm.hpp"

namespace Neon
{
	namespace Input
	{
		namespace detail
		{
			class NEON_API Win32InputManager
			{
			public:
				Win32InputManager() = default;

				static void Init(std::shared_ptr<Application::Window>& window);

				static bool GetKey(int keycode);

				static glm::vec2 GetMousePos();

				~Win32InputManager() = default;

			private:
				static std::shared_ptr<Application::Window> m_pWindow;
			};
		}

		#if defined(NEON_PLATFORM_WINDOWS)
		typedef Input::detail::Win32InputManager InputManager;
		#endif
	}
}