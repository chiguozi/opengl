#version 330 core

in vec3 normal;
in vec3 fragPos;

out vec4 fragColor;

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

struct Light
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Material material;
uniform Light light;
uniform vec3 viewPos;

void main()
{
	vec3 ambientColor = light.ambient * material.ambient;
	
	vec3 lightDir = normalize(light.position - fragPos);
	vec3 norm = normalize(normal);
	float diff = max(dot(lightDir, norm), 0.0);
	vec3 diffuse = light.diffuse * (diff * material.diffuse);
	
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float specular = pow(max(dot(viewDir, lightDir), 0.0), material.shininess);
	vec3 specularColor = light.specular * material.specular * specular;
	
	fragColor = vec4(ambientColor + diffuse + specularColor, 1);
	
}
