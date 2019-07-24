#pragma once

#include "Core/Config.h"
#include "Scene.h"

namespace Neon
{
	namespace World
	{
		class World;
		class NodeHandle;

		class NEON_API SceneHandle
		{
		public:
			SceneHandle(World* world, Scene* scene) : mScene(scene), mWorld(world) {}
			
			void CreateNode(const std::string& name);

			NodeHandle GetNode(const std::string& name);
			void DeleteNode(const std::string& name);



		public:
			Scene* mScene;
			World* mWorld;
		};
	}
}