#include "stdafx.h"
#include "Renderer.h"

namespace Neon
{
	namespace Graphics
	{
		std::shared_ptr<Renderer::SceneData> Renderer::m_SceneData = std::make_shared<Renderer::SceneData>();
		
		void Renderer::StartScene(World::OrthoCamera& camera)
		{
			m_SceneData->m_ViewProjectionMatrix = camera.GetViewProjectionMatrix();
		}

		void Renderer::StartScene(World::PerspectiveCamera& camera)
		{
			m_SceneData->m_ViewProjectionMatrix = camera.GetProjectionViewMatrix();
		}

		void Renderer::Submit(std::shared_ptr<VertexArray>& vertexArray, std::shared_ptr<Shader>& shader)
		{
			shader->Bind();
			shader->UploadUniformMat4("u_ProjectionView", m_SceneData->m_ViewProjectionMatrix);
			shader->UploadUniformMat4("u_ModelMatrix", m_SceneData->m_identityMatrix);

			vertexArray->Bind();
			DrawCommand::DrawIndexed(vertexArray);
		}
	}
}