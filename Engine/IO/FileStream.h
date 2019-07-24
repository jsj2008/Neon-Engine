#pragma once

#include "Core/Config.h"

#include "stdafx.h"

namespace Neon
{
	namespace IO
	{
		class FileStream
		{
		public:
			FileStream() = default;

			static bool OpenNewFile(std::string filename);

			static std::string ReadFile(std::string filename);

			static bool WriteFile(std::string filename, std::string stuffToWrite);
		};
	}
}

