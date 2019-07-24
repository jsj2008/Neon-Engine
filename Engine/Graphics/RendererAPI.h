#pragma once

#include "Core/Config.h"

namespace Neon
{
	namespace Graphics
	{
		class VertexArray;
		
		enum GraphicsAPI
		{
			None = 0,
			OpenGL = 1
		};
		
		class NEON_API RendererAPI
		{
		public:
			RendererAPI() = default;

			virtual void ClearBuffers(float colorX, float colorY, float colorZ, float alpha) = 0;
			virtual void DrawIndexed(std::shared_ptr<VertexArray>& vertexArray) = 0;

			static std::shared_ptr<RendererAPI> Create();

			virtual ~RendererAPI() {}

		public:
			static GraphicsAPI m_RendererAPI;
		
		};

		
	}
}