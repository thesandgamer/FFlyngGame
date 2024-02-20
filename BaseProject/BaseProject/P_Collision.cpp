#include "P_Collision.h"

#include "CollisionManager.h"

P_Collision::P_Collision()
{
	CollisionManager::GetInstance()->AddCollider(this);//Rajoute tout seul la boite de collisoon au manager à la création
}

P_Collision::~P_Collision()
{
	CollisionManager::GetInstance()->RemoveCollider(this);//On enlève le pointeur de la liste des colliders
	collisions.clear();
	transform = nullptr;
}

bool P_Collision::IsColliding()
{
	if (collisions.size() > 0)	//Si on à des collisions
	{
		for each (P_Collision* col in collisions)//Pour chaque collider avec lequel on collide
		{
			if (!col->trigger)//Si il ne trigger pas
			{
				return true;//Il y a collision
			}
		}
	}
	return false;//Sinob si pas de collision où que des trigger pas de colliding
}

Vector3 P_Collision::GetNormalOfCollidingObjects()
{
	if (collisions.size() > 0)	//Si on à des collisions
	{
		for each (P_Collision * col in collisions)//Pour chaque collider avec lequel on collide
		{
			Ray ray = { GetPosition(),Vector3Remove(col->GetPosition(),GetPosition()) };

			if (col->collisionType == BoxCollider)
			{
				RayHitInfo info = GetRayCollisionBox(ray,static_cast<BoxCollision*>(col)->GetBoundingBox());
 				return info.normal;
			}
		}
	}

	return Vector3();
}



