#pragma once

#include "stdafx.h"
#include "Core/Config.h"
#include "World/Components/ComponentManager.h"
#include "World/Components/Component.h"
#include "World/GameObject.h"
#include "Node.h"
#include "World/Components/ComponentMask.h"

namespace Neon
{
	namespace World
	{
		class SceneNode;

		class NEON_API Scene
		{
		private:
			friend class NodeHandle; 
			friend class SceneHandle;
			friend class SceneNode;

		public:
			std::vector<std::unique_ptr<Component::BaseComponentManager>> mComponentManagers;
			std::map<GameObject, Component::ComponentMask> mGameObjectMasks;
			
			std::unordered_map<int, std::shared_ptr<SceneNode>> mSceneNodes;
			std::unordered_map<std::string, Node> mNodes;

			Node mRootNode;
			std::string mName;

			std::hash<std::string> mHasher;
			int mID;

			int mLastNode = 0;

		public:
			Scene(const std::string& name);

			int GetID() { return mID; }

			void CreateNode(const std::string& name);
			void DeleteNode(const std::string& name);
			
			Node GetNode(const std::string& name);

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

