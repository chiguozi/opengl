#version 330 core
out vec4 fragColor;
in vec3 outColor;
in vec2 texCoord;

uniform sampler2D ourTexture;

void main()
{
	fragColor = texture(ourTexture, texCoord)* vec4(outColor, 1.0);;
}