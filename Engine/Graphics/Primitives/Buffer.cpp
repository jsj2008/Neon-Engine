#include "stdafx.h"
#include "Buffer.h"
#include "Core/Log.h"
#include "Graphics/OpenGL/OpenGLBuffer.h"

namespace Neon
{
	namespace Graphics
	{
		std::shared_ptr<VertexBuffer> VertexBuffer::Create(std::vector<float>& vertices)
		{
			switch (RendererAPI::m_RendererAPI)
			{
			case None: Log::Warn("No Graphics API set!"); break;
			case OpenGL: return std::make_shared<OpenGLVertexBuffer>(vertices); 
			}
		}
		
		std::shared_ptr<IndexBuffer> IndexBuffer::Create(std::vector<unsigned int>& indices)
		{
			switch (RendererAPI::m_RendererAPI)
			{
			case None: Log::Warn("No Graphics API set!"); break;
			case OpenGL: return std::make_shared<OpenGLIndexBuffer>(indices);
			}
		}
	}
}
