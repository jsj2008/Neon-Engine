#pragma once

#include "Core/Config.h"

namespace Neon
{
	namespace Graphics
	{
		class NEON_API Shader
		{
		public:
			Shader() = default;

			virtual unsigned int GetID() = 0;

			virtual void Bind() = 0;

			virtual void UploadUniformMat4(std::string name, const glm::mat4& matrix4) = 0;

			static std::shared_ptr<Shader> Create(std::string vertexPath, std::string pixelPath);

			virtual ~Shader() = default;
		};
	}
}

