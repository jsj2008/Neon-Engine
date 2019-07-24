#include "stdafx.h"
#include "NodeHandle.h"
#include "World/GameObjectHandle.h"
#include "World/Scene/Scene.h"
#include "Core/Log.h"

namespace Neon
{
	namespace World
	{
		void NodeHandle::CreateChild(const std::string& name)
		{
			mScene->mSceneNodes[mSceneNode.mID]->CreateChild(name);
			mChildren.push_back(name);
		}

		NodeHandle NodeHandle::GetChild(const std::string& name)
		{
			Node childNode = mScene->mNodes.at(name);
			return NodeHandle(mScene, childNode);
		}
		
		void NodeHandle::DeleteChild(const std::string& name)
		{
			if (mScene->mNodes.count(name) > 0)
			{
				mScene->mSceneNodes.erase(mScene->mNodes[name].mID);
				mScene->mNodes.erase(name);
			}
		}
		
		GameObjectHandle NodeHandle::GetGameObject()
		{
			return mScene->mSceneNodes[mSceneNode.mID]->GetGameObject();
		}
	}
}
