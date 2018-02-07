#version 330 core
out vec4 fragColor;
in vec2 TexCoord;

uniform sampler2D tex1;
uniform sampler2D tex2;

void main()
{
	fragColor = mix(texture(tex1, TexCoord), texture(tex2, TexCoord), 0.5);
}
