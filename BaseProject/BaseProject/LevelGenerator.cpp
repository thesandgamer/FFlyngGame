#include "LevelGenerator.h"

void LevelGenerator::Start()
{
	//------
	boxSize = { 50,50,50};
	chara = new ChMainCharacter();

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

	aStar.aStarGrid.AddObstacle({ 3,3,3 });
	aStar.aStarGrid.AddObstacle({ 3,3,4 });
	aStar.aStarGrid.AddObstacle({ 3,4,4 });
	path = aStar.GetPath({0, 0, 0}, {4, 4, 4});

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


	for (int xx = 0; xx < aStar.GRID_WIDTH; ++xx)
	{
		for (int yy = 0; yy < aStar.GRID_HEIGHT; ++yy)
		{
			for (int zz = 0; zz < aStar.GRID_LENGTH; ++zz)
			{
				Color col = WHITE;
				Vector3 pos = { (float)xx * boxSize.x  ,(float)yy * boxSize.y ,(float)zz * boxSize.z };

				if (!aStar.aStarGrid.GetNodeByPos({xx,yy,zz})->traversable)
				{
					col = BLACK;
					DrawCube(pos, boxSize.x, boxSize.y, boxSize.z, BLACK);

				}
				else
				{
					DrawCubeWires(pos, boxSize.x, boxSize.y, boxSize.z, col);

				}
			}
		}
	}

	for (auto pathPos : path)
	{
		Vector3 pos = { (float)pathPos.x * boxSize.x  ,(float)pathPos.y * boxSize.y ,(float)pathPos.z * boxSize.z };
		DrawCube(pos, boxSize.x, boxSize.y, boxSize.z, RED);
	}

	

}
