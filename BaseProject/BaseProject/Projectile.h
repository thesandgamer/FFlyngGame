#pragma once
#include "PhysicBody.h"
#include "BoxCollision.h"	
#include "CubeActor.h"	
#include "MovingActor.h"

class AC_Shoot;
//++ToDo: rempalcer par Sphere collision
//++ToDo: Détruit quand touche : remplacer pointeurs par smart pointers



/**
 * \brief Classe de base pour les projectiles
 */
class Projectile : public MovingActor
{
public:
	friend class AC_Shoot;

	Projectile(Vector3 position, Vector3 launchForce, CollisionLayer layer = BodyColliders, AC_Shoot* parentP = nullptr);

	void Start() override;
	void Draw() override;
	void Update() override;



	void AddForce(Vector3 force);

private:

	AC_Shoot* parent;

public:

	Projectile() = default;
};

