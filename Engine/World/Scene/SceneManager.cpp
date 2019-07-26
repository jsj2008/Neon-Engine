#include "stdafx.h"
#include "Scene.h"
#include "SceneHandle.h"
#include "World/World.h"
#include "SceneManager.h"

namespace Neon
{
	namespace World
	{
		void SceneManager::CreateScene(const std::string& name)
		{
			mScenes[name] = new Scene(name);
		}

		Scene* SceneManager::GetScene(const std::string& name)
		{
			NEON_ASSERT(mScenes.count(name) > 0);
			return mScenes[name];
		}

		void SceneManager::DeleteScene(const std::string& name)
		{
			if (mScenes.count(name) > 0)
				delete mScenes.at(name);
		}

		void SceneManager::Iterate(World* world, std::function<void(const SceneHandle& scene)> lambda)
		{
			for (auto& kv : mScenes)
			{
				lambda(SceneHandle(world, kv.second));
			}
		}

		SceneManager::~SceneManager()
		{
			for (auto it = mScenes.begin(); it != mScenes.end(); it++)
			{
				delete (*it).second;
			}
		}
	}
}
