#include <Neon.h>

using namespace Neon;
using namespace Neon::World;
using namespace Neon::Component;

/* The game class. This is the place where the game code must be written */
class MyApp : public Neon::Application::Application
{
public:
	MyApp() : camera(glm::vec3(0.0f, 0.0f, -6.0f)), orthoCamera(-1.6f, 1.6f, -1.2f, 1.2f) {}

	/* This method gets called when the appliction is created.*/
	void Start() override
	{
		/* This is the array of vertices that make up the quad.*/
		std::vector<float> vertices = {
				-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
				 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f,
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,

				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
				 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
				-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,

				-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
				-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
				-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,

				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
				 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
				 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
				 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,

				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
				 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
				 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
				 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,

				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
				-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f
		};

		/* The indices used for indexed drawing */
		std::vector<unsigned int> indices;
		for (unsigned int i = 0; i < 36; i++) indices.push_back(i);
		
		/* This is the creation of a basic set of shaders */
		/* NOTE: In the future shader files will be created at runtime by materials! */
		std::string vertPath = "Engine/Graphics/Shaders/BasicVertex.glsl";
		std::string fragPath = "Engine/Graphics/Shaders/BasicFrag.glsl";
		shader = Graphics::Shader::Create(vertPath, fragPath);

		/* The buffer layout is neccessery and describes the layout of the vertices */
		Graphics::BufferLayout layout =
		{
			{ Graphics::ShaderType::Float3, "inPos" },
			{ Graphics::ShaderType::Float3, "inColor" }
		};

		Mesh meshComponent = Mesh(vertices, indices, layout);

		/* Creating a new scene in the world */
		mSceneManager->CreateScene("Test");

		SceneRef mScene = mSceneManager->GetScene("Test");

		/* Creating a set of children nodes in the scenes root node */
		SceneNodeRef node1 = mScene->GetRootNode()->CreateChildNode("Quad1");
		SceneNodeRef node2 = mScene->GetRootNode()->CreateChildNode("Quad2");
		SceneNodeRef node3 = mScene->GetRootNode()->CreateChildNode("Quad3");
		
		/* Setting the transform component in each of the nodes */
		/* NOTE: The transform component is always created by default with a node! */
		node1->SetComponent<Transform>(Transform(glm::vec3(-1.5f, 0.0f, 0.0f)));
		node2->SetComponent<Transform>(Transform(glm::vec3(0.0f, 0.0f, 0.0f)));
		node2->SetComponent<Transform>(Transform(glm::vec3(1.5f, 0.0f, 0.0f)));

		node1->AddComponent<Mesh>(meshComponent);
		node2->AddComponent<Mesh>(meshComponent);
		node3->AddComponent<Mesh>(meshComponent);
	}
	
	/* This method is called on every simulation step */
	void OnUpdate() override
	{
		/* Example use of the InputManager for camera controls */
		if (!Input::InputManager::GetKey(NEON_KEY_H))
		{
			if (Input::InputManager::GetKey(NEON_KEY_W))
			{
				m_CameraPosition += camera.GetFrontVector() * camera.GetCameraSpeed();
				m_OrthoPosition.y += 2.0f * (float)deltaTime;
			}
			else if (Input::InputManager::GetKey(NEON_KEY_S))
			{
				m_CameraPosition -= camera.GetFrontVector() * camera.GetCameraSpeed();
				m_OrthoPosition.y -= 2.0f * (float)deltaTime;
			}
			else if (Input::InputManager::GetKey(NEON_KEY_A))
			{
				m_CameraPosition -= camera.GetRightVector() * camera.GetCameraSpeed();
				m_OrthoPosition.x -= 2.0f * (float)deltaTime;
			}
			else if (Input::InputManager::GetKey(NEON_KEY_D))
			{
				m_CameraPosition += camera.GetRightVector() * camera.GetCameraSpeed();
				m_OrthoPosition.x += 2.0f * (float)deltaTime;
			}

			orthoCamera.SetPosition(m_OrthoPosition);

			camera.SetPosition(m_CameraPosition);
			camera.ProcessMouseMovement();
		}
	}

	void OnRender() override
	{
		/* Adjust the aspect ratio of the projection */
		camera.SetAspectRatio(m_Window->GetDimetions());
		
		/* Neon's rendering pipeline */
		Graphics::Renderer::StartScene(camera);

		Graphics::DrawCommand::ClearBuffer(0.0f, 0.4f, 0.9f, 1.0f);

		/* Iterating over the sceneNodes of the active scene and drawing all the gameObjects */
		/* In the future I think that a better way to do this is to render in the EndScene() method */
		/* and have this Submit() call push back draw calls to a render queue that can later can be ex. sorted by material */
		mSceneManager->GetActiveScene()->IterateSceneNodes([this](const World::SceneNodeRef& node)
		{
			ComponentRef<Transform> transform = node->GetComponent<Transform>();
			ComponentRef<Mesh> mesh = node->GetComponent<Mesh>();

			Graphics::Renderer::Submit(mesh->GetVertexArray(), shader, transform->GetModelMatrix());
		});

		Graphics::Renderer::EndScene();
	}

	/* Called when the application is closed */
	void Stop() override
	{
		
	}

private:
	std::shared_ptr<Graphics::Shader> shader;

	World::OrthoCamera orthoCamera;
	glm::vec3 m_OrthoPosition = glm::vec3(0.0f);

	World::PerspectiveCamera camera;
	glm::vec3 m_CameraPosition = glm::vec3(0.0f);
};

/* Sets your application as the current active application */
NEON_MAIN_APPLICATION(MyApp);