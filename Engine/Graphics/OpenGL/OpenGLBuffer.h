#pragma once

#include "Core/Config.h"
#include "Graphics/Primitives/Buffer.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API OpenGLVertexBuffer : public VertexBuffer
		{
		public:
			OpenGLVertexBuffer() = default;
			OpenGLVertexBuffer(std::vector<float>& vertices);

			void Bind() const override;
			void Unbind() const override;

			BufferLayout& GetLayout() override;
			void SetLayout(BufferLayout& layout) override;

			~OpenGLVertexBuffer() { /*glDeleteBuffers(GL_ARRAY_BUFFER, &m_VertexBufferID);*/ }

		private:
			unsigned int m_VertexBufferID;

			std::vector<float> m_Vertices;
			BufferLayout m_Layout;
		};

		class NEON_API OpenGLIndexBuffer : public IndexBuffer
		{
		public:
			OpenGLIndexBuffer() = default;
			OpenGLIndexBuffer(std::vector<unsigned int>& indices);

			void Bind() const override;
			void Unbind() const override;

			int GetCount() const override { return m_Count; }

			~OpenGLIndexBuffer() { /*glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_IndexBufferID);*/ }

		private:
			std::vector<unsigned int> m_Indices;

			unsigned int m_IndexBufferID = 0;
			int m_Count;
		};
	}
}