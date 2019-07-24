#include "stdafx.h"
#include "RendererAPI.h"
#include "OpenGL/OpenGLRendererAPI.h"
#include "Core/Log.h"

namespace Neon
{
	namespace Graphics
	{
		GraphicsAPI RendererAPI::m_RendererAPI = GraphicsAPI::OpenGL;
		
		std::shared_ptr<RendererAPI> RendererAPI::Create()
		{
			switch (m_RendererAPI)
			{
			case None: Log::Warn("No Graphics API set!"); break;
			case OpenGL: return std::make_shared<OpenGLRendererAPI>();
			}

			return nullptr;
		}
	}
}