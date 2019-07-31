#pragma once

#include "Core/Config.h"
#include <unordered_map>
#include "World/GameObject.h"
#include <functional>

namespace Neon
{
	namespace Component
	{
		template <typename ComponentType>
		struct NEON_API ComponentData
		{
			unsigned int mSize = 1;
			std::array<ComponentType, MAX_COMPONENTS> mData;
		};

		// Simple unsinged int (syntaxical sugar) that refers to the index of a component in the componentData array
		typedef unsigned int ComponentInstance;

		class BaseComponentManager 
		{
		public:
			BaseComponentManager() = default;
			virtual ~BaseComponentManager() = default;
			
			BaseComponentManager(const BaseComponentManager&) = default;
			BaseComponentManager& operator=(const BaseComponentManager&) = default;
			
			BaseComponentManager(BaseComponentManager&&) = default;
			BaseComponentManager& operator=(BaseComponentManager&&) = default;
		};

		template<typename ComponentType>
		class NEON_API ComponentManager : public BaseComponentManager
		{
		public:
			using Type = typename ComponentType;

		public:
			ComponentInstance AddComponent(World::GameObject obj, ComponentType& c);

			ComponentType* GetComponent(World::GameObject obj);

			void SetComponent(World::GameObject e, ComponentType newc);
			void RemoveComponent(World::GameObject e);

			void Iterate(std::function<void(ComponentType& c)> lambda);

		private:
			ComponentData<ComponentType> mComponentData;
			
			std::map<World::GameObject, ComponentInstance> mGameObjectMap;
			std::unordered_map<ComponentInstance, World::GameObject> mInstanceMap;
		};
		
		template<typename ComponentType>
		inline ComponentInstance ComponentManager<ComponentType>::AddComponent(World::GameObject obj, ComponentType& component)
		{
			ComponentInstance instance = mComponentData.mSize;
			mComponentData.mData[instance] = component;
			
			mGameObjectMap[obj] = instance;
			mInstanceMap[instance] = obj;
			
			mComponentData.mSize++;
			return instance;
		}
		
		template<typename ComponentType>
		inline ComponentType* ComponentManager<ComponentType>::GetComponent(World::GameObject obj)
		{
			ComponentInstance inst = mGameObjectMap[obj];
			
			return &mComponentData.mData[inst];
		
		}
		
		template<typename ComponentType>
		inline void ComponentManager<ComponentType>::SetComponent(World::GameObject e, ComponentType newc)
		{
			ComponentInstance inst = mGameObjectMap[e];
			mComponentData.mData[inst] = newc;
		}

		template<typename ComponentType>
		inline void ComponentManager<ComponentType>::RemoveComponent(World::GameObject obj)
		{
			ComponentInstance inst = mGameObjectMap[obj];
			ComponentInstance lastComponent = mComponentData.mSize - 1;
			mComponentData[inst] = mComponentData.data[lastComponent];
			mGameObjectMap.erase(obj);
			mComponentData.mSize--;

			mGameObjectMap[mInstanceMap[lastComponent]] = inst;
		}
		
		template<typename ComponentType>
		inline void ComponentManager<ComponentType>::Iterate(std::function<void(ComponentType& c)> lambda)
		{
			for (int i = 1; i < mComponentData.mSize; i++)
			{
				lambda(mComponentData.mData[i]);
			}
		}
	}
}