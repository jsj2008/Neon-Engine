#include "stdafx.h"
#include "NodeHandle.h"
#include "World/GameObjectHandle.h"
#include "World/Scene/Scene.h"
#include "Core/Log.h"

namespace Neon
{
	namespace World
	{
		NodeHandle NodeHandle::CreateChild(const std::string& name)
		{
			mScene->mSceneNodes[mSceneNode->mName]->CreateChild(name);
			return this->GetChild(name);
		}

		NodeHandle NodeHandle::GetChild(const std::string& name)
		{
			return NodeHandle(mScene, mSceneNode->GetChild(name));
		}
		
		void NodeHandle::DeleteChild(const std::string& name)
		{
			if (mScene->mSceneNodes.count(name) > 0)
			{
				delete mScene->mSceneNodes[name];
				mScene->mSceneNodes.erase(name);
			}
		}
		
		GameObjectHandle NodeHandle::GetGameObject()
		{
			return GameObjectHandle(mSceneNode, mSceneNode->mGameObject);
		}
	}
}
