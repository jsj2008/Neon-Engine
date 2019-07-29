#pragma once

#include "stdafx.h"
#include "Core/Config.h"
#include "SceneRef.h"

namespace Neon
{
	namespace World
	{
		class Scene;
		
		class NEON_API SceneManager
		{
		private:
			friend class SceneRef;

		public:
			SceneManager() = default;

			void CreateScene(const std::string& name, bool mActive = true);
			void DeleteScene(const std::string& name);

			SceneRef GetScene(const std::string& name);
			SceneRef GetActiveScene();
			
			~SceneManager();

		private:
			Scene* GetScenePtr(const std::string& name);

		private:
			std::unordered_map<std::string, std::unique_ptr<Scene>> mScenes;
			std::unordered_map<std::string, SceneRef> mSceneRefs;

			std::string mActiveScene;
		};
	}
}