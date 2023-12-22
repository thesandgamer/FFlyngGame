#pragma once
#include "P_Collision.h"

struct Sphere {
	Vector3 Center{ 0,0,0 };
	float Radius{ 1 };

};

class SphereCollision :
    public P_Collision
{
public:
	SphereCollision();
	SphereCollision(float radius);

	void Draw();

	Sphere GetCollider(); //++Todo Renvoyer un pointeur de bounding box

	void Test() {};

private:
	float rad{ 1 };

};

