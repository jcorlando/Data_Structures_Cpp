#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

// Callback function to resize framebuffer every time the window is resized
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window);

// Settings and Constants
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


int main()
{
	// Initialize GLFW
	glfwInit();

	// Start OpenGl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Use the core profile of OpenGl Instead of the Immediate-Mode
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window with width = 800, height = 600, title = "My OpenGL",
	// windowed mode and not to share resources in windowed mode.
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "My OpenGL", NULL, NULL);

	// If there is an error creating the window then print error to console
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Make the context of our window the main context on the current thread
	glfwMakeContextCurrent(window);
	// Register callback function to tell GLFW we want to call this function on every window resize
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}


	// render loop
	while(!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		// render
		glClearColor(0.4f, 0.7f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	// glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	return 0;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window)
{
	if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}


// Callback function to resize framebuffer every time the window is resized
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// tell OpenGL the size of the rendering window so OpenGL knows how we
	// want to display the data and coordinates with respect to the window
	// -------------------------------------------------------------------
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}


