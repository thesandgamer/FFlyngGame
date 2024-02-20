#include "PhysicActor.h"

PhysicActor::PhysicActor()
{
}

void PhysicActor::Start()
{
	CubeActor::Start();

	pb.canFall = false;
	pb.SetPos(&transform.translation);
	pb.SetColliderForCollisionCheck(GetCollision());//Set la boite de collision pour le check des cols de la gravité



}

PhysicActor::~PhysicActor()
{
}

void PhysicActor::Draw()
{
	CubeActor::Draw();
	
}

void PhysicActor::Update()
{
	CubeActor::Update();
	pb.AddForce({ 5,0,0 });

	pb.Update();
}
