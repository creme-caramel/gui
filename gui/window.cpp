#include "window.h"
using namespace std;

void error_callback(int err, const char *desc)
{
	fprintf(stderr, "Error: %d: %s\n", err, desc);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLFWwindow *init_window(int width, int height, const char *title)
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		cout <<  "can't initialize glfw" << endl;
		return NULL;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow * window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		cout << "Window or openGL context creation failed" << endl;
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	cout << "Starting GLFW context, OpenGL2" << endl;
	ImGui_ImplGlfw_Init(window, true);
	return window;
}

bool window_should_close(GLFWwindow *window)
{
	return glfwWindowShouldClose(window);
}

void pollevents()
{
	glfwPollEvents();
}

void render(GLFWwindow *window, const ImVec4 &color)
{
	int display_w, display_h;
	glfwGetFramebufferSize(window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClearColor(color.x, color.y, color.z, color.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui::Render();
	glfwSwapBuffers(window);
}

void terminate_window(GLFWwindow *window)
{
	// glfwDestroyWindow(window);
	ImGui_ImplGlfw_Shutdown();
	glfwTerminate();
}