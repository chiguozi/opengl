#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;



out vec3 Normal;
out vec3 FragPos;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	//逆矩阵也是一个开销比较大的运算，因此，只要可能就应该避免在着色器中进行逆矩阵运算
	//在绘制之前你最好用CPU计算出法线矩阵，然后通过uniform把值传递给着色器
	//Normal = mat3(transpose(inverse(model))) * aNormal;
	Normal = aNormal;
	FragPos = vec3(model * vec4(aPos, 1.0f));
}