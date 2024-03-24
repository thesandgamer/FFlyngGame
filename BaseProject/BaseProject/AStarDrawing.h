#pragma once
#include <vector>

#include "AStarNode.h"

namespace AStar
{

class AStarDrawing
{
public:
	AStarDrawing();

	virtual void DrawGraph() {}
	virtual void DrawPath(std::vector<AStar::Vector3Pos> path) {}
	virtual void DrawStartEnd() {}


private:

};




}
