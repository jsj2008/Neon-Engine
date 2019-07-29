#include "stdafx.h"
#include "Win32InputManager.h"

namespace Neon
{
	namespace Input
	{
		namespace detail
		{
			std::shared_ptr<Application::Window> Win32InputManager::m_pWindow;

			void Win32InputManager::Init(std::shared_ptr<Application::Window>& window)
			{
				m_pWindow = window;
			}

			bool Win32InputManager::GetKey(int keycode)
			{
				GLFWwindow* window = static_cast<GLFWwindow*>(m_pWindow->GetWindowHandle());
				return (glfwGetKey(window, keycode) == GLFW_PRESS);
			}
			
			glm::vec2 Win32InputManager::GetMousePos()
			{
				GLFWwindow* window = static_cast<GLFWwindow*>(m_pWindow->GetWindowHandle());
				
				double xpos = 0;
				double ypos = 0;
				
				glfwGetCursorPos(window, &xpos, &ypos);

				return glm::vec2(xpos, ypos);
			}
		}
	}
}
