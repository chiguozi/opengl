#version 330 core
out vec4 fragColor;
in vec3 outColor;
in vec2 texCoord;

uniform sampler2D ourTexture;
uniform sampler2D ourTexture1;
uniform float radio;

void main()
{
	fragColor = mix(texture(ourTexture, texCoord), texture(ourTexture1, vec2(texCoord.x * 2, texCoord.y * 2)), radio);
	//fragColor = mix(texture(ourTexture, texCoord), texture(ourTexture1, texCoord), 0.5)* vec4(outColor, 1.0);
}