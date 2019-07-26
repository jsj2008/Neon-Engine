#pragma once

#include "Core/Config.h"
#include "Scene/SceneManager.h"

namespace Neon
{
	namespace World
	{
		class SceneHandle;
		
		class NEON_API World
		{
		private:
			friend class SceneHandle;

		public:
			World(const std::string& name);

			void CreateScene(const std::string& name);

			SceneHandle GetScene(const std::string& name);

			void IterateScenes(std::function<void(const SceneHandle& scene)> lambda);

			 ~World() { delete mSceneManager; }

		private:
			SceneManager* mSceneManager;

			std::string mName;
		};
	}
}

