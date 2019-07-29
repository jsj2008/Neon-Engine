#include "stdafx.h"
#include "SceneRef.h"
#include "Scene.h"
#include "SceneManager.h"

namespace Neon
{
	namespace World
	{
		Scene* Neon::World::SceneRef::operator->() const
		{
			NEON_ASSERT(mSceneManager->mScenes.count(mName) > 0);
			NEON_ASSERT(mSceneManager->mScenes[mName] != nullptr);

			return mSceneManager->GetScenePtr(mName);
		}
	}
}
