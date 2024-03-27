#pragma once
#include "SphereCollision.h"
#include "AC_Shoot.h"
#include "AStarManager.h"
#include "MovingActor.h"



class Ennemy: public MovingActor
{
	//ToDo: faire un mesh pour l'ennemi, et réussir à faire en sorte de tourner cet ennemi en fonction de son déplacement ou de sa cible si il en a une

public:
	Ennemy();
	Ennemy(Vector3 pos, float detectionRadius);


	void Start() override;
	void Draw() override;
	void Update() override;

	SphereCollision* GetTriggerCollider() { return &triggerCollider; }

	void MoveToLocation(Vector3* posToGo);

	void InitAStar(AStar::AStarManager& ref) { astarLink = &ref; }

private:

	SphereCollision triggerCollider;
	AC_Shoot shootComponenet{2,EnnemyProjectileCollision };

	void Shoot();
	void ReloadShoot();

	void MakeMovement();

	AStar::AStarManager* astarLink = nullptr;
	std::vector<AStar::Vector3Pos> currentPath;

	float currentTime = 0;
	int it = 0;



	Transform* target{ nullptr }; //La target que va cibler l'ennemi
};

