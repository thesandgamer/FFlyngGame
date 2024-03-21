#include "AStarList.h"
#include <algorithm>
#include <iostream>

namespace AStar
{
    void AStarList::Add(AStarNode newNode)
    {
        nodeList.push_back(newNode);
    }

    AStarNode& AStarList::FindInList(AStarNode node)
    {
        auto it = find(nodeList.begin(), nodeList.end(), node);
        if (it != nodeList.end())
        {
            int index = distance(nodeList.begin(), it);
            return nodeList.at(index);

        }
        else
        {
            std::cout << "NOT FOUND IN THE LIST" << std::endl;
        }
    }

    bool AStarList::IsInList(AStarNode node)
    {
        auto it = find(nodeList.begin(), nodeList.end(), node);
        if (it != nodeList.end())
        {
            return true;

        }
        return false;
    }

    AStarNode& AStarList::FindLowestValue()
    {
        return *std::min_element(nodeList.begin(), nodeList.end());
    }

    void AStarList::Clear()
    {
        nodeList.clear();
    }





}
