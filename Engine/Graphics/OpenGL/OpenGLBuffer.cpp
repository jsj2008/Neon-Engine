#include "stdafx.h"
#include "OpenGLBuffer.h"
#include "Core/Log.h"

namespace Neon
{
	namespace Graphics
	{
		OpenGLVertexBuffer::OpenGLVertexBuffer(std::vector<float>& vertices)
		{
			m_Vertices = vertices;

			glGenBuffers(1, &m_VertexBufferID);
			glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_Vertices.size(), &m_Vertices[0], GL_STATIC_DRAW);
		}

		void OpenGLVertexBuffer::Bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
		}
		
		void OpenGLVertexBuffer::Unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		
		BufferLayout& OpenGLVertexBuffer::GetLayout()
		{
			return m_Layout;
		}
		
		void OpenGLVertexBuffer::SetLayout(BufferLayout& layout)
		{
			m_Layout = layout;
		}





		OpenGLIndexBuffer::OpenGLIndexBuffer(std::vector<unsigned int>& indices)
		{
			m_Indices = indices;
			m_Count = indices.size();

			glGenBuffers(1, &m_IndexBufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);
		}
		
		void OpenGLIndexBuffer::Bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		}

		void OpenGLIndexBuffer::Unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}
