#pragma once

#include "Core/Config.h"
#include "Primitives/Buffer.h"
#include "Primitives/Shader.h"
#include "World/Camera/OthoCamera.h"
#include "Primitives/Texture.h"
#include "World/Camera/PerspectiveCamera.h"
#include "Primitives/VertexArray.h"
#include "DrawCommand.h"
#include "World/Components/Transform.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API Renderer
		{
		public:
			Renderer() = default;

			static void StartScene(World::OrthoCamera& camera);
			static void StartScene(World::PerspectiveCamera& camera);

			static void Submit(std::shared_ptr<VertexArray>& vertexArray, std::shared_ptr<Shader>& shader, const glm::mat4& model);
			
			static void EndScene() {}

		private:
			struct SceneData
			{
				glm::mat4 m_ViewProjectionMatrix = glm::mat4(1.0f);
				glm::mat4 m_identityMatrix = glm::mat4(1.0f);
			};

			static std::shared_ptr<SceneData> m_SceneData;

			~Renderer() = default;
		};
	}
}