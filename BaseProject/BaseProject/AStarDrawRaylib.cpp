#include "AStarDrawRaylib.h"

#include "CubeActor.h"
#include "AStarManager.h"



AStarDrawRaylib::AStarDrawRaylib(Vector3 sizeOfBox, Vector3 sizeOfGrid,AStar::AStarManager& manager): AStarDrawing(), boxSize(sizeOfBox),
                                                                         gridSize(sizeOfGrid), manager_(manager)
{
}

void AStarDrawRaylib::DrawGraph()
{
	for (int xx = 0; xx < gridSize.x; ++xx)
	{
		for (int yy = 0; yy < gridSize.y; ++yy)
		{
			for (int zz = 0; zz < gridSize.z; ++zz)
			{
				Vector3 pos = { (float)xx * boxSize.x  ,(float)yy * boxSize.y ,(float)zz * boxSize.z };

				DrawCubeWires(pos, boxSize.x, boxSize.y, boxSize.z, WHITE);

				
				if (!manager_.aStarGrid.GetNodeByPos({ xx,yy,zz })->traversable)
				{
					DrawCube(pos, boxSize.x, boxSize.y, boxSize.z, BLACK);

				}
			
			}
		}
	}
}

void AStarDrawRaylib::DrawPath(std::vector<AStar::Vector3Pos> path)
{
	for (auto pathPos : path)
	{
		Vector3 pos = { (float)pathPos.x * boxSize.x  ,(float)pathPos.y * boxSize.y ,(float)pathPos.z * boxSize.z };
		DrawCube(pos, boxSize.x, boxSize.y, boxSize.z, RED);
	}
}

void AStarDrawRaylib::DrawStartEnd()
{
}
