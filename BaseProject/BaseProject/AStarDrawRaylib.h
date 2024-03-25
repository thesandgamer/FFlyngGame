#pragma once
#include <vector>

#include "AStarDrawing.h"
#include "AStarNode.h"
#include "CubeActor.h"

namespace AStar
{
	class AStarManager;
}

class AStarDrawRaylib: public AStar::AStarDrawing
{
public:
	AStarDrawRaylib(Vector3 sizeOfBox, Vector3 sizeOfGrid, AStar::AStarManager& manager);
	void DrawGraph() override;
	void DrawPath(std::vector<AStar::Vector3Pos> path) override;
	void DrawStartEnd() override;

	/*
	 Vector3 PosInGridToPosInWorld(Vector3 posInGrid);
	 AStar::Vector3Pos PosInWorldToPosInGrid(Vector3 posInWorld);
	 */

private:
	Vector3 boxSize {10,10,10};
	Vector3 gridSize {10,10,10};

	AStar::AStarManager& manager_;
};

