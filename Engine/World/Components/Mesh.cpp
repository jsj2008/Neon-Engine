#include "stdafx.h"
#include "Mesh.h"

namespace Neon
{
	namespace Component
	{
		Mesh::Mesh(std::vector<float>& vertices, std::vector<unsigned int>& indices, Graphics::BufferLayout& layout)
		{
			mBuffer = Graphics::VertexBuffer::Create(vertices);
			mBuffer->SetLayout(layout);

			mIndexBuffer = Graphics::IndexBuffer::Create(indices);

			mVertexArray = Graphics::VertexArray::Create();

			mVertexArray->AddVertexBuffer(mBuffer);
			mVertexArray->AddIndexBuffer(mIndexBuffer);

			mVertexArray->Unbind();
		}
	}
}
