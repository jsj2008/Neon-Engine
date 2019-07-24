#include <Neon.h>

using namespace Neon::Application;
using namespace Neon::Graphics;
using namespace Neon::Event;
using namespace Neon::Component;
using namespace Neon::Input;
using namespace Neon::World;

struct R : public Component<R> {};

class MyApp : public Application
{
public:
	MyApp() : camera(glm::vec3(0.0f, 0.0f, -6.0f)), orthoCamera(-1.0f, 1.0f, -1.0f, 1.0f) {}

	void Start() override
	{
		std::vector<float> vertices = 
		{
			-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,
			 0.0f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f,
		};

		std::vector<unsigned int> indices = 
		{
			0, 1, 2   
		};
		
		std::string vertPath = "Engine/Graphics/Shaders/BasicVertex.glsl";
		std::string fragPath = "Engine/Graphics/Shaders/BasicFrag.glsl";
		shader = Shader::Create(vertPath, fragPath);

		BufferLayout layout =
		{
			{ ShaderType::Float3, "inPos" },
			{ ShaderType::Float3, "inColor" }
		};
		
		vertexArray = VertexArray::Create();

		std::shared_ptr<VertexBuffer> vertex = VertexBuffer::Create(vertices);
		vertex->SetLayout(layout);

		std::shared_ptr<IndexBuffer> index = IndexBuffer::Create(indices);

		vertexArray->AddVertexBuffer(vertex);
		vertexArray->AddIndexBuffer(index);

		vertexArray->Unbind();

		mWorld->CreateScene("Test");

		SceneHandle mScene = mWorld->GetScene("Test");
		
		mScene.CreateNode("Trig");

		NodeHandle node = mScene.GetNode("Trig");
		
		GameObjectHandle g = node.GetGameObject();

		g.AddComponent<Transform>(Transform());
	}
	
	void OnUpdate() override
	{
		if (InputManager::GetKey(NEON_KEY_W))
		{
			m_CameraPosition += camera.GetFrontVector() * camera.GetCameraSpeed();
			m_OrthoPosition.y += 0.1f;
		}
		if (InputManager::GetKey(NEON_KEY_S))
		{
			m_CameraPosition -= camera.GetFrontVector() * camera.GetCameraSpeed();
			m_OrthoPosition.y -= 0.1f;
		}
		if (InputManager::GetKey(NEON_KEY_A))
		{
			m_CameraPosition -= camera.GetRightVector() * camera.GetCameraSpeed();
			m_OrthoPosition.x -= 0.1f;
		}
		if (InputManager::GetKey(NEON_KEY_D))
		{
			m_CameraPosition += camera.GetRightVector() * camera.GetCameraSpeed();
			m_OrthoPosition.x += 0.1f;
		}

		orthoCamera.SetPosition(m_OrthoPosition);

		camera.SetPosition(m_CameraPosition);
		camera.ProcessMouseMovement();
	}

	void OnRender() override
	{
		Renderer::StartScene(orthoCamera);

		DrawCommand::ClearBuffer(0.1f, 0.2f, 0.3f, 1.0f);
		Renderer::Submit(vertexArray, shader);
		
		Renderer::EndScene();
	}

	void Stop() override
	{
		
	}

private:
	std::shared_ptr<VertexArray> vertexArray;
	std::shared_ptr<Shader> shader;

	OrthoCamera orthoCamera;
	glm::vec3 m_OrthoPosition = glm::vec3(0.0f);

	PerspectiveCamera camera;
	glm::vec3 m_CameraPosition = glm::vec3(0.0f);
};

NEON_MAIN_APPLICATION(MyApp);