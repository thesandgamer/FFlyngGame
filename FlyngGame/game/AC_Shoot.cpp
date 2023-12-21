#include "AC_Shoot.h"
#include "Projectile.h"

#include <assert.h>

AC_Shoot::AC_Shoot()
{
}

AC_Shoot::~AC_Shoot()
{
}

AC_Shoot::AC_Shoot(float cooldown):shootSpeed(cooldown)
{
}

AC_Shoot::AC_Shoot(float cooldown, CollisionLayer layerToProjectileCollide) :shootSpeed(cooldown), projectileCollideWith{layerToProjectileCollide}
{

}

void AC_Shoot::Start()
{
}

void AC_Shoot::Update()
{
	//------------Pour faire qu'on puisse shoot que tout les xs
	if (timer)
	{
		currentCooldown -= GetFrameTime();
		if (currentCooldown <= 0)
		{
			timer = false;
			canShoot = true;
		}
	}
	//-----------
	for (auto i = projectiles.begin(); i != projectiles.end(); i++)
	{
		if (*i)
		{
			(*i)->Update();

		}
	}
	for (Projectile* proj : projectilesToDestroy)
	{
		projectiles.erase(std::find(projectiles.begin(), projectiles.end(), proj));
		delete proj;
	}
	projectilesToDestroy.clear();

}

void AC_Shoot::Draw()
{
	for (auto i = projectiles.begin(); i != projectiles.end(); i++)
	{
		if (*i)
		{
			(*i)->Draw();
		}
	}
}


void AC_Shoot::Shoot(Vector3 position, Vector3 direction, float force)
{
	if (canShoot)
	{
		canShoot = false;
		projectiles.emplace_back(new Projectile(position, { direction.x * force,direction.y * force ,direction.z * force }, projectileCollideWith,this));
		StartTimer();
	}
}

void AC_Shoot::StartTimer()
{
	timer = true;
	currentCooldown = shootSpeed;
}


void AC_Shoot::RemoveProjectile(Projectile* projectile)
{
	assert(projectile);
	for (auto i = projectiles.begin(); i != projectiles.end(); ++i)
	{
		if ((*i) == projectile)
		{
			//(*i).release();
			projectilesToDestroy.push_back((*i));
			//projectiles.erase(i);
			break;
		}

	}

}