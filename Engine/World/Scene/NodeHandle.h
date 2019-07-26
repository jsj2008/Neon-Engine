#pragma once

#include "Core/Config.h"
#include "SceneNode.h"

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
			NodeHandle(Scene* scene, SceneNode* node) : mSceneNode(node), mScene(scene) {}

			NodeHandle CreateChild(const std::string& name);

			NodeHandle GetChild(const std::string& name);
			void DeleteChild(const std::string& name);

			GameObjectHandle GetGameObject();

		public:
			SceneNode* mSceneNode;
			Scene* mScene;
		};
	}
}