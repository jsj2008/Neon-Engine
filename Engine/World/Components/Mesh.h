#pragma once

#include "Core/Config.h"
#include "World/Component/Component.h"

#include "Graphics/Primitives/BufferLayout.h"
#include "Graphics/Primitives/Buffer.h"
#include "Graphics/Primitives/VertexArray.h"

namespace Neon
{
	namespace Component
	{
		class NEON_API Mesh : public Component<Mesh>
		{
		public:
			Mesh() = default;
			Mesh(std::vector<float>& vertices, std::vector<unsigned int>& indices, Graphics::BufferLayout& layout);

			std::shared_ptr<Graphics::VertexArray>& GetVertexArray() { return mVertexArray; }

		private:
			std::shared_ptr<Graphics::VertexBuffer> mBuffer;
			std::shared_ptr<Graphics::IndexBuffer> mIndexBuffer;
			std::shared_ptr<Graphics::VertexArray> mVertexArray;
		};
	}
}

