#version 330 core

in vec3 normal;
in vec3 fragPos;

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

uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 lightPos;
uniform Material material;

void main()
{
	vec3 ambientColor = lightColor * material.ambient;
}
