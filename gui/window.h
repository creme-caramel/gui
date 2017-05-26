#include "imgui.h"
#include "imgui_impl_glfw.h"
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>

typedef GLFWwindow Window;
 
void error_callback(int, const char *);
void key_callback(GLFWwindow *, int, int, int, int);
GLFWwindow * init_window(int, int, const char *);
bool window_should_close(GLFWwindow *);
void pollevents();
void render(GLFWwindow *, const ImVec4 &);
void terminate_window(GLFWwindow *);