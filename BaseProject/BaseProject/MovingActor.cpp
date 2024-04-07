#include "MovingActor.h"

#include "SphereCollision.h"

MovingActor::MovingActor()
{
}

MovingActor::MovingActor(Vector3 spawnPos)
{
    transf.translation = spawnPos;
}


void MovingActor::Init()
{
    //----------Set body collider
    //bodyCol = new SphereCollision(1);
    bodyCol->SetParent(&transf);
    bodyCol->id = 12;
    bodyCol->checkingCollision = true;
    bodyCol->showCollisions = true;

    //----------Set Physics body
    pb.SetPos(&transf.translation);
    pb.SetColliderForCollisionCheck(bodyCol);//Set la boite de collision pour le check des cols de la gravité
    pb.canFall = false;
    pb.SetBounciness(1);
    pb.friction = .9f;
    pb.elasticity = .7f;
}

void MovingActor::Start()
{
    MovingActor::Init();

}

void MovingActor::Update()
{
    pb.Update();
    
}

void MovingActor::Draw()
{
    bodyCol->Draw();
    pb.Draw();
}

Vector3 MovingActor::GetForwardVector() const
{
    Quaternion rotation = transf.rotation;
    rotation = QuaternionInvert(rotation);
    Vector3 dir = { 0,0,-1 };//Forward
    return Vector3RotateByQuaternion(dir, rotation);
}

