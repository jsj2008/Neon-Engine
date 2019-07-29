#include "stdafx.h"
#include "Scene.h"
#include "SceneRef.h"
#include "SceneNode.h"
#include "SceneManager.h"

namespace Neon
{
	namespace World
	{
		void SceneManager::CreateScene(const std::string& name, bool mActive)
		{
			mScenes[name] = std::make_unique<Scene>(name);
			mSceneRefs[name] = SceneRef(name, this);

			mActiveScene = mActive ? name : mActiveScene;
		}

		SceneRef SceneManager::GetScene(const std::string& name)
		{
			NEON_ASSERT(mScenes.count(name) > 0);
			return mSceneRefs[name];
		}

		SceneRef SceneManager::GetActiveScene()
		{
			return mSceneRefs[mActiveScene];
		}

		SceneManager::~SceneManager()
		{
			mSceneRefs.clear();
			mScenes.clear();
		}

		Scene* SceneManager::GetScenePtr(const std::string& name)
		{
			return mScenes[name].get();
		}

		void SceneManager::DeleteScene(const std::string& name)
		{
			if (mScenes.count(name) > 0)
				mScenes.at(name).reset();
		}
	}
}
