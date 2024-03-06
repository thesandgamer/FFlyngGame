#pragma once
#include "Level.h"

class LevelCreator :
	public Level
{
public:
	void Start() override;
	void Update() override;
	void Draw() override;
	P_Collision* CalculateWhereRemoveActor();

	void CalculateWherePosActor();

protected:
	Vector3 boxSize { 10,10,10 };
	Color wallColor { 239, 123, 69, 255 };
	Vector3 origin { 0,0,0 };

	void AddWallAt(Vector3 pos);

	Vector3 putPos {};
	Ray ray{};
	RayHitInfo hitInfo {};


};

