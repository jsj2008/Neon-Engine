#pragma once

#include "Core/Config.h"
#include "Core/Entry.h"
#include "Core/ISystem.h"
#include "Core/Log.h"
#include "Core/Application.h"
#include "Core/Event/Event.h"
#include "Core/Event/EventBus.h"
#include "Core/Event/KeyEvent.h"
#include "Core/Event/MemberHandler.h"
#include "Core/Event/MouseEvent.h"
#include "Core/Event/WindowEvent.h"
#include "Core/Context.h"
#include "Core/KeyCode.h"
#include "Core/Platform/Windows/Win32InputManager.h"
#include "Core/Platform/Windows/Win32Window.h"
#include "Core/Timer.h"
#include "Core/Window.h"
#include "IO/FileStream.h"
#include "Graphics/DrawCommand.h"
#include "Graphics/Renderer.h"
#include "Graphics/RendererAPI.h"
#include "Graphics/OpenGL/OpenGLBuffer.h"
#include "Graphics/OpenGL/OpenGLContext.h"
#include "Graphics/OpenGL/OpenGLRendererAPI.h"
#include "Graphics/OpenGL/OpenGLShader.h"
#include "Graphics/OpenGL/OpenGLVertexArray.h"
#include "Graphics/Primitives/Buffer.h"
#include "Graphics/Primitives/BufferLayout.h"
#include "Graphics/Primitives/Shader.h"
#include "Graphics/Primitives/VertexArray.h"
#include "Graphics/Primitives/Texture.h"
#include "Graphics/OpenGL/OpenGLTexture.h"
#include "World/Components/Transform.h"
#include "World/Camera/OthoCamera.h"
#include "World/Camera/PerspectiveCamera.h"
#include "World/Components/Component.h"
#include "World/Components/ComponentManager.h"
#include "World/Components/ComponentMask.h"
#include "World/GameObject.h"
#include "World/GameObjectManager.h"
#include "World/Scene/Node.h"
#include "World/Scene/NodeHandle.h"
#include "World/Scene/Scene.h"
#include "World/Scene/SceneHandle.h"
#include "World/Scene/SceneManager.h"
#include "World/Scene/SceneNode.h"
#include "World/World.h"
#include "World/GameObjectHandle.h"
#include "World/Components/ComponentHandle.h"

#include "glm/gtx/string_cast.hpp"