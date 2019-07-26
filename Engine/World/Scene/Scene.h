#pragma once

#include "stdafx.h"
#include "Core/Config.h"
#include "World/Components/ComponentManager.h"
#include "World/Components/Component.h"
#include "World/Components/ComponentMask.h"

namespace Neon
{
	namespace World
	{
		class SceneNode;
		class GameObjectHandle;
		class NodeHandle;

		class NEON_API Scene
		{
		private:
			friend class NodeHandle; 
			friend class SceneHandle;
			friend class SceneNode;

		public:
			std::vector<std::unique_ptr<Component::BaseComponentManager>> mComponentManagers;

			std::map<GameObject, Component::ComponentMask> mGameObjectMasks;
			std::unordered_map<std::string, SceneNode*> mSceneNodes;

			std::string mName;
		public:
			Scene(const std::string& name);

			NodeHandle GetRootNode();
			
			void Iterate(std::function<void(GameObjectHandle g)> lambda);

			~Scene();

		private:
			SceneNode* GetSceneNode(const std::string& name);

			template <typename ComponentType>
			Component::ComponentManager<ComponentType>* GetComponentManager();
			
		};
		
		
		template<typename ComponentType>
		inline Component::ComponentManager<ComponentType>* Scene::GetComponentManager()
		{
			int family = Component::GetComponentFamily<ComponentType>();

			if (family >= mComponentManagers.size())
			{
				mComponentManagers.push_back(std::make_unique<Component::ComponentManager<ComponentType>>());
				return static_cast<Component::ComponentManager<ComponentType>*>(mComponentManagers[family].get());
			}

			if (!mComponentManagers[family])
			{
				mComponentManagers[family] = std::make_unique<Component::ComponentManager<ComponentType>>();
				return static_cast<Component::ComponentManager<ComponentType>*>(mComponentManagers[family].get());
			}

			return static_cast<Component::ComponentManager<ComponentType>*>(mComponentManagers[family].get());
		}

	}
}

