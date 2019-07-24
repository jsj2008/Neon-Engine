#include "stdafx.h"
#include "DrawCommand.h"
#include "RendererAPI.h"

namespace Neon
{
	namespace Graphics
	{
		void DrawCommand::ClearBuffer(float colorX, float colorY, float colorZ, float alpha)
		{
			std::shared_ptr<RendererAPI> API = RendererAPI::Create();

			API->ClearBuffers(colorX, colorY, colorZ, alpha);
		}

		void DrawCommand::DrawIndexed(std::shared_ptr<VertexArray>& vertexArray)
		{
			std::shared_ptr<RendererAPI> API = RendererAPI::Create();

			API->DrawIndexed(vertexArray);
		}
	}
}
