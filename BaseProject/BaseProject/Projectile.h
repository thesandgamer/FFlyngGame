#pragma once
#include "PhysicBody.h"
#include "BoxCollision.h"	
#include "CubeActor.h"	

class AC_Shoot;
//++ToDo: rempalcer par Sphere collision
//++ToDo: Détruit quand touche : remplacer pointeurs par smart pointers



/**
 * \brief Classe de base pour les projectiles
 */
class Projectile
{
public:
	friend class AC_Shoot;

	Projectile(Vector3 position, Vector3 launchForce, CollisionLayer layer = Layer2, AC_Shoot* parentP = nullptr);
	~Projectile();

	void Start();
	void Draw();
	void Update();


	std::shared_ptr<BoxCollision> GetCollider();

	void AddForce(Vector3 force);

private:
	PhysicBody pb{};

	BoxCollision collider { Vector3{1,1,1} };

	Transform transform { {0,0,0},{ 0,0,0,0},{0.2f,0.2f,0.2f} };

	AC_Shoot* parent;

public:

	Projectile() = default;
};

