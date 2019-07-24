#include "stdafx.h"
#include "glm/gtx/string_cast.hpp"
#include "PerspectiveCamera.h"
#include "Core/Platform/Windows/Win32InputManager.h"

namespace Neon
{
	namespace World
	{
		PerspectiveCamera::PerspectiveCamera(glm::vec3 position) : m_Front(glm::vec3(0.0f, 0.0f, -1.0f)), 
			MovementSpeed(7.5f), MouseSensitivity(0.05f), Zoom(45.0f),
			m_ProjectionMatrix(glm::perspective(glm::radians(45.0f), 1000.0f / 720.0f, 0.1f, 100.0f))
		{
			m_Position = position;
			m_WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
			Yaw = -90.0f;
			Pitch = 0.0f;
			
			UpdateCameraVectors();
		}

		void PerspectiveCamera::ProcessMouseMovement(bool constrainPitch)
		{
			float xpos = Input::InputManager::GetMousePos().x;
			float ypos = Input::InputManager::GetMousePos().y;

			if (firstMouse)
			{
				lastX = xpos;
				lastY = ypos;
				firstMouse = false;
			}

			float xoffset = xpos - lastX;
			float yoffset = lastY - ypos;
			lastX = xpos;
			lastY = ypos;
			
			xoffset *= MouseSensitivity;
			yoffset *= MouseSensitivity;

			Yaw += xoffset;
			Pitch += yoffset;

			if (constrainPitch)
			{
				Pitch = Pitch > 89.0f ? 89.0f : Pitch;
				Pitch = Pitch < -89.0f ? -89.0f : Pitch;
			}

			UpdateCameraVectors();
		}

		void PerspectiveCamera::UpdateCameraVectors()
		{
			glm::vec3 front;
			front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
			front.y = sin(glm::radians(Pitch));
			front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
			m_Front = glm::normalize(front);

			m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
			m_Up = glm::normalize(glm::cross(m_Right, m_Front));

			m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
			m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
		}
		
	}
}