#include "BoxCollision.h"

BoxCollision::BoxCollision()
{
}

BoxCollision::BoxCollision(Vector3 sizeP) : P_Collision()
{
	Offset.scale = sizeP;
}



void BoxCollision::Draw()
{
	if(showCollisions)
		DrawBoundingBox(GetBoundingBox(), (IsColliding()) ? RED : GREEN);
}

BoundingBox BoxCollision::GetBoundingBox()
{
	if (transform == nullptr) return { {0,0,0},{0,0,0} };
	return  { Vector3{ (transform->translation.x + Offset.translation.x) - (transform->scale.x * Offset.scale.x / 2) ,
						(transform->translation.y + Offset.translation.y) - (transform->scale.y * Offset.scale.y / 2 ),
						(transform->translation.z + Offset.translation.z) - (transform->scale.z * Offset.scale.z / 2 )},
			Vector3{(transform->translation.x +Offset.translation.x) + (transform->scale.x * Offset.scale.x / 2 ) ,
					(transform->translation.y + Offset.translation.y) + (transform->scale.y * Offset.scale.y / 2 ) ,
					(transform->translation.z + Offset.translation.z) + (transform->scale.z * Offset.scale.z / 2 ) } };;
}
