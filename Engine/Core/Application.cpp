#include "stdafx.h"
#include "Platform/Windows/Win32InputManager.h"
#include "Platform/Windows/Win32Window.h"
#include "Event/EventBus.h"
#include "glm/gtx/string_cast.hpp"
#include "Graphics/Renderer.h"
#include "Application.h"
#include "KeyCode.h"
#include "Log.h"

namespace Neon
{
	namespace Application
	{
		Application::Application() { Init(); }

		void Application::Init()
		{
			Log::Init();
			Log::Info("Engine Initialize!");
			
			m_pBus = std::make_shared<Event::EventBus>();
			mWorld = std::make_unique<World::World>("Main");
			m_Window = std::make_shared<Win32Window>("Neon Game Engine", 1000, 720, this->m_pBus);
			m_Window->SetVSync(true);

			Input::InputManager::Init(m_Window);

			m_pBus->subscribe(this, &Application::OnWindowClose);
			m_isRunning = true;
		}

		void Application::Run()
		{
			while (m_isRunning)
			{
				OnUpdate();
				OnRender();

				m_Window->Update();
			}
			
			glfwTerminate();
		}

		void Application::OnWindowClose(Event::WindowCloseEvent* event)
		{
			m_isRunning = false;
		}
	}
}