#include "Utility.h"

void Utility::Start()
{
	dotTexture = LoadTexture("../resources/Dot.png");

	jumpSound = LoadSound("../resources/Audio/Snd_Jump.wav");
}

void Utility::AddModel(Model* model)
{
	cubesModels.push_back(model);
}



void Utility::Unload()
{
	for (Model* cube : cubesModels)
	{
		UnloadModel(*cube);
	}
	UnloadTexture(dotTexture);
	UnloadShader(*shader);

	UnloadSound(jumpSound);
}