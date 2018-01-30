#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "iostream"


int main_03()
{
	//uniform 可以放在vertex 也可以放在frag中 
	const GLchar* vertexShaderSource =
		"#version 330 core\n"
		"layout(location = 0) in vec3 position;\n"
		"layout(location = 1) in vec4 verColor;\n"
		//"//uniform vec4 inputColor;"
		"out vec4 outColor;"
		"out vec4 outposition;"
		"void main()\n"
		"{\n outColor = verColor;\n  gl_Position = vec4(position, 1.0f); outposition = vec4(position, 1.0f);   }\n";

	const GLchar* fragShaderSource =
		"#version 330 core \n"
		"out vec4 fragColor;\n"
		//"//uniform vec4 inputColor;\n"
		"in vec4 outColor;\n"
		"in vec4 outposition;"
		"void main() { fragColor = outposition;}";

	//GLGW初始化
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // 此行用来给Mac OS X系统做兼容
#endif
	GLFWwindow* window = glfwCreateWindow(800, 600, "shaderuniform", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return -1;
	}

	glViewport(0, 0, 800, 600);

	// 顶点shader
	// 创建一个shader  使用ID来引用
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//shader    传递的字符串数量    字符串源码
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//编译shader
	glCompileShader(vertexShader);

	//获取shader编译状态
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Error" << infoLog;
	}

	// 顶点着色器
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fragShaderSource, NULL);
	glCompileShader(fragShader);

	// 创建着色器程序对象，合并多个着色器
	GLuint shaderProgram = glCreateProgram();

	//将shader链接到shaderProgram中
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);


	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "LINK ERROR\n" << infoLog;
	}



	//着色器链接之后  shader就不需要了 可以直接删除
	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);

	// 顶点输入
	GLfloat vertices[] = {
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0,
		0.5f, -0.5f, 0.0f, 0, 1.0f, 0,
		-0.5f, -0.5f, 0.0f, 0, 0, 1, // 左下角
		//-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.5f,   // 左上角
		//0.5f, -1.0f, 0.0f,
	};

	GLint indices[] = {// 注意索引从0开始! 
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	// 0. 复制顶点数组到缓冲中供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//绑定颜色
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);

		/*float timeValue = glfwGetTime();
		float greenValue = sin(timeValue) / 2.0 + 0.5f;
		float redValue = cos(timeValue) / 2.0 + 0.5f;

		int vertexColorLoaction = glGetUniformLocation(shaderProgram, "inputColor");
		glUniform4f(vertexColorLoaction, redValue, greenValue, 0.0f, 1.0f);*/
		
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 4);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glfwTerminate();

	return 0;
}


