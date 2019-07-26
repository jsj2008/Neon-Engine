#pragma once

#include <experimental/filesystem>

#if defined(NEON_STATIC_EXPORT) && !defined(NEON_DYNAMIC_EXPORT)
	#define NEON_API
#elif !defined(NEON_STATIC_EXPORT) && defined(NEON_DYNAMIC_EXPORT)
	#if defined(NEON_ENGINE)
		#define NEON_API __declspec(dllexport)
	#else
		#define NEON_API __declspec(dllimport)
	#endif
#elif !defined(NEON_STATIC_EXPORT) && !defined(NEON_DYNAMIC_EXPORT)
	#error Please define the engine export mode!
#else
	#error You cannot define both static and dynamic export mode!
#endif

#if defined(_WIN32)
	#define NEON_PLATFORM_WINDOWS
#elif defined(__unix__) || defined(__unix) || defined(unix) || defined(linux)
	#define NEON_PLATFORM_LINUX
#elif defined(__APPLE__)
	#define NEON_PLATFORM_MACOS
#else
	#error Platform not supported!
#endif

#define NEON_MAIN_APPLICATION(x) \
Neon::Application::Application* Neon::Application::CreateApplication() \
{ \
	return new x(); \
} \

#define NEON_ASSERT(x) if(!(x)) __debugbreak()

const std::string NEON_CLIENT_PATH = std::experimental::filesystem::current_path().u8string();
const std::string NEON_ENGINE_PATH = NEON_CLIENT_PATH + "/../";

#define MAX_COMPONENTS 1024