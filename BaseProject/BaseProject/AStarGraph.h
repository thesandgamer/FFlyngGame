#pragma once
#include <vector>

#include "AStarNode.h"


namespace AStar
{


class AStarGraph
{
public:

    AStarGraph(Vector3Pos pos);
    AStarGraph() = default;
    ~AStarGraph() = default;

    int graphWidth;
    int graphHeight;
    int graphLength;

    std::vector<AStarNode> graphNodes{}; //Liste des nodes dans le jeu

    double getCostOfNode(const AStarNode& current, const AStarNode&  next);

    AStarNode* GetNodeByPos(Vector3Pos nodePos);
    AStarNode* GetNodeByRef(const AStarNode& node);


    std::vector<AStarNode*> GetAroundNodes(const AStarNode current);

    void AddObstacles(std::vector<Vector3Pos> positions);
    void AddObstacle(Vector3Pos position);
    void RemoveObstacle(Vector3Pos position);


};

}
