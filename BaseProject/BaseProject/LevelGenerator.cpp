#include "LevelGenerator.h"

#include "AStarDrawRaylib.h"

void LevelGenerator::Start()
{
	//------
	boxSize = { 50,50,50};
	chara = new MovingCharacter();

	/*
	for (int xx = 0; xx < maxSizeOfMap.x; ++xx)
	{
		for (int yy = 0; yy < maxSizeOfMap.y; ++yy)
		{
			for (int zz = 0; zz < maxSizeOfMap.z; ++zz)
			{
				Vector3 pos = pos = { (xx) * boxSize.x,
			(yy) * boxSize.y,
			(zz) * boxSize.z };
				AddWallAt({ pos });
			}
		}
	}*/

	/*
	aStar = new AStar::AStarManager(5, 5, 5);

	aStar->SetDrawing(new AStarDrawRaylib(boxSize, { (float)aStar->GRID_WIDTH,(float)aStar->GRID_HEIGHT,(float)aStar->GRID_LENGTH }, *aStar));

	aStar->aStarGrid.AddObstacle({ 3,3,3 });
	aStar->aStarGrid.AddObstacle({ 3,3,4 });
	aStar->aStarGrid.AddObstacle({ 3,4,4 });
	path = aStar->GetPath({0, 0, 0}, {4, 4, 4});*/

	for (auto vector3_pos : path)
	{
		std::cout << vector3_pos.x << " " << vector3_pos.y << " " << vector3_pos.z << "\n";
	}
	std::cout << std::endl;
	//---------
	Level::Start();
}

void LevelGenerator::Update()
{
	Level::Update();
}

void LevelGenerator::Draw()
{
	Level::Draw();

	//aStar->DrawAStarDebug();

	

}
