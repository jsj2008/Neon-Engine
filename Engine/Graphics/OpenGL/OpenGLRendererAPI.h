#pragma once

#include "Core/Config.h"
#include "Graphics/RendererAPI.h"
#include "OpenGLVertexArray.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API OpenGLRendererAPI : public RendererAPI
		{
		public:
			OpenGLRendererAPI() = default;

			void ClearBuffers(float colorX, float colorY, float colorZ, float alpha) override;
			void DrawIndexed(std::shared_ptr<VertexArray>& vertexArray) override;

			~OpenGLRendererAPI() = default;
		};
	}
}