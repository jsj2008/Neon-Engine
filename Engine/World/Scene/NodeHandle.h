#pragma once

#include "Core/Config.h"
#include "SceneNode.h"
#include "Node.h"

namespace Neon
{
	namespace World
	{
		class Scene;
		class GameObjectHandle;

		class NEON_API NodeHandle
		{
		public:
			NodeHandle() = default;
			NodeHandle(Scene* scene, Node node) : mSceneNode(node), mScene(scene) {}

			void CreateChild(const std::string& name);

			NodeHandle GetChild(const std::string& name);
			void DeleteChild(const std::string& name);

			GameObjectHandle GetGameObject();

		public:
			std::vector<std::string> mChildren;

			Node mSceneNode;
			Scene* mScene;
		};
	}
}