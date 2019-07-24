#include "stdafx.h"
#include "Scene/Scene.h"
#include "GameObjectHandle.h"

namespace Neon
{
	namespace World
	{
		void GameObjectHandle::Destroy()
		{
			mSceneNode->DestroyGameObject();
		}
	}
}
