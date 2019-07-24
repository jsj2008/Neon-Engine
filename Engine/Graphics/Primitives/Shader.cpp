#include "stdafx.h"
#include "Shader.h"
#include "Graphics/RendererAPI.h"
#include "Graphics/OpenGL/OpenGLShader.h"
#include "Core/Log.h"

namespace Neon
{
	namespace Graphics
	{
		std::shared_ptr<Shader> Shader::Create(std::string vertexPath, std::string pixelPath)
		{
			switch (RendererAPI::m_RendererAPI)
			{
			case GraphicsAPI::None: Log::Warn("No Graphics API set!");
			case GraphicsAPI::OpenGL: return std::make_shared<OpenGLShader>(vertexPath, pixelPath);
			}
		}
	}
}
