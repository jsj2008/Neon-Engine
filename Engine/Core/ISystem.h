#pragma once

#include "Config.h"
#include "World/GameObject.h"
#include "World/Components/Component.h"
#include <bitset>

namespace Neon 
{
	namespace System
	{
		class World::Scene;

		class NEON_API System
		{
		public:
			virtual void Init() = 0;

			virtual void Update() = 0;
			virtual void Render() = 0;

			virtual void RegisterGameObject(World::GameObject obj) = 0;
			virtual void UnregisterGameObject(World::GameObject obj) = 0;

			virtual ~System() = default;

		protected:
			std::bitset<32> mSystemSignature;

			std::vector<World::GameObject> mGameobjects;
			World::Scene* mScene;
		};
		
	}
}