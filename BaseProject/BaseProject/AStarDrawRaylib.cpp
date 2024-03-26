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
	Vector3 startPos = {(float)manager_.startNode.GetPosition().x * boxSize.x,(float)manager_.startNode.GetPosition().y * boxSize.y,(float)manager_.startNode.GetPosition().z * boxSize.z};
	Vector3 endPos = { (float)path[0].x * boxSize.x,(float)path[0].y * boxSize.y,(float)path[0].z * boxSize.z };
	DrawLine3D(startPos, endPos, RED);

	for (int i = 0; i < path.size(); ++i)
	{
		
		startPos = { (float)path[i].x * boxSize.x,(float)path[i].y * boxSize.y,(float)path[i].z * boxSize.z};

		if (i+1< path.size())
		{
			endPos = { (float)path[i + 1].x * boxSize.x,(float)path[i + 1].y * boxSize.y,(float)path[i + 1].z * boxSize.z };
		}
		else
		{
			endPos = startPos;
		}
		DrawSphereWires(startPos, 5, 8, 8, RED);

		DrawLine3D(startPos, endPos,RED);
	}

}

void AStarDrawRaylib::DrawStartEnd()
{
	Vector3 startPos = { (float)manager_.startNode.GetPosition().x * boxSize.x,(float)manager_.startNode.GetPosition().y * boxSize.y,(float)manager_.startNode.GetPosition().z * boxSize.z };
	Vector3 endPos = { (float)manager_.goalNode.GetPosition().x * boxSize.x,(float)manager_.goalNode.GetPosition().y * boxSize.y,(float)manager_.goalNode.GetPosition().z * boxSize.z };
	DrawSphere(startPos, 10, YELLOW);
	DrawSphere(endPos, 10, GREEN);

}


Vector3 AStarDrawRaylib::PosInGridToPosInWorld(Vector3 posInGrid)
{

	return {posInGrid.x * boxSize.x,posInGrid.y * boxSize.y,posInGrid.z * boxSize.z };
}

AStar::Vector3Pos AStarDrawRaylib::PosInWorldToPosInGrid(Vector3 posInWorld)
{
	return { (int) (posInWorld.x / boxSize.x),(int)(posInWorld.y / boxSize.y),(int)(posInWorld.z / boxSize.z) };

}
