#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "iostream"


int main_03()
{
	//uniform ���Է���vertex Ҳ���Է���frag�� 
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

	//GLGW��ʼ��
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // ����������Mac OS Xϵͳ������
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

	// ����shader
	// ����һ��shader  ʹ��ID������
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//shader    ���ݵ��ַ�������    �ַ���Դ��
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//����shader
	glCompileShader(vertexShader);

	//��ȡshader����״̬
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Error" << infoLog;
	}

	// ������ɫ��
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fragShaderSource, NULL);
	glCompileShader(fragShader);

	// ������ɫ��������󣬺ϲ������ɫ��
	GLuint shaderProgram = glCreateProgram();

	//��shader���ӵ�shaderProgram��
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);


	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "LINK ERROR\n" << infoLog;
	}



	//��ɫ������֮��  shader�Ͳ���Ҫ�� ����ֱ��ɾ��
	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);

	// ��������
	GLfloat vertices[] = {
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0,
		0.5f, -0.5f, 0.0f, 0, 1.0f, 0,
		-0.5f, -0.5f, 0.0f, 0, 0, 1, // ���½�
		//-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.5f,   // ���Ͻ�
		//0.5f, -1.0f, 0.0f,
	};

	GLint indices[] = {// ע��������0��ʼ! 
		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	// 0. ���ƶ������鵽�����й�OpenGLʹ��
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//���ö�������ָ��
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//����ɫ
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


