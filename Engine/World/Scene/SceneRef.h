#pragma once

#include "Core/Config.h"
#include "Scene.h"

namespace Neon
{
	namespace World
	{
		class SceneManager;
		class Scene;
		
		class NEON_API SceneRef
		{
		public:
			SceneRef() = default;
			SceneRef(const std::string& name, SceneManager* manager) : mName(name), mSceneManager(manager) {}

			Scene* operator -> () const;

		private:
			std::string mName;
			SceneManager* mSceneManager;
		};
	}
}