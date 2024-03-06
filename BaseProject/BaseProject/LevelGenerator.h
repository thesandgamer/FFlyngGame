#pragma once
#include "Level.h"
#include "LevelCreator.h"

class LevelGenerator :
    public LevelCreator
{
public:
	void Start() override;
	void Update() override;
	void Draw() override;

private:
	Vector3 maxSizeOfMap{ 20,20,20 };
	

};

