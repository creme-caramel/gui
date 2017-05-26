#include "imgui.h"
#include "imgui_impl_glfw.h"
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>

typedef GLFWwindow Window;
 
void error_callback(int err, const char *desc);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
GLFWwindow * init_window(int width, int height, const char *title);
bool window_should_close(GLFWwindow *window);
void pollevents();
void render(GLFWwindow *window, const ImVec4 &color);
void terminate_window(GLFWwindow *window);