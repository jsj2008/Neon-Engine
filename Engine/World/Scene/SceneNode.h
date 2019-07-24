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
		class Scene;
		class GameObjectHandle;
		class Node;
		
		class NEON_API SceneNode
		{
		private:
			friend class Scene;
			friend class GameObjectHandle;

		public:
			SceneNode(Scene* scene, const std::string& name = "Root");

			size_t GetID() { return mID; }

			void CreateChild(const std::string& name);
			void DeleteChild(const std::string& name);

			Node GetChild(const std::string& name);

			GameObjectHandle GetGameObject();
			void DestroyGameObject();

			template <typename ComponentType>
			void AddComponent(ComponentType c);

			template <typename ComponentType>
			void RemoveComponent(ComponentType c);

			template <typename ComponentType>
			Component::ComponentHandle<ComponentType> GetComponent();

		private:
			std::hash<std::string> mHasher;

			std::shared_ptr<SceneNode> mParent;
			std::vector<int> mChildren;
			
			std::string mName;
			size_t mID = 0;

			Scene* mScene;

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
		inline void SceneNode::RemoveComponent(ComponentType c)
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			manager->RemoveComponent(mGameObject);

			mScene->mGameObjectMasks[mGameObject].RemoveComponent<ComponentType>();
		}
		
		template<typename ComponentType>
		inline Component::ComponentHandle<ComponentType> SceneNode::GetComponent()
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			return Component::ComponentHandle<ComponentType>(manager, mGameObject);
		}
	}
}

