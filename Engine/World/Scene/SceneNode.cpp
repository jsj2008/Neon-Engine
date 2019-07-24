#include "stdafx.h"
#include "Core/Log.h"
#include "Node.h"
#include "World/GameObjectHandle.h"
#include "World/Components/ComponentMask.h"
#include "World/GameObjectManager.h"
#include "SceneNode.h"
#include "Scene.h"

namespace Neon
{
	namespace World
	{
		SceneNode::SceneNode(Scene* scene, const std::string& name) : mName(name)
		{
			mScene = scene;
			mID = mHasher(name);
			mGameObject = GameObjectManager::CreateGameObject();
			mScene->mGameObjectMasks[mGameObject] = Component::ComponentMask();
		}

		void SceneNode::CreateChild(const std::string& name)
		{
			NEON_ASSERT(mScene->mNodes.count(name) == 0);
			if (std::find(mChildren.begin(), mChildren.end(), mScene->mNodes[name].mID) == mChildren.end())
			{
				mScene->mNodes[name] = Node(mScene->mLastNode++);
				mScene->mSceneNodes[mScene->mNodes[name].mID] = std::make_shared<SceneNode>(mScene, name);
				mChildren.push_back(mScene->mNodes[name].mID);
			}
		}
		
		Node SceneNode::GetChild(const std::string& name)
		{
			NEON_ASSERT(mScene->mNodes.count(name) > 0);
			if (std::find(mChildren.begin(), mChildren.end(), mScene->mNodes[name].mID) != mChildren.end())
			{
				NEON_ASSERT(mScene->mSceneNodes[mScene->mNodes[name].mID] != nullptr);
				return mScene->mNodes[name];
			}
			else
			{
				Neon::Log::Warn("Attempted access to non existant or deleted node: " + name);
				NEON_ASSERT(false);
			}
			
		}

		GameObjectHandle SceneNode::GetGameObject()
		{
			GameObjectHandle handle(this, mGameObject);
			return handle;
		}

		void SceneNode::DestroyGameObject()
		{
			mScene->mGameObjectMasks.erase(mGameObject);
			mGameObject = GameObject(-1);
		}
		
		void SceneNode::DeleteChild(const std::string& name)
		{
			if (std::find(mChildren.begin(), mChildren.end(), mScene->mNodes[name].mID) != mChildren.end())
			{
				mScene->mSceneNodes[mScene->mNodes[name].mID].reset();
			}
		}
	}
}
