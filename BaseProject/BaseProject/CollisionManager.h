#pragma once
#include "P_Collision.h"
#include "BoxCollision.h"
#include "RaycastCollision.h"
#include "SphereCollision.h"
#include <vector>

#include <iostream>
#include <string>  

class CollisionManager
{
	//--------------Make it a singleton------------------
private:
	CollisionManager() {};
	static CollisionManager* instance;

public:
	CollisionManager(const CollisionManager& obj) = delete;
	void operator=(const CollisionManager&) = delete;

	static CollisionManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new CollisionManager();
		}
		return instance;
	}

//-------------------
public:
	 void Start();
	 void Update();
	 void Draw();

	 void AddCollider(P_Collision* collider);
	 void RemoveCollider(P_Collision* colliderToRemove);


private:


	std::vector<P_Collision*> colliders;
	//std::vector<std::shared_ptr<P_Collision>> colliders;

	void ProcessColisions();



	void DoCollisionBoxsCheck(BoxCollision* colliderToCheck);
	void DoRayBoxCollisionCheck(RaycastCollision* colliderToCheck);
	void DoSphereBoxCollisionCheck(SphereCollision* colliderToCheck);

	void InsertCollision(bool insert, P_Collision* collider, P_Collision* colliderToCheck);

	//++ToDo faire une fonction pour check uniquement les collider proche les uns des autres

};

