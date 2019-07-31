#include "stdafx.h"
#include "OpenGLContext.h"
#include "Core/Log.h"

namespace Neon
{
	namespace Graphics
	{
		OpenGLContext::OpenGLContext(GLFWwindow* window) : m_pWindow(window)
		{
			glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			if (!window) { Log::Critical("GLFW Window is NULL!"); }
		}

		void OpenGLContext::Init()
		{
			glfwMakeContextCurrent(m_pWindow);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { Log::Critical("Could not initialize Glad!"); return; }

			Log::Info("OpenGL Info:");
			Log::Info("  Vendor: " + std::string(reinterpret_cast<const char*>(glGetString(GL_VENDOR))));
			Log::Info("  Renderer: " + std::string(reinterpret_cast<const char*>(glGetString(GL_RENDERER))));
			Log::Info("  Version: " + std::string(reinterpret_cast<const char*>(glGetString(GL_VERSION))));

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_MULTISAMPLE);
			glEnable(GL_STENCIL_TEST);
		}
		
		void OpenGLContext::SwapBuffers()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_pWindow);
		}
		
		void OpenGLContext::EnableDepth()
		{
			glDepthMask(true);
		}

		void OpenGLContext::DisableDepth()
		{
			glDepthMask(false);
		}
	}
}