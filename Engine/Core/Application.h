#pragma once

#include "Config.h"
#include "Graphics/Primitives/Buffer.h"
#include "Graphics/Primitives/Shader.h"
#include "Graphics/Primitives/VertexArray.h"
#include "World/Camera/PerspectiveCamera.h"
#include "World/Camera/OthoCamera.h"
#include "World/Scene/Scene.h"
#include "World/World.h"
#include "World/Scene/SceneNode.h"
#include "Event/EventBus.h"
#include "Log.h"
#include "stdafx.h"

namespace Neon
{
	namespace Application
	{
		class Window;
		
		class NEON_API Application
		{
		public:
			Application();

			void Init();
			virtual void Start() = 0;

			virtual void OnUpdate() = 0;
			virtual void OnRender() = 0;
			void Run();

			virtual void Stop() = 0;

			void OnWindowClose(Event::WindowCloseEvent* event);

			virtual ~Application() = default;

		protected:
			std::shared_ptr<Event::EventBus> m_pBus;
			std::shared_ptr<Window> m_Window;
			std::unique_ptr<World::World> mWorld;

			bool m_isRunning = true;
		};

		Application* CreateApplication();
	}
}

