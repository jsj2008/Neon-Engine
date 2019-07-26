#include "stdafx.h"
#include "Core/Log.h"
#include "World/GameObjectHandle.h"
#include "World/Components/ComponentMask.h"
#include "World/GameObjectManager.h"
#include "World/Components/Transform.h"
#include "SceneNode.h"

namespace Neon
{
	namespace World
	{
		SceneNode::SceneNode(Scene* scene, const std::string& name) : mName(name), mScene(scene)
		{
			mGameObject = GameObjectManager::CreateGameObject();
			
			Component::ComponentMask mComponentMask;
			mScene->mGameObjectMasks[mGameObject] = mComponentMask;

			Component::Transform mTransform(glm::vec3(0.0f, 0.0f, 0.0f));
			this->AddComponent<Component::Transform>(mTransform);
		}

		void SceneNode::CreateChild(const std::string& name)
		{
			NEON_ASSERT(mScene->mSceneNodes.count(name) == 0);
			
			mScene->mSceneNodes[name] = new SceneNode(mScene, name);
			mChildren.push_back(name);
		}
		
		SceneNode* SceneNode::GetChild(const std::string& name)
		{
			NEON_ASSERT(mScene->mSceneNodes.count(name) > 0);
			if (std::find(mChildren.begin(), mChildren.end(), name) != mChildren.end())
			{
				NEON_ASSERT(mScene->mSceneNodes[name] != nullptr);
				return mScene->mSceneNodes[name];
			}
			else
			{
				Neon::Log::Warn("Attempted access to non existant or deleted node: " + name);
				NEON_ASSERT(false);
			}
			
		}

		void SceneNode::DeleteChild(const std::string& name)
		{
			if (std::find(mChildren.begin(), mChildren.end(), name) != mChildren.end())
			{
				delete mScene->mSceneNodes[name];
				mScene->mSceneNodes.erase(name);
			}
		}
	}
}
