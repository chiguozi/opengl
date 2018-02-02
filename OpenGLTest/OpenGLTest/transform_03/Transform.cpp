#include "Tool.h"

int main()
{
	MyGlInitGLFW(3);
	GLFWwindow* window = MyGlCreateWindow("transform", 800, 600);
	MyGlInitLoader();
	return 0;
}