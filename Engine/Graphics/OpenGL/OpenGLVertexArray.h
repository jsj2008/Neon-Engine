#pragma once

#include "Core/Config.h"
#include "Graphics/Primitives/VertexArray.h"
#include "Graphics/Primitives/Buffer.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API OpenGLVertexArray : public VertexArray
		{
		public:
			OpenGLVertexArray();

			void Bind() const override;
			void Unbind() const override;

			std::shared_ptr<VertexBuffer> GetVertexBuffer() override { return m_pVertexBuffer; }
			std::shared_ptr<IndexBuffer> GetIndexBuffer() override { return m_pIndexBuffer; }

			void AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer) override;
			void AddIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer) override;

			~OpenGLVertexArray();

		private:
			unsigned int m_VertexArrayID;

			std::shared_ptr<VertexBuffer> m_pVertexBuffer;
			std::shared_ptr<IndexBuffer> m_pIndexBuffer;
		};
	}
}