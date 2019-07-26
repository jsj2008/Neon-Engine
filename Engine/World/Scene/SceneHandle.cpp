#include "stdafx.h"
#include "Scene.h"
#include "SceneHandle.h"
#include "NodeHandle.h"
#include "World/GameObjectHandle.h"
#include "World/World.h"

namespace Neon
{
	namespace World
	{
		NodeHandle SceneHandle::CreateNode(const std::string& name)
		{
			return mScene->GetRootNode().CreateChild(name);
		}

		NodeHandle SceneHandle::GetNode(const std::string& name)
		{
			return mScene->GetRootNode().GetChild(name);
		}
		
		void SceneHandle::DeleteNode(const std::string& name)
		{
			mScene->GetRootNode().DeleteChild(name);
		}
		
		void SceneHandle::Iterate(std::function<void(GameObjectHandle g)> lambda)
		{
			mScene->Iterate(lambda);
		}
		
		Component::ComponentMask& SceneHandle::GetGameObjectMask(GameObject obj)
		{
			return mScene->mGameObjectMasks[obj];
		}
	}
}
