#pragma once
#include "SphereCollision.h"
#include "AC_Shoot.h"
#include "AStarManager.h"
#include "MovingActor.h"



class Ennemy: public MovingActor
{
	//ToDo: faire un mesh pour l'ennemi, et r�ussir � faire en sorte de tourner cet ennemi en fonction de son d�placement ou de sa cible si il en a une

public:
	Ennemy();
	Ennemy(Vector3 pos, float detectionRadius);


	void Start() override;
	void Draw() override;
	void Update() override;

	SphereCollision* GetTriggerCollider() { return &triggerCollider; }

	void MoveToLocation(Vector3& posToGo);

	void InitAStar(AStar::AStarManager& ref) { astarLink = &ref; }

private:

	SphereCollision triggerCollider;
	AC_Shoot shootComponenet{2,EnnemyProjectileCollision };

	void Shoot();
	void ReloadShoot();

	AStar::AStarManager* astarLink = nullptr;


	Transform* target{ nullptr }; //La target que va cibler l'ennemi
};

