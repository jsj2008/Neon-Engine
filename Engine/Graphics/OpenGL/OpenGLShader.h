#pragma once

#include "Core/Config.h"
#include "Graphics/Primitives/Shader.h"

namespace Neon
{
	namespace Graphics
	{
		enum GLShaderType
		{
			Vertex, Fragment
		};
		
		class NEON_API OpenGLShader : public Shader
		{
		public:
			OpenGLShader(std::string vertexPath, std::string fragPath);

			unsigned int GetID() override;

			void UploadUniformMat4(std::string name, glm::mat4& matrix4) override;

			void Bind() override;

			~OpenGLShader();

		private:
			
			unsigned int m_ShaderID;
		};
	}
}
