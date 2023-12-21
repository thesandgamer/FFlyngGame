#pragma once
#include "raylib.h"
#include <vector>

int const screenWidth = 1920;
int const screenHeight = 1080;

class Utility
{
	//--------------Make it a singleton------------------
private:
	Utility() {};
	static Utility* instance;

public:
	Utility(const Utility& obj) = delete;
	void operator=(const Utility&) = delete;

	static Utility* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Utility();
		}
		return instance;
	}

public:

	void Start();

	Texture2D dotTexture;// = LoadTexture("../resources/Dot.png");
	std::vector<Model*> cubesModels;

	Shader* shader;

	void AddModel(Model* model);

	void Unload();
	

	Sound jumpSound;
};

