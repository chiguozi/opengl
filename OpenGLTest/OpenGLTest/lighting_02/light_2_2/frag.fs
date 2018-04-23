#version 330 core

in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;

uniform vec3 lightColor;
uniform vec3 objectColor;
uniform float ambientStrength;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
	vec3 normal = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	
	float diff = max(0, dot(lightDir, normal));
	vec3 diffColor = diff * lightColor;
	
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, normal);	
	float spec = pow(max(dot(viewDir , reflectDir), 0), 32);
	vec3 specialColor = spec * lightColor * 0.5;
	
	vec3 ambient = ambientStrength * lightColor;
	FragColor = vec4((ambient + diffColor + specialColor) * objectColor, 1.0f);
}