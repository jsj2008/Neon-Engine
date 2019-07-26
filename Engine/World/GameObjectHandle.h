#pragma once

#include "Core/Config.h"
#include "GameObject.h"
#include "Components/ComponentHandle.h"
#include "Scene/SceneNode.h"

namespace Neon
{
	namespace World
	{
		class NEON_API GameObjectHandle
		{
		private:
			friend class SceneNode;
		public:
			GameObjectHandle() = default;
			GameObjectHandle(SceneNode* node, GameObject obj) : mSceneNode(node), mGameObject(obj) {}

			template <typename ComponentType>
			void AddComponent(ComponentType c);

			template <typename ComponentType>
			void RemoveComponent(ComponentType c);

			template <typename ComponentType>
			Component::ComponentHandle<ComponentType> GetComponent();

			template <typename ComponentType>
			void SetComponent(ComponentType newC);

		private:
			SceneNode* mSceneNode;
			GameObject mGameObject;
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
		
		template<typename ComponentType>
		inline void GameObjectHandle::SetComponent(ComponentType newC)
		{
			mSceneNode->SetComponent(newC);
		}
	}
}