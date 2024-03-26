#pragma once
#include <memory>

namespace AStar
{

    struct Vector3Pos
    {
        int x = { -1 };
        int y = { -1 };
        int z = { -1 };
        bool operator==(const Vector3Pos& vector3_pos) const { return (x == vector3_pos.x && y == vector3_pos.z && z == vector3_pos.z); };
    };

class AStarNode
{
public:
    //=========================]Constructeurs[=========================//
    AStarNode(int x, int y, int z);
    AStarNode(Vector3Pos pos);
    AStarNode();
    ~AStarNode();

    //=========================]Variables[=========================//
public:
    Vector3Pos GetPosition() const { return { x,y,z }; }

    int x;
    int y;
    int z;
    double cost;
    AStarNode* cameFrom;//Juste un lien vers un autre node, utiliser un * pour que ça puisse être nulptr
    //std::shared_ptr<AStarNode> cameFrom;
    bool traversable;


    //=========================] OPERATORS [=========================//
    bool operator ==(const AStarNode& other) const
    {
        if (this->x == other.x && this->y == other.y && this->z == other.z) return true;
        return false;
    }
    bool operator !=(const AStarNode& other) const
    {
        if (this->x == other.x && this->y == other.y && this->z == other.z) return false;
        return true;
    }


    //
    bool operator>(const AStarNode& other) const
    {
        if (this->cost > other.cost) return true;
        return false;
    }
    bool operator>=(const AStarNode& other) const
    {
        if (this->cost >= other.cost) return true;
        return false;
    }

    bool operator<(const AStarNode& other) const
    {
        if (this->cost < other.cost) return true;
        return false;
    }
    bool operator<=(const AStarNode& other) const
    {
        if (this->cost <= other.cost) return true;
        return false;
    }

    //
    AStarNode& operator =(const AStarNode& other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->cameFrom = other.cameFrom;
        this->cost = other.cost;
        this->traversable = other.traversable;
        return *this;
    }
};

}
