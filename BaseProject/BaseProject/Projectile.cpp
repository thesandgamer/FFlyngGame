#include "Projectile.h"
#include "CollisionManager.h"
#include "AC_Shoot.h"

Projectile::Projectile(Vector3 position, Vector3 launchForce, CollisionLayer layer, AC_Shoot* parentP): MovingActor(), parent{parentP}
{
	bodyCol = new BoxCollision({ 1,1,1 });
	transf.translation = position;
	bodyCol->layer = layer;

	Start();
	AddForce(launchForce);
}



void Projectile::Start()
{
	MovingActor::Start();
	pb.canFall = false;
	pb.friction = 0;
}

void Projectile::Draw()
{
	MovingActor::Draw();

	DrawCube(transf.translation, transf.scale.x, transf.scale.y, transf.scale.z, WHITE);
}

void Projectile::Update()
{
	MovingActor::Update();


	if (bodyCol->IsColliding())
	{
		std::cout << "Projectile Collide" << std::endl;
		parent->RemoveProjectile((this));
	}
}


void Projectile::AddForce(Vector3 force)
{
	pb.AddForce(force);
}
