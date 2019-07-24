#include "stdafx.h"
#include "Win32Window.h"
#include "Core/Log.h"

namespace Neon
{
	namespace Application
	{
		Win32Window::Win32Window(std::string title, int width, int height, std::shared_ptr<Event::EventBus>& globalBus) : m_title(title), m_Width(width), m_Height(height), m_bus(globalBus)
		{
			Init();
		}

		void Win32Window::Update()
		{
			m_pContext->SwapBuffers();
		}

		void Win32Window::SetVSync(bool value)
		{
			glfwSwapInterval((int)value);
			isVSync = value;
		}

		Win32Window::~Win32Window()
		{
			Destroy();
		}
		
		void Win32Window::Init()
		{
			int status = glfwInit();

			if (!status) { Log::Critical("Could not initialize GLFW!"); glfwTerminate(); return; }
			glfwWindowHint(GLFW_SAMPLES, 4);

			m_WindowHandle = glfwCreateWindow(m_Width, m_Height, m_title.c_str(), NULL, NULL);

			m_pContext = std::make_shared<Graphics::OpenGLContext>(m_WindowHandle);
			m_pContext->Init();

			glfwSetWindowUserPointer(m_WindowHandle, this);

			glfwSetFramebufferSizeCallback(m_WindowHandle, [](GLFWwindow* window, int width, int height)
			{
				glViewport(0, 0, width, height);
			});

			glfwSetWindowCloseCallback(m_WindowHandle, [](GLFWwindow* window)
			{
				Win32Window* this_ptr = (Win32Window*)glfwGetWindowUserPointer(window);
				this_ptr->m_bus->publish(new Event::WindowCloseEvent());
			});

			glfwSetCursorPosCallback(m_WindowHandle, [](GLFWwindow* window, double xpos, double ypos)
			{
				Win32Window* this_ptr = (Win32Window*)glfwGetWindowUserPointer(window);
				this_ptr->m_bus->publish(new Event::MouseMovedEvent(xpos, ypos));
			});

			glfwSetErrorCallback([](int error_code, const char* description)
			{
				Log::Critical("GLFW error: " + std::to_string(error_code) + " " + std::string(description));
			});

			glfwSetMouseButtonCallback(m_WindowHandle, [](GLFWwindow* window, int button, int action, int mods)
			{
				Win32Window* this_ptr = (Win32Window*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						this_ptr->m_bus->publish(new Event::MouseButtonPress(button));
						break;
					}
					case GLFW_RELEASE:
					{
						this_ptr->m_bus->publish(new Event::MouseButtonRelease(button));
						break;
					}
				}
			});

			glfwSetKeyCallback(m_WindowHandle, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				Win32Window* this_ptr = (Win32Window*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						this_ptr->m_bus->publish(new Event::KeyPressed(key, 0));
						break;
					}
					case GLFW_RELEASE:
					{
						this_ptr->m_bus->publish(new Event::KeyReleased(key));
						break;
					}
					case GLFW_REPEAT:
					{
						this_ptr->m_bus->publish(new Event::KeyPressed(key, 1));
						break;
					}
				}
			});
		}
	}
}
