#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


int main()
{
	std::cout << "Hello OpenGL, GLaD and GLFW!" << std::endl;

	glfwInit();

	// Start OpenGl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	return 0;
}


