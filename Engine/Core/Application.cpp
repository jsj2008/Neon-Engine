#include "stdafx.h"
#include "Platform/Windows/Win32InputManager.h"
#include "Platform/Windows/Win32Window.h"
#include "Event/EventBus.h"
#include "Application.h"
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
			mSceneManager = std::make_unique<World::SceneManager>();
			m_Window = std::make_shared<Win32Window>("Neon Game Engine", 1280, 720, this->m_pBus);
			m_Window->SetVSync(true);

			Input::InputManager::Init(m_Window);

			m_pBus->subscribe(this, &Application::OnWindowClose);
			m_isRunning = true;
		}

		void Application::Run()
		{
			while (m_isRunning)
			{
				deltaTime = this->GetDeltaTime();
				
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
		
		double Application::GetDeltaTime()
		{
			double currentTime = glfwGetTime();
			double deltaTime = currentTime - lastTime;
			lastTime = currentTime;

			return deltaTime;
		}
	}
}
