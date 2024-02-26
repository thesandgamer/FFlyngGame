#include "MovingCharacter.h"

void MovingCharacter::Start()
{
    //----------Set camera
    camera.SetParent(&transf);
    camera.Start();


    //----------Set body collider
    bodyCol.SetParent(&transf);
    bodyCol.id = 12;
    bodyCol.checkingCollision = true;
    bodyCol.layer = Layer3;
    bodyCol.showCollisions = false;

    //----------Set Physics body
    pb.SetPos(&transf.translation);
    pb.SetColliderForCollisionCheck(&bodyCol);//Set la boite de collision pour le check des cols de la gravit�
    pb.canFall = false;
    pb.SetBounciness(2);
    pb.friction = 2;
    pb.elasticity = .9f;
}

void MovingCharacter::Update()
{
    //Process PhysicBody
    pb.Update();

    //Process inputs
    ProcessInputs();

    //Set la rotation du chara en yaw: on fait une matrice de rotation avec le camera x (l'axe vertical)
    transf.rotation = QuaternionFromMatrix(MatrixRotateXYZ({ 0, PI * 2 - camera.GetAngle().x, 0 }));

    //Bouge le character
    Move();

    //Update la camera
    camera.Update();

}

void MovingCharacter::Draw()
{
    camera.Draw();
    bodyCol.Draw();
}

void MovingCharacter::DrawUi()
{
    DrawFPS(20, 20);
}

void MovingCharacter::Death()
{
    SetPos({ 4,20,4 });
    pb.Reset();
}

Vector3 MovingCharacter::GetForwardVector() const
{
    Quaternion rotation = camera.offsetTransform.rotation;
    rotation = QuaternionInvert(rotation);
    Vector3 dir = { 0,0,-1 };//Forward
    return Vector3RotateByQuaternion(dir, rotation);
}

void MovingCharacter::Move()
{
    float xValue =
        (sinf(camera.GetAngle().x) * dir[1] -   
            sinf(camera.GetAngle().x) * dir[0] -    
            cosf(camera.GetAngle().x) * dir[3] +    
            cosf(camera.GetAngle().x) * dir[2]);    

    float yValue =
        (cosf(camera.GetAngle().x) * dir[1] -
            cosf(camera.GetAngle().x) * dir[0] +
            sinf(camera.GetAngle().x) * dir[3] -
            sinf(camera.GetAngle().x) * dir[2]);

    float zValue =
        (sinf(camera.GetAngle().y) * dir[0] -
            sinf(camera.GetAngle().y) * dir[1]);

    pb.AddForce({ xValue * maxSpeed , zValue * maxSpeed ,yValue * maxSpeed });
}

void MovingCharacter::GoUp()
{
    pb.AddForce({ 0,upDownSpeed,0 });
}

void MovingCharacter::GoDown()
{
    pb.AddForce({ 0,-upDownSpeed,0 });
}

void MovingCharacter::ProcessInputs()
{
    dir[0] = IsKeyDown(KEY_W); //Devant
    dir[1] = IsKeyDown(KEY_S);
    dir[2] = IsKeyDown(KEY_D);
    dir[3] = IsKeyDown(KEY_A);


    if (IsKeyDown(KEY_SPACE))
    {
        GoUp();
    }
    else if (IsKeyDown(KEY_LEFT_CONTROL))
    {
        GoDown();
    }
}
