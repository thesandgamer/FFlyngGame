#include "AStarGraph.h"

#include "CubeActor.h"

namespace AStar
{


    AStarGraph::AStarGraph(Vector3Pos pos): graphWidth(0), graphHeight(0), graphLength(0)
    {
	    for (int xx = 0; xx < pos.x; xx++) //Lignes
	    {
		    for (int yy = 0; yy < pos.y; yy++) //Colognes
		    {
				for (int zz = 0; zz < pos.z; zz++) //Colognes
				{
					//graphNodes.push_back(AStarNode(xx,yy,zz));
					graphNodes.emplace_back(xx,yy,zz);
				}
		    }
	    }
    }


    double AStarGraph::getCostOfNode(const AStarNode& current, const AStarNode& next)
    {
        auto it = find(graphNodes.begin(), graphNodes.end(), current);
        if (it != graphNodes.end())
        {
            int index = distance(graphNodes.begin(), it);
            return graphNodes.at(index).cost;

        }

        return -1;
    }

    AStarNode* AStarGraph::GetNodeByPos(Vector3Pos nodePos)
    {
        auto it = find(graphNodes.begin(), graphNodes.end(), nodePos);
        if (it != graphNodes.end())
        {
            int index = distance(graphNodes.begin(), it);
            return &graphNodes.at(index);

        }
        else
        {
            return nullptr;
        }
    }

    AStarNode* AStarGraph::GetNodeByRef(const AStarNode& node)
    {
        auto it = find(graphNodes.begin(), graphNodes.end(), node);
        if (it != graphNodes.end())
        {
            int index = distance(graphNodes.begin(), it);
            return &graphNodes.at(index);

        }
        return nullptr;
    }

    std::vector<AStarNode*> AStarGraph::GetAroundNodes(const AStarNode current)
    {
        std::vector<AStarNode*> nodes{};
        /*
        int i = 0;
        //On va parcourir les 9 tiles
        for (int xx = -1; xx < 2; xx++)
        {
            for (int yy = -1; yy < 2; yy++)
            {
                if (xx == 0 && yy == 0) continue;
                if (current.x + xx >= 0 && current.x + xx < graphWidth && current.y + yy >= 0 && current.y + yy < graphHeight) //Check si on est dans la grille
                {
                    Node newNode = GetNode({current.x + (float)xx, current.y + (float)yy });// Node(Vector2(current.x + xx, current.y + yy));
                    nodes.push_back(newNode);
                    i++;
                }

            }
        }*/

        /*
        for(int xx = -1; xx <= 1 ; xx++)
        {
            for (int yy = -1; yy <= 1; yy++)
            {
                for (int zz = -1; zz <= 1; zz++)
                {
                    nodes.push_back(GetNodeByPos({ current.x + xx,current.y + yy,current.z + zz }));
                }
            }
        }*/

        
        nodes.push_back(GetNodeByPos({ current.x - 1, current.y + 0,current.z + 0}));
        nodes.push_back(GetNodeByPos({ current.x + 1, current.y + 0,current.z - 0}));

        nodes.push_back(GetNodeByPos({ current.x - 0, current.y - 1,current.z + 0}));
        nodes.push_back(GetNodeByPos({ current.x + 0, current.y + 1,current.z - 0}));

        nodes.push_back(GetNodeByPos({ current.x - 0, current.y - 0,current.z + 1}));
        nodes.push_back(GetNodeByPos({ current.x + 0, current.y + 0,current.z - 1}));
        


        return nodes;
    }

    void AStarGraph::AddObstacles(std::vector<Vector3Pos> positions)
    {
        for (Vector3Pos pos : positions)
        {
            AddObstacle(pos);
        }
    }

    void AStarGraph::AddObstacle(Vector3Pos position)
    {
        auto it = find(graphNodes.begin(), graphNodes.end(), position);
        if (it != graphNodes.end())
        {
            int index = distance(graphNodes.begin(), it);
            graphNodes.at(index).traversable = false;

        }
    }
    void AStarGraph::RemoveObstacle(Vector3Pos position)
    {
        auto it = find(graphNodes.begin(), graphNodes.end(), position);
        if (it != graphNodes.end())
        {
            int index = distance(graphNodes.begin(), it);
            graphNodes.at(index).traversable = true;

        }
    }
}
