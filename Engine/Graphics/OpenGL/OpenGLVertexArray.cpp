#include "stdafx.h"
#include "Core/Log.h"
#include "OpenGLVertexArray.h"

namespace Neon
{
	namespace Graphics
	{
		OpenGLVertexArray::OpenGLVertexArray()
		{
			glGenVertexArrays(1, &m_VertexArrayID);
			glBindVertexArray(m_VertexArrayID);
		}

		void OpenGLVertexArray::Bind() const
		{
			glBindVertexArray(m_VertexArrayID);
		}

		void OpenGLVertexArray::Unbind() const
		{
			glBindVertexArray(0);
		}

		void OpenGLVertexArray::AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer)
		{
			m_pVertexBuffer = vertexBuffer;

			m_pVertexBuffer->Bind();
			for (int i = 0; i < m_pVertexBuffer->GetLayout().GetElements().size(); i++)
			{
				//Log::Trace(std::to_string(i) + " " + std::to_string(m_pVertexBuffer->GetLayout().GetElements()[i].GetSize()) + " GL_FLOAT " + std::to_string(m_pVertexBuffer->GetLayout().GetStride()) + " * sizeof(float) (void*)(" + std::to_string(m_pVertexBuffer->GetLayout().GetElements()[i].offset) + " * sizeof(float)");
				glVertexAttribPointer(i,
									   m_pVertexBuffer->GetLayout().GetElements().at(i).GetSize(),
									   GL_FLOAT,
									   m_pVertexBuffer->GetLayout().GetElements().at(i).m_normalised,
									   m_pVertexBuffer->GetLayout().GetStride() * sizeof(float),
									   (void*)(m_pVertexBuffer->GetLayout().GetElements().at(i).offset * sizeof(float))
				);

				glEnableVertexAttribArray(i);
			}
		}

		void OpenGLVertexArray::AddIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer)
		{
			m_pIndexBuffer = indexBuffer;
			m_pIndexBuffer->Bind();
		}
		
		OpenGLVertexArray::~OpenGLVertexArray()
		{
			glDeleteVertexArrays(1, &m_VertexArrayID);
		}
	}
}