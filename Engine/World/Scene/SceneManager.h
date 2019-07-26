#pragma once

#include "stdafx.h"
#include "Core/Config.h"

namespace Neon
{
	namespace World
	{
		class Scene;
		class World;
		class SceneHandle;
		
		class NEON_API SceneManager
		{
		public:
			SceneManager() = default;

			void CreateScene(const std::string& name);
			Scene* GetScene(const std::string& name);

			void DeleteScene(const std::string& name);
			void Iterate(World* world, std::function<void(const SceneHandle& scene)> lambda);

			~SceneManager();

		private:
			std::unordered_map<std::string, Scene*> mScenes;

		};
	}
}