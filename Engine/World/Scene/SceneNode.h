#pragma once

#include "stdafx.h"
#include "Scene.h"
#include "Core/Config.h"
#include "World/Components/ComponentHandle.h"
#include "World/GameObject.h"

namespace Neon
{
	namespace World
	{
		class NEON_API SceneNode
		{
		private:
			friend class Scene;
			friend class GameObjectHandle;
			friend class NodeHandle;

		public:
			SceneNode(Scene* scene, const std::string& name);

			void SetParent(const std::string& name) { mParent = name; }

			void CreateChild(const std::string& name);
			void DeleteChild(const std::string& name);

			SceneNode* GetChild(const std::string& name);

			template <typename ComponentType>
			void AddComponent(ComponentType c);

			template <typename ComponentType>
			void RemoveComponent();

			template <typename ComponentType>
			void SetComponent(ComponentType newc);

			template <typename ComponentType>
			Component::ComponentHandle<ComponentType> GetComponent();

		private:
			std::string mParent;
			std::vector<std::string> mChildren;
			
			std::string mName;

			Scene* mScene;

		public:
			GameObject mGameObject;
		};
		
		template<typename ComponentType>
		inline void SceneNode::AddComponent(ComponentType c)
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			manager->AddComponent(mGameObject, c);
			mScene->mGameObjectMasks[mGameObject].AddComponent<ComponentType>();
		}
		
		template<typename ComponentType>
		inline void SceneNode::RemoveComponent()
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			manager->RemoveComponent(mGameObject);

			mScene->mGameObjectMasks[mGameObject].RemoveComponent<ComponentType>();
		}

		template<typename ComponentType>
		inline void SceneNode::SetComponent(ComponentType newc)
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			manager->SetComponent(mGameObject, newc);
		}
		
		template<typename ComponentType>
		inline Component::ComponentHandle<ComponentType> SceneNode::GetComponent()
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			return Component::ComponentHandle<ComponentType>(manager, mGameObject);
			
		}
	}
}

