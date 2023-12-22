#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Callbacks.h"
#include "Utilities.h"
#include "Input.h"
#include "Vertex.h"
#include "rendering/OpenGLLoader.h"
#include "rendering/OpenGLDraw.h"

int main(int argc, char* argv[])
{
	glfwSetErrorCallback(glfw_error_callback);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	GLFWwindow* window = glfwCreateWindow(640, 480, extract_version(argv[0]), NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSetWindowCloseCallback(window, glfw_window_close_callback);
	glfwSetFramebufferSizeCallback(window, glfw_framebuffer_size_callback);
	glClearColor(.2f, .2f, .6f, 0.0f);

	std::vector<DrawDetails> drawDetails;

	std::vector<Vertex> vertices;
	vertices.emplace_back(0.5f, -0.5f, 0.0f); // bottom left
	vertices.emplace_back(-0.5f, 0.5f, 0.0f); // bottom right
	vertices.emplace_back(0.0f, 0.5f, 0.0f); // top

	std::vector<uint32_t> elems = { 0, 1, 2 };

	// Upload vertex data to GPU
	drawDetails.push_back(UploadMesh(vertices, elems));

	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);
		glClear(GL_COLOR_BUFFER_BIT);
		Draw(drawDetails);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	UnloadMesh(drawDetails);
	glfwTerminate();

	return 0;
}	