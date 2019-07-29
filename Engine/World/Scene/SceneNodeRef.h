#pragma once

#include "Core/Config.h"

namespace Neon
{
	namespace World
	{
		class SceneNode;
		
		class NEON_API SceneNodeRef
		{
		public:
			SceneNodeRef() = default;
			SceneNodeRef(SceneNode* owner) : mOwner(owner) {}

			SceneNode* operator -> () const;

		private:
			SceneNode* mOwner;
		};
	}
}