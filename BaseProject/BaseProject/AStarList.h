#pragma once
#include "AStarNode.h"
#include <vector>

namespace AStar
{

class AStarList
{
public:
    AStarList() {};
    ~AStarList() {};


    //=============]Variables[======================//
    std::vector<AStarNode> nodeList{};


    //=============]Fonctions[======================//
    void Add(AStarNode newNode);

    AStarNode& FindInList(AStarNode node);

    bool IsInList(AStarNode node);

    AStarNode& FindLowestValue();

    void Clear();


    //=============]Operators[======================//

    AStarList& operator+=(const AStarNode& other) {

        this->nodeList.push_back(other);
        return *this;
    }
    AStarList& operator-=(const AStarNode& other) {

        this->nodeList.erase(std::find(this->nodeList.begin(), this->nodeList.end(), other));
        return *this;
    }

};

}
