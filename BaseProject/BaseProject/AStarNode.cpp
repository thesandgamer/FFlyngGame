#include "AStarNode.h"

namespace AStar
{



AStarNode::AStarNode(int x, int y, int z) : x(x), y(y), z(z), cost(NULL), cameFrom(nullptr), traversable(true)
{
}

AStarNode::AStarNode(Vector3Pos pos): x(pos.x), y(pos.y), z(pos.z), cost(NULL), cameFrom(nullptr), traversable(true)
{
}

AStarNode::AStarNode() : x(-1), y(-1), z(-1), cost(NULL), cameFrom(nullptr), traversable(false)
{
}

AStarNode::~AStarNode()
	= default;



}

