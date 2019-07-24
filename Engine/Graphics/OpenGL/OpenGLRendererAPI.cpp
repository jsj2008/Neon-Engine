#include "stdafx.h"
#include "OpenGLRendererAPI.h"

namespace Neon
{
	namespace Graphics
	{
		void OpenGLRendererAPI::ClearBuffers(float colorX, float colorY, float colorZ, float alpha)
		{
			glClearColor(colorX, colorY, colorZ, alpha);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		}

		void OpenGLRendererAPI::DrawIndexed(std::shared_ptr<VertexArray>& vertexArray)
		{
			glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);
		}
	}
}