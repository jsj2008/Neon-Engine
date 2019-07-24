#pragma once

#include "Core/Config.h"
#include "stdafx.h"

namespace Neon
{
	namespace World
	{
		enum Camera_Movement
		{
			FORWARD,
			BACKWARD,
			LEFT,
			RIGHT
		};

		class NEON_API PerspectiveCamera
		{
		public:
			PerspectiveCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));

			void ProcessMouseMovement(bool constrainPitch = true);

			glm::mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
			glm::mat4 GetViewMatrix() const { return m_ViewMatrix; }
			glm::mat4& GetProjectionViewMatrix() { return m_ProjectionViewMatrix; }

			void SetProjectionMatrix(glm::mat4& projection) { m_ProjectionMatrix = projection; }

			void SetPosition(glm::vec3 pos) { m_Position = pos; UpdateCameraVectors(); }
			glm::vec3& GetPosition() { return m_Position; }

			glm::vec3& GetFrontVector() { return m_Front; }
			glm::vec3& GetRightVector() { return m_Right; }

			void SetCameraSpeed(float speed) { m_CameraSpeed = speed; }
			float GetCameraSpeed() const { return m_CameraSpeed; }

			~PerspectiveCamera() {}

		private:
			void UpdateCameraVectors();
			
		private:
			glm::mat4 m_ViewMatrix = glm::mat4(1.0f);
			glm::mat4 m_ProjectionMatrix = glm::mat4(1.0f);
			glm::mat4 m_ProjectionViewMatrix = glm::mat4(1.0f);
			
			glm::vec3 m_Position, m_Front, m_Up, m_Right, m_WorldUp;

			float Yaw, Pitch;
			float MovementSpeed, MouseSensitivity, Zoom;
			float m_CameraSpeed = 0.1f;

			bool firstMouse = true;
			float lastX = 0.0f, lastY = 0.0f;
		};
	}
}