#ifndef  TOOL_H
#define TOOL_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Tool
{
public:
	static void MyGlInitGLFW(int version)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // 此行用来给Mac OS X系统做兼容
#endif
	};

	static GLFWwindow*  MyGlCreateWindow(char* name, int width, int height)
	{
		GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
		if (window == NULL)
		{
			glfwTerminate();
			return NULL;
		}
		glfwMakeContextCurrent(window);
		return window;
	};

	static void MyGlInitLoader()
	{
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}
protected:
private:
};










#endif // ! TOOL_H
