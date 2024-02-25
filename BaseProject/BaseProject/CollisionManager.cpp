#include "CollisionManager.h"

void CollisionManager::Start()
{
}

void CollisionManager::Update()
{
	ProcessColisions();
}

void CollisionManager::Draw()
{
}

void CollisionManager::AddCollider(P_Collision* collider)
{
	colliders.push_back(collider);
	//colliders.emplace(colliders.begin(), collider);
}

void CollisionManager::RemoveCollider(P_Collision* colliderToRemove)
{
	if (colliderToRemove == nullptr) return;
	colliders.erase(std::find(colliders.begin(), colliders.end(), colliderToRemove));
	
}

void CollisionManager::ProcessColisions()
{
	for each (P_Collision* collider in colliders) //On va récupérer un collider et regarder si il collide avec les autres collider
	{
		if (!collider->checkingCollision)continue;
		//++ToDo: checker si les deux collider ont le même parent, ou si l'un est parent de l'autre, et avoir un bool pour savoir si on veut désactiver les collisons entre eux
		switch (collider->collisionType)
		{
		case BoxCollider:
			DoCollisionBoxsCheck(dynamic_cast<BoxCollision*>(collider));
		break;

		case RayCollider:
			DoRayBoxCollisionCheck(dynamic_cast<RaycastCollision*>(collider));	//Si c'est le rayon qui check ses collisions
		break;

		case SphereCollider:
			DoSphereBoxCollisionCheck(dynamic_cast<SphereCollision*>(collider));
		break;

		default:
			break;
		}
	}
}


/// <summary>
/// On check les collisions entre des BB et d'autres BB
/// </summary>
/// <param name="colliderToCheck"></param>
void CollisionManager::DoCollisionBoxsCheck(BoxCollision* colliderToCheck)
{
	for each (P_Collision* collider in colliders)
	{
		if (colliderToCheck == collider) continue;
		if (colliderToCheck->collideWithLayer != collider->layer) continue;	//Si le collider ne collide pas avec le layer de l'autre objet
		bool collide = false;
		switch (collider->collisionType)
		{
		case BoxCollider:	//Si l'autre est une boite
			collide = CheckCollisionBoxes(colliderToCheck->GetBoundingBox(), dynamic_cast<BoxCollision*>(collider)->GetBoundingBox());
			break;
		case RayCollider:	//Si l'autre est un rayon
			RayHitInfo hitinfo = GetRayCollisionBox(dynamic_cast<RaycastCollision*>(collider)->GetRay(), colliderToCheck->GetBoundingBox());
			collide = hitinfo.hit && abs( hitinfo.distance) <= dynamic_cast<RaycastCollision*>(collider)->GetLength();
			break;
		case SphereCollider:	//Si l'autre est une sphère
			collide = CheckCollisionBoxSphere(colliderToCheck->GetBoundingBox(),
				dynamic_cast<SphereCollision*>(collider)->GetCollider().Center, dynamic_cast<SphereCollision*>(collider)->GetCollider().Radius);
			break;
		default:
			break;
		}
		InsertCollision(collide, collider, colliderToCheck);

	
	
	}
}

void CollisionManager::DoRayBoxCollisionCheck(RaycastCollision* colliderToCheck)
{
	for each (P_Collision * collider in colliders)
	{
		if (colliderToCheck == collider) continue;
		if (colliderToCheck->collideWithLayer != collider->layer) continue;
		bool collide = false;

		switch (collider->collisionType)
		{

		case BoxCollider:
			RayHitInfo hitinfo = GetRayCollisionBox(colliderToCheck->GetRay(), dynamic_cast<BoxCollision*>(collider)->GetBoundingBox());
			collide = hitinfo.hit && abs( hitinfo.distance) <= colliderToCheck->GetLength();
			break;

		case SphereCollider:
			RayHitInfo hit = GetRayCollisionSphere(colliderToCheck->GetRay(),
				dynamic_cast<SphereCollision*>(collider)->GetCollider().Center, 
				dynamic_cast<SphereCollision*>(collider)->GetCollider().Radius);
			collide = hit.hit && abs(hit.distance) <= colliderToCheck->GetLength();
			break;

		default:
			break;

		}		
		InsertCollision(collide, collider, colliderToCheck);

	}
}

void CollisionManager::DoSphereBoxCollisionCheck(SphereCollision* colliderToCheck)//Une sphère va check les autres collisons
{
	for each (P_Collision * collider in colliders)
	{
		if (colliderToCheck == collider) continue;
		if (colliderToCheck->collideWithLayer != collider->layer) continue;
		bool collide{ false };

		switch (collider->collisionType)
		{

		case BoxCollider:
			collide = CheckCollisionBoxSphere(dynamic_cast<BoxCollision*>(collider)->GetBoundingBox(),
				colliderToCheck->GetCollider().Center, colliderToCheck->GetCollider().Radius);
			if (collide)
			{
				//std::cout << "col: "<< collider->layer << std::endl;
			}
			break;

		case RayCollider:
			RayHitInfo hit = GetRayCollisionSphere(dynamic_cast<RaycastCollision*>(collider)->GetRay(),
				colliderToCheck->GetCollider().Center, colliderToCheck->GetCollider().Radius);
			collide = hit.hit && abs(hit.distance) <= dynamic_cast<RaycastCollision*>(collider)->GetLength();

			break;

		case SphereCollider:
			collide = CheckCollisionSpheres(colliderToCheck->GetCollider().Center, colliderToCheck->GetCollider().Radius,
				dynamic_cast<SphereCollision*>(collider)->GetCollider().Center, dynamic_cast<SphereCollision*>(collider)->GetCollider().Radius);
			break;

		default:
			break;

		}
		InsertCollision(collide, collider, colliderToCheck);

	}
}

void CollisionManager::InsertCollision(bool insert, P_Collision* collider, P_Collision* colliderToCheck)
{
	bool colliderToCheckAlreadyInCollider = std::find(collider->collisions.begin(), collider->collisions.end(), colliderToCheck) != collider->collisions.end();
	bool colliderAlreadyInColliderToCheck = std::find(colliderToCheck->collisions.begin(), colliderToCheck->collisions.end(), collider) != colliderToCheck->collisions.end();
	if (insert)
	{
		if (!colliderAlreadyInColliderToCheck)
		{
			colliderToCheck->collisions.insert(collider);
		}
		if (!colliderToCheckAlreadyInCollider)
		{
			//collider->collisions.insert(colliderToCheck);
		}
	}
	else
	{
		
		colliderToCheck->collisions.erase(collider);
		//collider->collisions.erase(colliderToCheck);

	}
}


