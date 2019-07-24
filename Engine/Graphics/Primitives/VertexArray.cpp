#include "stdafx.h"
#include "VertexArray.h"
#include "Graphics/RendererAPI.h"
#include "Graphics/OpenGL/OpenGLVertexArray.h"
#include "Core/Log.h"

namespace Neon
{
	namespace Graphics
	{
		std::shared_ptr<VertexArray> VertexArray::Create()
		{
			switch (RendererAPI::m_RendererAPI)
			{
			case None: Log::Warn("No Graphics API set!"); break;
			case OpenGL: return std::make_shared<OpenGLVertexArray>();
			}

			return nullptr;
		}
	}
}
