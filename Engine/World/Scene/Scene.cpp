#include "stdafx.h"
#include "SceneNode.h"
#include "Scene.h"
#include "World/GameObject.h"

namespace Neon
{
	namespace World
	{
		Scene::Scene(const std::string& name)
		{
			std::hash<std::string> hasher;
			
			mName = name;
			mID = hasher(name);

			mRootNode = Node(mLastNode++);
			mSceneNodes[mRootNode.mID] = std::make_shared<SceneNode>(this, "Root");
			mNodes["Root"] = mRootNode;
		}
		
		void Scene::CreateNode(const std::string& name)
		{
			Node mChild(mLastNode++);
			mRootNode.mChildrenIDs.push_back(mChild.mID);
			mSceneNodes[mChild.mID] = std::make_shared<SceneNode>(this, name);
			mNodes[name] = mChild;
		}

		void Scene::DeleteNode(const std::string& name)
		{
			mRootNode.mChildrenIDs.erase(std::find(mRootNode.mChildrenIDs.begin(), mRootNode.mChildrenIDs.end(), mNodes[name].mID));
		}
		
		Node Scene::GetNode(const std::string& name)
		{
			NEON_ASSERT(mNodes.count(name) > 0);
			NEON_ASSERT(std::find(mRootNode.mChildrenIDs.begin(), mRootNode.mChildrenIDs.end(), mNodes[name].mID) != mRootNode.mChildrenIDs.end());

			return mNodes[name];
		}
	}
}
