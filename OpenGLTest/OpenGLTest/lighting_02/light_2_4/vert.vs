#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTex;

uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;

out vec3 fragPos;
out vec3 normal;
out vec2 tex;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1);
	normal = aNormal;
	tex = aTex;
	fragPos = vec3(model * vec4(aPos, 1.0f));
}
