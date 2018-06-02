#version 330 core

out vec4 FragColor;

in vec2 Texcoords;

uniform sampler2D texture1;

void main()
{
	vec4 texColor = texture(texture1, Texcoords);
	if(texColor.a < 0.1)
		discard;
	FragColor = texColor;
}