#pragma once
#include <cstdio>
#include "Utilities.h"

static void glfw_error_callback(int error, const char* description)
{
	write_log(description);
	throw("glfw error");
 }

static void glfw_window_close_callback(GLFWwindow* window)
{
	std::string msg = "Window closed at: ";
	msg += get_timestamp();
	write_log(msg.c_str());
}	

static void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}