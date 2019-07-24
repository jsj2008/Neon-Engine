#pragma once

#define GLFW_INCLUDE_NONE

#if defined(NEON_PLATFORM_WINDOWS)
#include <Windows.h>
#endif

// OpenGL headers 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

// C++ headers
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <functional>
#include <charconv>
#include <memory>
#include <typeinfo>
#include <typeindex>
#include <sstream>
#include <fstream>
#include <initializer_list>
#include <ostream>
#include <filesystem>


