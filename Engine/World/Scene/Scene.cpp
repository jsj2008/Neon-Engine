#include "stdafx.h"
#include "Scene.h"
#include "SceneNode.h"
#include "SceneNodeRef.h"

namespace Neon
{
	namespace World
	{
		Scene::Scene(const std::string& name)
		{
			mName = name;
			mRootNode = std::make_unique<SceneNode>(this, "Root");
		}

		SceneNodeRef Scene::GetRootNode()
		{
			return SceneNodeRef(mRootNode.get());
		}
		
		void Scene::IterateSceneNodes(std::function<void(const SceneNodeRef& node)> func)
		{
			mRootNode->IterateChildren(func);
		}
		
		Scene::~Scene() = default;
	}
}
