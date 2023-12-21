#include "LevelManager.h"

void LevelManager::Init()
{
	levels.emplace_back(new Level0());
	levels.emplace_back(new Level01());
	levels.emplace_back(new Level03());
}

void LevelManager::Start()
{
	levels.at(levelIndex)->Start();
}

void LevelManager::Update()
{
	levels.at(levelIndex)->Update();

}

void LevelManager::Draw()
{
	levels.at(levelIndex)->Draw();

}

void LevelManager::DrawUi()
{
	levels.at(levelIndex)->DrawUi();
}

void LevelManager::GoToNextLevel()
{
	if (levelIndex + 1 < levels.size())
	{
		levels[levelIndex]->Clean();
		levelIndex++;
		Start();
	}
}

void LevelManager::ResetLevel()
{
	levels.at(levelIndex)->ResetLevel();
}
