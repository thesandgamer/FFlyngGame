#include "PhysicActor.h"

PhysicActor::PhysicActor(): pb()
{
}

PhysicActor::PhysicActor(const Vector3& posP, const Vector3& sizeP, const Color& colorP)
	: CubeActor(posP, sizeP, colorP), pb()
{
}

void PhysicActor::Start()
{
	CubeActor::Start();
	collision.id = 20;
	collision.layer = Layer3;
	collision.checkingCollision = true;
	collision.showCollisions = true;


	pb.canFall = false;
	pb.SetPos(&transform.translation);
	pb.SetColliderForCollisionCheck(GetCollision());//Set la boite de collision pour le check des cols de la gravité
	pb.SetBounciness(1);
	pb.friction = .9f;
	pb.elasticity = 1;
	pb.canFall = true;

	pb.AddForce({ 500,0 ,500 });
	//pb.AddForce({ 0,-200 ,0 });


}

PhysicActor::~PhysicActor()
{
}

void PhysicActor::Draw()
{
	CubeActor::Draw();

	pb.Draw();
	
}

void PhysicActor::Update()
{
	CubeActor::Update();

	pb.Update();


}
