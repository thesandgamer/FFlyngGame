#include "AStarManager.h"

#include <iostream>

#include "AStarDrawRaylib.h"

namespace AStar
{
	AStarManager::AStarManager(const int width, const int height, const int length): aStarGrid({width, height, length}),
		GRID_WIDTH(width),
		GRID_HEIGHT(height), GRID_LENGTH(length)
	{
	}


	std::vector<Vector3Pos> AStarManager::GetPath(Vector3Pos startPos, Vector3Pos endPos)
	{
        //===========]Initialisation[===========//
        openList.Clear();
        closedList.Clear();

        startNode = AStarNode(startPos);
        startNode.cameFrom = &startNode;
        goalNode = AStarNode(endPos);

        openList += startNode;

        //=====================================//

        while (!openList.nodeList.empty())
        {
            current = openList.FindLowestValue();

            //===========]Debug[===========//
            /*
            cout<< endl << "Selected/Current Node = " << current.x<<" " << current.y <<" f_cost: "<<current.cost << endl;
            cout << "Dans la liste de choix: ";
            for (Node nd : openList.nodeList)
            {
                cout << nd.cost<<" ";
            }
            cout << endl;
            */
            //=============================//


            openList -= current;
            closedList += current;

            if (current == goalNode)
            {
                break;//La recherche du chemin est fini
            }

            //C'est là qu'on va décider quel sera le prochain node à calculer
            for (AStarNode* nextNode : aStarGrid.GetAroundNodes(current))
            {
                if (nextNode == nullptr) continue;
                if (closedList.IsInList(*nextNode) || !aStarGrid.GetNodeByPos(nextNode->GetPosition())->traversable) //Si le node à déjà été vérifié ou si il n'est pas traversable
                {
                    continue; //Passe au voisin suivant
                }

                //On va définir le cout du prochain node
                double newCost = CalculateFCostOfNode(nextNode->GetPosition(), startNode.GetPosition(), goalNode.GetPosition());

                if (newCost < nextNode->cost || !openList.IsInList(*nextNode))//Si le chemin à un plus petit cout que le node qui est check ou si il n'est pas dans open(donc pas encore check)
                {
                    //Du coup c'est ce node qu'on va prendre
                    nextNode->cost = newCost; //On va set son f cost            
                    nextNode->cameFrom = &current; //Dit que le node vien du node current
                    nextNode->cameFrom = aStarGrid.GetNodeByRef(current); //Dit que le node vien du node current
                    if (!openList.IsInList(*nextNode))
                    {
                        openList += *nextNode;
                    }
                }
            }


        }
        if (current != goalNode)
        {
            std::cout << "Path not find" << std::endl;
            std::cout << "Position asked: " << endPos.x << " " << endPos.y << std::endl;
            return {};
        }
        std::vector<Vector3Pos> path = CalculatePath();

        calculatedPath = path;
        return path;
	}

	void AStarManager::DrawAStarDebug(bool showGrid, bool showStartEnd ) const
	{
        if (aStarDrawing)
        {
            if (showGrid)
            {
                aStarDrawing->DrawGraph();  
            }

            if (calculatedPath.size() > 0)
            {
                aStarDrawing->DrawPath(calculatedPath);

            }
        }
	}

	std::vector<Vector3Pos> AStarManager::CalculatePath()
	{ 
		std::vector<Vector3Pos> path;
		while (current != startNode)
		{
			path.push_back(current.GetPosition());
			current = closedList.FindInList(*current.cameFrom);
		}
		//path.push_back(startNode.positon);
		reverse(path.begin(), path.end());

		return path;
	}
}
