#pragma once

#include "Core/Config.h"
#include "Scene/SceneNode.h"
#include "GameObject.h"
#include "Components/ComponentHandle.h"

namespace Neon
{
	namespace World
	{
		class SceneNode;

		class NEON_API GameObjectHandle
		{
		public:
			GameObjectHandle(SceneNode* node, GameObject obj) : mSceneNode(node), mGameObejct(obj) {}

			void Destroy();

			template <typename ComponentType>
			void AddComponent(ComponentType c);

			template <typename ComponentType>
			void RemoveComponent(ComponentType c);

			template <typename ComponentType>
			Component::ComponentHandle<ComponentType> GetComponent();

		private:
			SceneNode* mSceneNode;
			GameObject mGameObejct;
		};
		
		template<typename ComponentType>
		inline void GameObjectHandle::AddComponent(ComponentType c)
		{
			mSceneNode->AddComponent<ComponentType>(c);
		}
		
		template<typename ComponentType>
		inline void GameObjectHandle::RemoveComponent(ComponentType c)
		{
			mSceneNode->RemoveComponent<ComponentType>(c);
		}
		
		template<typename ComponentType>
		inline Component::ComponentHandle<ComponentType> GameObjectHandle::GetComponent()
		{
			NEON_ASSERT(Component::Component<ComponentType>::family() < mSceneNode->mScene->mComponentManagers.size());
			return mSceneNode->GetComponent<ComponentType>();
		}
	}
}