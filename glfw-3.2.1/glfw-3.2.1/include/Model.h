#pragma once
#ifndef MODEL_H
#define MODEL_H
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "stb_image.h"
#include "tool.h"
#include "shader.h"
#include "Mesh.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Model
{
public:
	vector<Mesh> meshes;
	vector<Texture> textures_loaded;
	bool gammaCorrection;
	Model(char* path)
	{
		loadModel(path);
	}
	void Draw(Shader shader)
	{
		for (unsigned int i = 0; i < meshes.size(); i ++)
		{
			meshes[i].Draw(shader);
		}
	}
private:

	string directroy;
	void loadModel(string path) 
	{
		Assimp::Importer import;
		const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
		{
			cout << "error:assimp:" << import.GetErrorString() << endl;
			return;
		}
		directroy = path.substr(0, path.find_last_of('/'));
		processNode(scene->mRootNode, scene);
	}
	void processNode(aiNode *node, const aiScene *scene)
	{
		//处理节点所有的网格（如果有的话）
		for (unsigned int i = 0; i < node->mNumMeshes; i++)
		{
			aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
			meshes.push_back(processMesh(mesh, scene));
		}

		for (unsigned int i = 0; i < node->mNumChildren; i++)
		{
			processNode(node->mChildren[i], scene);
		}
	}
	Mesh processMesh(aiMesh *mesh, const aiScene *scene) 
	{
		vector<Vertex> vertices;
		vector<unsigned int> indeces;
		vector<Texture> textures;

		//处理顶点、法线、纹理
		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			Vertex vertex;
			glm::vec3 vector;
			vector.x = mesh->mVertices[i].x;
			vector.y = mesh->mVertices[i].y;
			vector.z = mesh->mVertices[i].y;
			vertex.Position = vector;

			vector.x = mesh->mNormals[i].x;
			vector.y = mesh->mNormals[i].y;
			vector.z = mesh->mNormals[i].z;
			vertex.Normal = vector;

			if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
			{
				glm::vec2 vec;
				// a vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
				// use models where a vertex can have multiple texture coordinates so we always take the first set (0).
				vec.x = mesh->mTextureCoords[0][i].x;
				vec.y = mesh->mTextureCoords[0][i].y;
				vertex.TexCoords = vec;
			}
			else
				vertex.TexCoords = glm::vec2(0.0f, 0.0f);
			// tangent
			//vector.x = mesh->mTangents[i].x;
			//vector.y = mesh->mTangents[i].y;
			//vector.z = mesh->mTangents[i].z;
			//vertex.Tangent = vector;
			//// bitangent
			//vector.x = mesh->mBitangents[i].x;
			//vector.y = mesh->mBitangents[i].y;
			//vector.z = mesh->mBitangents[i].z;
			//vertex.Bitangent = vector;
			vertices.push_back(vertex);

		}
		
		for (unsigned int i = 0; i < mesh->mNumFaces; i++)
		{
			aiFace face = mesh->mFaces[i];
			for (unsigned int j = 0; j < face.mNumIndices; j++)
			{
				indeces.push_back(face.mIndices[j]);
			}
		}

		// 处理材质
		if (mesh->mMaterialIndex >= 0)
		{
			aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
			// 1. diffuse maps
			vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
			textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
			// 2. specular maps
			vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
			textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
			// 3. normal maps
			std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
			textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
			// 4. height maps
			std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
			textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
		}
		return Mesh(vertices, indeces, textures);
	}
	vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName)
	{
		vector<Texture> textures;
		for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
		{
			aiString str;
			mat->GetTexture(type, i, &str);
			bool skip = false;
			for (unsigned int j = 0; j < textures_loaded.size(); j++)
			{
				if (std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
				{
					textures.push_back(textures_loaded[j]);
					skip = true;
					break;
				}
			}

			if (!skip)
			{   // 如果纹理还没有被加载，则加载它
				Texture texture;
				texture.id = Tool::TextureFromFile(str.C_Str(), directroy, false);
				texture.type = typeName;
				texture.path = str.C_Str();
				textures.push_back(texture);
				textures_loaded.push_back(texture); // 添加到已加载的纹理中
			}
		}
		return textures;
	}
	
};


#endif