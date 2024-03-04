#pragma once
#include "SphereCollision.h"
#include "AC_Shoot.h"
#include "MovingActor.h"

class Ennemy: public MovingActor
{
public:
	Ennemy();
	Ennemy(Vector3 pos, float detectionRadius);


	void Start() override;
	void Draw() override;
	void Update() override;

	SphereCollision* GetTriggerCollider() { return &triggerCollider; }

private:

	SphereCollision triggerCollider;
	AC_Shoot shootComponenet{2,Layer4};

	void Shoot();
	void ReloadShoot();


	Transform* target{ nullptr }; //La target que va cibler l'ennemi
};

