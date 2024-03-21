#include "AStarNode.h"

namespace AStar
{



AStarNode::AStarNode(int x, int y, int z) : x(x), y(y), z(z), cost(0), cameFrom(nullptr), traversable(true)
{
}

AStarNode::AStarNode() : x(-1), y(-1), z(-1), cost(-1), cameFrom(nullptr), traversable(false)
{
}

AStarNode::~AStarNode()
	= default;



}

