#pragma once

#include "Core/Config.h"
#include "Component.h"
#include "glm/glm.hpp"

namespace Neon
{
	namespace Component
	{
		class NEON_API Transform : public Component<Transform>
		{
		public:
			Transform() = default;
			Transform(glm::vec3 position);
			Transform(glm::vec3 position, glm::vec3 scale);

			void SetPosition(glm::vec3 pos) { m_Position = pos; CalculateModelMatrix(); }
			glm::vec3 GetPosition() const { return m_Position; }

			void SetScale(glm::vec3 scale) { m_Scale = scale; CalculateModelMatrix(); }
			glm::vec3 GetScale() const { return m_Scale; }

			glm::mat4 GetModelMatrix() { return m_ModelMatrix; }

			void OnAttach() {}
			void OnDettach() {}

		private:
			void CalculateModelMatrix();

		private:
			glm::vec3 m_Position = glm::vec3(0.0f);
			glm::vec3 m_Scale = glm::vec3(1.0f);

			glm::mat4 m_ModelMatrix = glm::mat4(1.0f);
		};
	}
}