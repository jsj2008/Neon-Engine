#pragma once

#include "Core/Config.h"
#include <vector>

namespace Neon
{
	namespace World
	{
		class NEON_API GameObject
		{
		public:
			GameObject() = default;
			GameObject(std::size_t id) : mID(id) {}

		public:
			std::size_t mID;

			friend bool operator < (const GameObject& l, const GameObject& r) { return l.mID < r.mID; }
		};
	}
}