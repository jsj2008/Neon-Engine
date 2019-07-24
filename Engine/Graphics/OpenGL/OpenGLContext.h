#pragma once

#include "Core/Config.h"
#include "Core/Context.h"

#include "stdafx.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API OpenGLContext : public Neon::Application::Context
		{
		public:	
			OpenGLContext(GLFWwindow* window);

			void Init();

			void AdjustFrameBufferSize(int width, int height) { glViewport(0, 0, width, height); }

			void SwapBuffers();

			void EnableDepth();
			void DisableDepth();

		private:
			GLFWwindow* m_pWindow;
		};
	}
}

