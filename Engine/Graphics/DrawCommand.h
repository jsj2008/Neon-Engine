#pragma once

#include "Core/Config.h"
#include "Primitives/VertexArray.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API DrawCommand
		{
		public:
			DrawCommand() = default;

			static void ClearBuffer(float colorX, float colorY, float colorZ, float alpha);

			static void DrawIndexed(std::shared_ptr<VertexArray>& vertexArray);

			~DrawCommand() = default;
		};
	}
}