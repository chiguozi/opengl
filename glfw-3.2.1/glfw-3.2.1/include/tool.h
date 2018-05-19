#ifndef  TOOL_H
#define TOOL_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

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


	static unsigned int LoadTexture(char const * path)
	{
		unsigned int texture;
		glGenTextures(1, &texture);

		int width, height, nrChannels;
		//防止图片颠倒
		stbi_set_flip_vertically_on_load(true);
		unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
		if (data)
		{
			GLenum format;
			if (nrChannels == 1)
				format = GL_RED;
			else if (nrChannels == 3)
				format = GL_RGB;
			else if (nrChannels == 4)
				format = GL_RGBA;

			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_image_free(data);
		}
		else
		{
			stbi_image_free(data);
		}
		return texture;
	}

	static unsigned int TextureFromFile(const char* path, string &directory, bool gamma = false)
	{
		string filename = string(path);
		filename = directory + '/' + path;
		unsigned int textureID;
		glGenTextures(1, &textureID);

		int  width, height, nrComponents;
		unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
		if (data)
		{
			GLenum format;
			if (nrComponents == 1)
				format = GL_RED;
			else if (nrComponents == 3)
				format = GL_RGB;
			else if (nrComponents == 4)
				format = GL_RGBA;

			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_image_free(data);
		}
		else
		{
			std::cout << "Texture failed to load at path: " << path << std::endl;
			stbi_image_free(data);
		}

		return textureID;
	}

protected:
private:
};










#endif // ! TOOL_H
