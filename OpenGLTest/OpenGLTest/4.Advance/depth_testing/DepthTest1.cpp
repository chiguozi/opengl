#include "tool.h"
#include "Shader.h"
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "../../stb_image.h"



int main()
{
	Tool::MyGlInitGLFW(3);
	GLFWwindow *window = Tool::MyGlCreateWindow("depthtest", 800, 600);
	Tool::MyGlInitLoader();
	return 0;
}

