#pragma once

#include "stdafx.h"
#include "Core/Config.h"
#include "World/Component/ComponentManager.h"
#include "World/Component/Component.h"
#include "World/Component/ComponentMask.h"

namespace Neon
{
	namespace World
	{
		class SceneNodeRef;
		class SceneNode;

		class NEON_API Scene
		{
		private:
			friend class SceneNode;
			friend class SceneManager;

		private:
			std::vector<std::unique_ptr<Component::BaseComponentManager>> mComponentManagers;
			
			std::unique_ptr<SceneNode> mRootNode;
			std::string mName;
		
		public:
			Scene(const std::string& name);

			SceneNodeRef GetRootNode();
			
			void IterateSceneNodes(std::function<void(const SceneNodeRef& node)> lambda);

			~Scene();

		private:
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

