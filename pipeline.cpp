#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
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

int main()
{
	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		cout <<  "can't initialize glfw" << endl;
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow *w = glfwCreateWindow(640, 480, "Awesome Window", NULL, NULL);
	if (!w) {
		cout << "Window or openGL context creation failed" << endl;
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(w);
	glfwSetKeyCallback(w, key_callback);
	cout << "Starting GLFW context, OpenGL2" << endl;

	ImGui_ImplGlfw_Init(w, true);
	bool show_test_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImColor(114, 144, 154);

	while (!glfwWindowShouldClose(w))
	{
		glfwPollEvents();
		ImGui_ImplGlfw_NewFrame();


		// Rendering
		int display_w, display_h;
		glfwGetFramebufferSize(w, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		glfwSwapBuffers(w);
	}

	// glfwDestroyWindow(w);
	ImGui_ImplGlfw_Shutdown();
	glfwTerminate();
	return 0;
}
