#pragma once
#include "AStarManager.h"
#include "Level.h"
#include "LevelCreator.h"

class LevelGenerator :
    public LevelCreator
{
public:
	void Start() override;
	void Update() override;
	void Draw() override;

protected:
	Vector3 maxSizeOfMap{ 20,20,20 };

	
	
	//
	std::vector<AStar::Vector3Pos> path;
};

