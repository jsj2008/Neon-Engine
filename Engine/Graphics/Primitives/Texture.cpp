#include "stdafx.h"
#include "Texture.h"
#include "Core/Log.h"
#include "Graphics/OpenGL/OpenGLTexture.h"

namespace Neon
{
	namespace Graphics
	{
		std::shared_ptr<Texture> Texture::Create(std::string& filepath)
		{
			switch (RendererAPI::m_RendererAPI)
			{
			case None: Log::Warn("Graphics API not set!"); break;
			case OpenGL: return std::shared_ptr<OpenGLTexture>(new OpenGLTexture(filepath));
			}
		}
	}
}
