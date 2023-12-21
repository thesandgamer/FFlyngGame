#pragma once
#include "SphereCollision.h"
#include "AC_Shoot.h"

class Ennemy
{
public:
	Ennemy();
	Ennemy(Vector3 pos, float detectionRadius);
	~Ennemy();


	void Start();
	void Draw();
	void Update();

	SphereCollision* GetCollider() { return &collider; }
	Vector3* GetPos() { return &transform.translation; }

	Transform transform{ {0,0,0},{0,0,0,0},{1,1,1} };

	void Test() { std::cout << "Ennemy functio ntest" << std::endl; }

private:

	SphereCollision collider;
	AC_Shoot shootComponenet{2,Layer4};

	void Shoot();
	void ReloadShoot();


	Transform* target{ nullptr }; //La target que va cibler l'ennemi
};

