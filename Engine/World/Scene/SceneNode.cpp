#include "stdafx.h"
#include "Core/Log.h"
#include "World/Components/ComponentMask.h"
#include "World/GameObjectManager.h"
#include "World/Components/Transform.h"
#include "SceneNode.h"

#include "SceneNodeRef.h"

namespace Neon
{
	namespace World
	{
		SceneNode::SceneNode(Scene* scene, const std::string& name) : mName(name)
		{
			mGameObject = GameObjectManager::CreateGameObject();
			mScene = scene;

			Component::Transform mTransform(glm::vec3(0.0f, 0.0f, 0.0f));
			this->AddComponent<Component::Transform>(mTransform);
		}

		SceneNodeRef SceneNode::CreateChildNode(const std::string& name)
		{
			if (mChildren.count(name) == 0)
			{
				mChildren[name] = std::make_unique<SceneNode>(mScene, name);
				mChildren[name]->SetParentNode(this);

				return SceneNodeRef(mChildren[name].get());
			}
			else
			{
				Neon::Log::Warn("Child with name: " + name + " already exists!");
			}
		}
		
		SceneNodeRef SceneNode::GetChildNode(const std::string& name)
		{
			if (mChildren.count(name) > 0)
			{
				NEON_ASSERT(mChildren[name] != nullptr);
				return SceneNodeRef(mChildren[name].get());
			}
			else
			{
				Neon::Log::Warn("Attempted access to non existant or deleted node: " + name);
				NEON_ASSERT(false);
			}
			
		}

		void SceneNode::IterateChildren(std::function<void(const SceneNodeRef& node)> func)
		{
			for (const auto& child : mChildren)
			{
				child.second->IterateChildren(func);
			}

			auto ref = SceneNodeRef(this);

			func(ref);
		}

		SceneNode::SceneNode() = default;

		void SceneNode::DeleteChildNode(const std::string& name)
		{
			if (mChildren.count(name) > 0)
			{
				mChildren[name].reset();
				mChildren.erase(name);
			}
		}
	}
}
