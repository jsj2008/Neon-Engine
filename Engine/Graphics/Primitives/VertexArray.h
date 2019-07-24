#pragma once

#include "Buffer.h"
#include "Core/Config.h"

#include "memory.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API VertexArray
		{
		public:
			VertexArray() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual std::shared_ptr<VertexBuffer> GetVertexBuffer() = 0;
			virtual std::shared_ptr<IndexBuffer> GetIndexBuffer() = 0;

			virtual void AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
			virtual void AddIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

			static std::shared_ptr<VertexArray> Create();

			virtual ~VertexArray() {}
		};
	}
}