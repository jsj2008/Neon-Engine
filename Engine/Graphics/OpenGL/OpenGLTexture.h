#pragma once

#include "Core/Config.h"
#include "Graphics/Primitives/Texture.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API OpenGLTexture : public Texture
		{
		public:
			OpenGLTexture(std::string& filepath);

			void Bind(unsigned int slot = 0) const override;
			void Unbind() const override;

			int GetWidth() const override { return m_Width; }
			int GetHeight() const override { return m_Height; }

			~OpenGLTexture();

		private:
			unsigned int m_TextureID;
			unsigned int m_Slot;

			unsigned char* m_PixelBuffer;
			int m_Width, m_Height, m_Channels;
		};
	}
}