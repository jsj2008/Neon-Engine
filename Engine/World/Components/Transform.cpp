#include "stdafx.h"
#include "Transform.h"

namespace Neon
{
	namespace Component
	{
		Transform::Transform(glm::vec3 position)
		{
			m_Position = position;

			CalculateModelMatrix();
		}
		
		Transform::Transform(glm::vec3 position, glm::vec3 scale)
		{
			m_Position = position;
			m_Scale = scale;

			CalculateModelMatrix();
		}
		
		void Transform::CalculateModelMatrix()
		{
			m_ModelMatrix = glm::translate(glm::mat4(1.0f), m_Position) * glm::scale(glm::mat4(1.0f), m_Scale);
		}
	}
}
