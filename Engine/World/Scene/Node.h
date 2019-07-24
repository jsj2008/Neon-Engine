#pragma once

#include "Core/Config.h"
#include <vector>

namespace Neon
{
	namespace World
	{
		class NEON_API Node
		{
		public:
			Node() = default;
			Node(unsigned int id) :mID(id) { mChildrenIDs = std::vector<int>(); }

		public:
			unsigned int mID;
			std::vector<int> mChildrenIDs;
		};
	}
}