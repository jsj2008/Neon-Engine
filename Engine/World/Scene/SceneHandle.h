#pragma once

#include "Core/Config.h"
#include "World/GameObjectHandle.h"
#include "World/Components/ComponentMask.h"
#include "World/GameObject.h"

namespace Neon
{
	namespace World
	{
		class World;
		class Scene;
		class NodeHandle;
		class GameObjectHandle;

		class NEON_API SceneHandle
		{
		private:
			friend class SceneNode;

		public:
			SceneHandle(World* world, Scene* scene) : mScene(scene), mWorld(world) {}
			
			NodeHandle CreateNode(const std::string& name);
			NodeHandle GetNode(const std::string& name);
			
			void DeleteNode(const std::string& name);
			void Iterate(std::function<void(const GameObjectHandle& g)> lambda) const;

		private:
			Component::ComponentMask& GetGameObjectMask(GameObject obj);

		private:
			Scene* mScene;
			World* mWorld;
		};
	}
}