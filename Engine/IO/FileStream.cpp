#include "stdafx.h"
#include "FileStream.h"
#include "Core/Log.h"

namespace Neon
{
	namespace IO
	{
		bool FileStream::OpenNewFile(std::string filename)
		{
			std::ofstream outfile(filename);

			outfile.close();

			return true;
		}

		std::string FileStream::ReadFile(std::string filename)
		{
			std::ifstream reader;
			reader.exceptions(std::ifstream::failbit | std::ifstream::badbit);

			std::stringstream strStream;
			std::string file;

			try
			{
				reader.open(NEON_ENGINE_PATH + filename);

				strStream << reader.rdbuf();
				file = strStream.str();

				reader.close();

				return file;
			}
			catch (std::ifstream::failure fail)
			{
				std::string error = "File: " + filename + " failed to open!";

				Log::Critical(error);
			}

			return std::string();
		}

		bool FileStream::WriteFile(std::string filename, std::string stuffToWrite)
		{
			std::ofstream outfile(filename);

			outfile << stuffToWrite;

			outfile.close();

			return true;
		}
		
	}
}
