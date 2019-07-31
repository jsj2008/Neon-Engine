#pragma once

#include "stdafx.h"
#include "Scene.h"
#include "Core/Config.h"
#include "World/Component/ComponentRef.h"
#include "World/GameObject.h"

namespace Neon
{
	namespace World
	{
		class SceneNodeRef;
		
		class NEON_API SceneNode
		{
		private:
			friend class Scene;
			friend class SceneManager;

		public:
			SceneNode(Scene* scene, const std::string& name);

			void SetParentNode(SceneNode* node) { mParent = node; }
			std::string& GetName() { return mName; }

			SceneNodeRef CreateChildNode(const std::string& name);
			void DeleteChildNode(const std::string& name);

			SceneNodeRef GetChildNode(const std::string& name);

			void IterateChildren(std::function<void(const SceneNodeRef& node)> func);

			template <typename ComponentType>
			void AddComponent(ComponentType c);

			template <typename ComponentType>
			void RemoveComponent();

			template <typename ComponentType>
			void SetComponent(ComponentType newc);

			template <typename ComponentType>
			Component::ComponentRef<ComponentType> GetComponent() const;

			SceneNode();

		private:
			SceneNode* mParent;
			Scene* mScene;

			Component::ComponentMask mGameObjectMask;
			std::string mName;

			std::unordered_map<std::string, std::unique_ptr<SceneNode>> mChildren;
		public:
			GameObject mGameObject;
		};

		template<typename ComponentType>
		inline void SceneNode::AddComponent(ComponentType c)
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			manager->AddComponent(mGameObject, c);
			mGameObjectMask.AddComponent<ComponentType>();
		}
		
		template<typename ComponentType>
		inline void SceneNode::RemoveComponent()
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			manager->RemoveComponent(mGameObject);

			mGameObjectMask.RemoveComponent<ComponentType>();
		}

		template<typename ComponentType>
		inline void SceneNode::SetComponent(ComponentType newc)
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			manager->SetComponent(mGameObject, newc);
		}
		
		template<typename ComponentType>
		inline Component::ComponentRef<ComponentType> SceneNode::GetComponent() const
		{
			Component::ComponentManager<ComponentType>* manager = mScene->GetComponentManager<ComponentType>();
			return Component::ComponentRef<ComponentType>(manager, mGameObject);
			
		}
	}
}

