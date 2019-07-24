#pragma once

#include "Core/Config.h"
#include "stdafx.h"

namespace Neon
{
	namespace World
	{
		class NEON_API OrthoCamera
		{
		public:
			OrthoCamera(float left, float right, float bottom, float top);

			glm::vec3 GetPosition() const { return m_Position; }
			void SetPosition(const glm::vec3& pos) { m_Position = pos; CalculateMatrices(); }

			float GetRotation() const { return m_Rotation; }
			void SetRotation(float rotation) { m_Rotation = rotation; CalculateMatrices(); }

			glm::mat4& GetViewProjectionMatrix() { return m_ProjectViewMatrix; }

			~OrthoCamera() {}

		private:
			void CalculateMatrices();

		private:
			glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
			float m_Rotation = 0.0f;

			glm::mat4 m_ViewMatrix;
			glm::mat4 m_ProjectMatrix;

			glm::mat4 m_ProjectViewMatrix;
		};
	}
}

