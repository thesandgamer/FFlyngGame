#pragma once
#include <vector>
#include <iostream>

#include "Projectile.h"

class AC_Shoot
{
public:
	friend class Projectile;

	AC_Shoot();
	~AC_Shoot();
	AC_Shoot(float cooldown);
	AC_Shoot(float cooldown, CollisionLayer layerToProjectileCollide= Layer2);

	void Start();
	void Update();
	void Draw();

	void Shoot(Vector3 position,Vector3 direction, float force = 1);



private:
	float shootSpeed{ 1 };
	float currentCooldown{ 0 };
	bool  canShoot{true};
	
	void RemoveProjectile(Projectile* projectile);


	std::vector<Projectile*> projectiles;
	std::vector<Projectile*> projectilesToDestroy;

	bool timer{ false };
	void StartTimer();


	CollisionLayer layer{Layer1};
	CollisionLayer projectileCollideWith{Layer0};



};

