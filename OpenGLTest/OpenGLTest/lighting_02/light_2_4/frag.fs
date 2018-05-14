#version 330 core

in vec3 normal;
in vec2 tex;
in vec3 fragPos;

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
	sampler2D emission;
	float shininess;
};

struct Light
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Material  material;
uniform Light light;
uniform vec3 viewPos;

out vec4 fragColor;

void main()
{
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, tex));
	
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(light.position - fragPos);
	float diff = max(dot(lightDir, norm), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, tex));
	
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float specular = pow(max(dot(viewDir, lightDir), 0.0), material.shininess);
	vec3 specularColor = light.specular * (vec3(texture(material.specular, tex))) * specular;
	
	vec3 emission = vec3(texture(material.emission, tex)) * 0.5f;
	
	fragColor = vec4(ambient + diffuse + specularColor + emission, 1);
}
