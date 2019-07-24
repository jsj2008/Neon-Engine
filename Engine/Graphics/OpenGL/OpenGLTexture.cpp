#include "stdafx.h"
#include "OpenGLTexture.h"
#include "Core/Log.h"
#include "stb_image.h"

namespace Neon
{
	namespace Graphics
	{
		OpenGLTexture::OpenGLTexture(std::string& filepath) : m_Slot(0), 
			m_Width(0), m_Height(0), m_Channels(0)
		{
			stbi_set_flip_vertically_on_load(1);
			m_PixelBuffer = stbi_load(filepath.c_str(), &m_Width, &m_Height, &m_Channels, STBI_rgb_alpha);

			glGenTextures(1, &m_TextureID);
			glBindTexture(GL_TEXTURE_2D, m_TextureID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			if (m_PixelBuffer)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_PixelBuffer);
				glGenerateTextureMipmap(m_TextureID);
			}
			else
			{
				Log::Critical("Failed to load texture: " + filepath);
			}

			glBindTexture(GL_TEXTURE_2D, 0);
		}

		void OpenGLTexture::Bind(unsigned int slot) const
		{
			glActiveTexture(GL_TEXTURE0 + slot);
			glBindTexture(GL_TEXTURE_2D, m_TextureID);
		}

		void OpenGLTexture::Unbind() const
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}
		
		OpenGLTexture::~OpenGLTexture()
		{
			stbi_image_free(m_PixelBuffer);
			glDeleteTextures(1, &m_TextureID);
		}
	}
}