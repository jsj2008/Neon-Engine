#include "stdafx.h"
#include "Scene/Scene.h"
#include "Scene/SceneHandle.h"
#include "World.h"

namespace Neon
{
	namespace World
	{
		World::World(const std::string& name)
		{
			mName = name;
			mID = std::hash<std::string>()(mName);

			mSceneManager = new SceneManager();
		}
		
		void World::CreateScene(const std::string& name)
		{
			mSceneManager->CreateScene(name);
		}
		
		SceneHandle World::GetScene(const std::string& name)
		{
			SceneHandle handle(this, mSceneManager->GetScene(name));
			return handle;
		}
	}
}
