#include "stdafx.h"
#include "MeshRenderer.h"

namespace Neon
{
	namespace Component
	{
		MeshRenderer::MeshRenderer(std::shared_ptr<VertexBuffer> buffer, std::shared_ptr<IndexBuffer> indexBuffer)
		{
			mVertexBuffer = buffer;
			mIndexBuffer = indexBuffer;
		}
	}
}
