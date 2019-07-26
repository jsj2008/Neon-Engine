#pragma once

#include "Core/Config.h"
#include "Component.h"
#include "Graphics/Primitives/Buffer.h"
#include <memory>

namespace Neon
{
	namespace Component
	{
		class VertexBuffer;
		class IndexBuffer;
		
		class NEON_API MeshRenderer : public Component<MeshRenderer>
		{
		public:
			MeshRenderer(std::shared_ptr<VertexBuffer> buffer, std::shared_ptr<IndexBuffer> indexBuffer);

			std::shared_ptr<VertexBuffer> GetVertexBuffer() const { return mVertexBuffer; }
			std::shared_ptr<IndexBuffer> GetIndexBuffer() const { return mIndexBuffer; }

		private:
			std::shared_ptr<VertexBuffer> mVertexBuffer;
			std::shared_ptr<IndexBuffer> mIndexBuffer;

		};
	}
}

