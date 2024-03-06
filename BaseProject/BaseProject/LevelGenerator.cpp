#include "LevelGenerator.h"

void LevelGenerator::Start()
{
	//------
	boxSize = { 50,50,50};
	chara = new ChMainCharacter();

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
	}

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
}
