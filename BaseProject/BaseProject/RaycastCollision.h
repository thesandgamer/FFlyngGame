#pragma once
#include "P_Collision.h"


class RaycastCollision :
    public P_Collision
{
public:
    RaycastCollision();
    RaycastCollision(Vector3 directionP, float lengthP);
    RaycastCollision(Vector3 pos, Vector3 directionP, float lengthP);
    ~RaycastCollision();

    void Draw() override;

    Ray GetRay();

    void Test() {};

    float GetLength() { return length; }

    void SetDirection(Vector3 dir) { direction = dir; }

private:
    Vector3 direction{0,0,0};
    float length{ 0 };

};

