#include "SphereCollision.h"

SphereCollision::SphereCollision()
{
}

SphereCollision::SphereCollision(float radius) : P_Collision()
{
    collisionType = SphereCollider;
    rad = radius;
}

void SphereCollision::Draw()
{
    if (trigger)
    {
        if (showCollisions)
        {
            DrawSphereWires(GetCollider().Center, GetCollider().Radius, 20, 20, (IsColliding()) ? RED : GREEN);
        }
    }
    else
    {
    	if (showCollisions)
	    {
	    	DrawSphere(GetCollider().Center, GetCollider().Radius, (IsColliding()) ? RED : GREEN);
            DrawSphereWires(GetCollider().Center, GetCollider().Radius, 20, 20, (IsColliding()) ? RED : GREEN);

	    }
    }
}

Sphere SphereCollision::GetCollider()
{
    if (transform == nullptr) return{-1,-1,-1,-1} ;
    return { {transform->translation.x + Offset.translation.x,
          transform->translation.y + Offset.translation.y,
          transform->translation.z + Offset.translation.z },
        rad
    };
}
