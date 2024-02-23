#pragma once
#include "Level.h"

class LevelCreator final :
	public Level
{
public:
	void Start() override;
	void Update() override;

private:
	Vector3 boxSize { 10,10,10 };
	Color wallColor { 239, 123, 69, 255 };
	Vector3 origin { 0,0,0 };

	void AddWallAt(Vector3 pos);

};

