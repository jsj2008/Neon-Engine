#pragma once

#include "Core/Config.h"
#include "BufferLayout.h"
#include "Graphics/RendererAPI.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API VertexBuffer
		{
		public:
			VertexBuffer() = default;
			VertexBuffer(std::vector<float>& vertices);

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual BufferLayout& GetLayout() = 0;
			virtual void SetLayout(BufferLayout& layout) = 0;

			virtual ~VertexBuffer() {}

			static std::shared_ptr<VertexBuffer> Create(std::vector<float>& vertices);
		};

		class NEON_API IndexBuffer
		{
		public:
			IndexBuffer() = default;
			IndexBuffer(std::vector<unsigned int>& indices);

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual int GetCount() const = 0;

			virtual ~IndexBuffer() {}

			static std::shared_ptr<IndexBuffer> Create(std::vector<unsigned int>& indices);
		};
	}
}