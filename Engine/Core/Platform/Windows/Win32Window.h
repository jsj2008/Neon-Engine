#pragma once

#include "Core/Config.h"
#include "Core/Window.h"
#include "Graphics/OpenGL/OpenGLContext.h"
#include "Core/Event/EventBus.h"

#include "stdafx.h"

namespace Neon
{
	namespace Application
	{
		class NEON_API Win32Window : public Neon::Application::Window
		{
		public:
			Win32Window(std::string title, int width, int height, std::shared_ptr<Event::EventBus>& globalBus);

			void Update() override;

			void* GetWindowHandle() { return m_WindowHandle; }

			std::shared_ptr<Context> GetContext() override { return m_pContext; }

			glm::vec2 GetDimetions() override { return glm::vec2(m_Width, m_Height); }
			void SetDimetions(const glm::vec2& dim) { m_Width = dim.x; m_Height = dim.y; }

			void SetVSync(bool value) override;

			~Win32Window();

		private:
			void Init();

			void Destroy() {}

		private:
			std::shared_ptr<Context> m_pContext;
			std::shared_ptr<Event::EventBus> m_bus;

			GLFWwindow* m_WindowHandle;
			
			std::string m_title = "OpenGL";

			int m_Width = 800;
			int m_Height = 600;

			bool isVSync = false;
		};
	}
}

