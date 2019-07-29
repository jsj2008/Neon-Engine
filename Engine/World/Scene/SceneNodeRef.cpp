#include "stdafx.h"
#include "SceneNodeRef.h"
#include "SceneNode.h"

namespace Neon
{
	namespace World
	{
		SceneNode* Neon::World::SceneNodeRef::operator->() const
		{
			NEON_ASSERT(mOwner != NULL);

			return mOwner;
		}
	}
}
