#pragma once

#include "Core/Config.h"
#include "GameObject.h"

namespace Neon
{
	namespace World
	{
		class NEON_API GameObjectManager
		{
		public:
			GameObjectManager() = default;

			static GameObject CreateGameObject()
			{
				GameObject mGameObject;
				mGameObject.mID = mGameObjectCounter++;
				return mGameObject;
			}

			~GameObjectManager() = default;

		private:
			static int mGameObjectCounter;
		};
	}
}