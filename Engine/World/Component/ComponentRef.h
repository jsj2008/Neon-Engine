#pragma once

#include "Core/Config.h"
#include "Component.h"
#include "ComponentManager.h"
#include "World/GameObject.h"

namespace Neon
{
	namespace Component
	{
		typedef unsigned int ComponentInstance;
		
		template <typename ComponentType>
		class NEON_API ComponentRef
		{
		public:
			using ExposedType = typename ComponentManager<ComponentType>::Type;
		public:
			ComponentRef(ComponentManager<ComponentType>* manager, World::GameObject obj);

			void Destroy();

			ExposedType* operator ->() const { return mManager->GetComponent(mOwner); }

		private:
			ComponentManager<ComponentType>* mManager;
			World::GameObject mOwner;
			
		};
		
		template<typename ComponentType>
		inline ComponentRef<ComponentType>::ComponentRef(ComponentManager<ComponentType>* manager, World::GameObject obj)
		{
			mManager = manager;
			mOwner = obj;
		}
		
		template<typename ComponentType>
		inline void ComponentRef<ComponentType>::Destroy()
		{
			mManager->Destroy(mOwner);
		}
	}
}