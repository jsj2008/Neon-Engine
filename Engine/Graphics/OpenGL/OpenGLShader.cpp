#include "stdafx.h"
#include "OpenGLShader.h"
#include "IO/FileStream.h"
#include "Core/Log.h"

namespace Neon
{
	namespace Graphics
	{
		OpenGLShader::OpenGLShader(std::string vertexPath, std::string fragPath)
		{
			std::string vert = IO::FileStream::ReadFile(vertexPath);
			std::string frag = IO::FileStream::ReadFile(fragPath);

			const char* vertSource = vert.c_str();
			const char* fragSource = frag.c_str();

			unsigned int vertexShader, fragmentShader;
			
			vertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShader, 1, &vertSource, NULL);
			glCompileShader(vertexShader);

			GLint isCompiled = 0;
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

				// The maxLength includes the NULL character
				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

				// We don't need the shader anymore.
				glDeleteShader(vertexShader);

				Log::Critical(infoLog.data());
				Log::Critical("Vertex shader compilation failure!");
				return;
			}

			fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShader, 1, &fragSource, NULL);
			glCompileShader(fragmentShader);

			isCompiled = 0;
			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

				// The maxLength includes the NULL character
				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

				// We don't need the shader anymore.
				glDeleteShader(fragmentShader);

				Log::Critical(infoLog.data());
				Log::Critical("Fragment shader compilation failure!");
				return;
			}

			m_ShaderID = glCreateProgram();
			glAttachShader(m_ShaderID, vertexShader);
			glAttachShader(m_ShaderID, fragmentShader);
			glLinkProgram(m_ShaderID);

			GLint isLinked = 0;
			glGetProgramiv(m_ShaderID, GL_LINK_STATUS, (int*)& isLinked);
			if (isLinked == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetProgramiv(m_ShaderID, GL_INFO_LOG_LENGTH, &maxLength);

				// The maxLength includes the NULL character
				std::vector<GLchar> infoLog(maxLength);
				glGetProgramInfoLog(m_ShaderID, maxLength, &maxLength, &infoLog[0]);

				// We don't need the program anymore.
				glDeleteProgram(m_ShaderID);
				// Don't leak shaders either.
				glDeleteShader(vertexShader);
				glDeleteShader(fragmentShader);

				Log::Critical(infoLog.data());
				Log::Critical("Shader link failure!");
				return;
			}

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
		}

		unsigned int OpenGLShader::GetID()
		{
			return m_ShaderID;
		}

		void OpenGLShader::UploadUniformMat4(std::string name, const glm::mat4& matrix4)
		{
			int uniformLoc = glGetUniformLocation(m_ShaderID, name.c_str());
			glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(matrix4));
		}

		void OpenGLShader::Bind()
		{
			glUseProgram(m_ShaderID);
		}

		OpenGLShader::~OpenGLShader()
		{
			glDeleteProgram(m_ShaderID);
		}
	}
}
