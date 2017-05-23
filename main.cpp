// main.cpp

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
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
		cout <<  "oops" << endl;
		return 0;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow *w = glfwCreateWindow(640, 480, "Awesome Window", NULL, NULL);
	if (!w) {
		cout << "Window or openGL context creation failed" << endl;
		glfwTerminate();
		return 0;
	}
	cout << "Starting GLFW context, OpenGL2" << endl;
	glfwMakeContextCurrent(w);
	glfwSetKeyCallback(w, key_callback);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "failed to initialize glew\n");
		glfwTerminate();
		return 0;
	}

	glfwSetInputMode(w, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0, 0, 0, 0);

	do {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(w);
		glfwPollEvents();
	} while (glfwGetKey(w, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(w) == 0);

	// glfwDestroyWindow(w);
	glfwTerminate();
	return 0;
}
