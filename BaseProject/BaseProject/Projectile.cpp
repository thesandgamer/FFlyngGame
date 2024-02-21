#include "Projectile.h"
#include "CollisionManager.h"
#include "AC_Shoot.h"

Projectile::Projectile(Vector3 position, Vector3 launchForce, CollisionLayer layer, AC_Shoot* parentP): parent{parentP}
{
	transform.translation = position;
	collider.layer = layer;
	Start();
	AddForce(launchForce);
}

Projectile::~Projectile()
{
	//CollisionManager::GetInstance()->RemoveCollider(&collider);
	//delete &collider;
}

void Projectile::Start()
{
	pb.SetPos(&transform.translation);
	pb.SetBounciness(1);
	pb.friction = 0;

	collider.SetParent(&transform);
	collider.checkingCollision = true;
}

void Projectile::Draw()
{
	DrawCube(transform.translation, transform.scale.x, transform.scale.y, transform.scale.z, WHITE);
	collider.Draw();
}

void Projectile::Update()
{
	pb.Update();

	if (collider.IsColliding())
	{
		std::cout << "Projectile Collide" << std::endl;
		parent->RemoveProjectile((this));
	}
}

std::shared_ptr<BoxCollision> Projectile::GetCollider()
{ return std::make_shared<BoxCollision>(collider); }

void Projectile::AddForce(Vector3 force)
{
	pb.AddForce(force);
}
