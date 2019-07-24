#include "stdafx.h"
#include "SceneHandle.h"
#include "NodeHandle.h"
#include "World/World.h"

namespace Neon
{
	namespace World
	{
		void SceneHandle::CreateNode(const std::string& name)
		{
			mScene->CreateNode(name);
		}

		NodeHandle SceneHandle::GetNode(const std::string& name)
		{
			NodeHandle handle(mScene, mScene->GetNode(name));
			return handle;
		}
		
		void SceneHandle::DeleteNode(const std::string& name)
		{
			mScene->DeleteNode(name);
		}
	}
}
