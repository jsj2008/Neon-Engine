#include "stdafx.h"
#include "Scene.h"

#include "SceneNode.h"
#include "NodeHandle.h"
#include "World/GameObjectHandle.h"

namespace Neon
{
	namespace World
	{
		Scene::Scene(const std::string& name)
		{
			mName = name;
			mSceneNodes["Root"] = new SceneNode(this, "Root");
		}

		NodeHandle Scene::GetRootNode()
		{
			return NodeHandle(this, mSceneNodes["Root"]);
		}
		
		SceneNode* Scene::GetSceneNode(const std::string& name)
		{
			return mSceneNodes[name];
		}
		
		void Scene::Iterate(std::function<void(const GameObjectHandle& g)> lambda)
		{
			for (auto& pair : mSceneNodes)
			{
				if (pair.first != "Root")
				{
					GameObjectHandle handle = GameObjectHandle(pair.second, pair.second->mGameObject);
					lambda(handle);
				}
			}
		}
		
		Scene::~Scene()
		{
			for (auto& kv : mSceneNodes)
			{
				delete kv.second;
			}
		}
	}
}
