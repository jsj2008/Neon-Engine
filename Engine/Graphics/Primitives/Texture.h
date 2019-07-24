#pragma once

#include "Core/Config.h"
#include "Graphics/RendererAPI.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API Texture
		{
		public:
			Texture() = default;

			virtual void Bind(unsigned int slot = 0) const = 0;
			virtual void Unbind() const = 0;

			virtual int GetWidth() const = 0;
			virtual int GetHeight() const = 0;

			static std::shared_ptr<Texture> Create(std::string& filepath);

			virtual ~Texture() {}
		};
	}
}