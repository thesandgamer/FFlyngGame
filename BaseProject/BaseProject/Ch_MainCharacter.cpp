#include "Ch_MainCharacter.h"

#include <string>

#include "Utility.h"  

void Ch_MainCharacter::Start()
{
    //-----------------
    camera.SetParent(&transf);


    bodyCol.SetParent(&transf);
    bodyCol.id = 12;
    bodyCol.checkingCollision = true;
    bodyCol.layer = Layer3;
    bodyCol.showCollisions = false;

    camera.Start();

    pb.canFall = false;
    pb.SetPos(&pos);
    pb.SetColliderForCollisionCheck(&bodyCol);//Set la boite de collision pour le check des cols de la gravité


    shootingComponent.Start();

}

void Ch_MainCharacter::Draw()
{
    camera.Draw();
    DrawCube({transf.translation.x,transf.translation.y-0.5f,transf.translation.z}, 0.1f, 0.1f, 0.1f, LIME);//Dessine son corps
    bodyCol.Draw();

    shootingComponent.Draw();

    //-----------


}

void Ch_MainCharacter::DrawUi()
{
    //Dessiner le curseur   
    DrawTextureEx(Utility::GetInstance()->dotTexture, 
        {(float)screenWidth / 2 ,
        (float)screenHeight / 2  },
        0, 0.02f, WHITE);
    
}

void Ch_MainCharacter::Update()
{
    //Process PhysicBody
    pb.Update();

    //Process inputs
    ProcessInputs();



    //Set la rotation du chara en yaw: on fait une matrice de rotation avec le camera x (l'axe vertical)
    transf.rotation = QuaternionFromMatrix(MatrixRotateXYZ({ 0, PI * 2 - camera.GetAngle().x, 0 }));

    //---------
    /*
    if (bodyBox.IsColliding())
    {
        //++ToDo: takes damages
        Death();
        std::cout << "BodyCollide" << std::endl;
    }*/
    
    //-------------


    Move();

    camera.Update();


    shootingComponent.Update();






}

void Ch_MainCharacter::ProcessInputs()
{

    if (IsKeyDown(KEY_W))
    {
        direction.x = 1;
    }
    else if (IsKeyDown(KEY_S))
    {
        direction.x = -1;
    }
    else
    {
        direction.x = 0;
    }
    if (IsKeyDown(KEY_D))
    {
        direction.y = 1;
    }
    else if (IsKeyDown(KEY_A))
    {
        direction.y = -1;
    }
    else
    {
        direction.y = 0;
    }

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


    if (IsMouseButtonDown(0))
    {  
        shootingComponent.Shoot(pos, Vector3Multiply(GetForwardVector(),{1,1,1}),3500);
    }
    if (IsMouseButtonPressed(1))
    {
        Dash();
    }
}



void Ch_MainCharacter::Move()
{
    //ToDo++ camera bubble activable avec variable exposé de force

    //---------------------Gère la direction dans laquelle aller
    //On regarde tous les inputs pour faire les diagonales 
    float xValue =
        (sinf(camera.GetAngle().x) * dir[1] -   //Touche vers le bas
            sinf(camera.GetAngle().x) * dir[0] -    //Touche vers le haut
            cosf(camera.GetAngle().x) * dir[3] +    //Touche à droite
            cosf(camera.GetAngle().x) * dir[2]);    //Touchce à gauche

    float yValue =
        (cosf(camera.GetAngle().x) * dir[1] -
            cosf(camera.GetAngle().x) * dir[0] +
            sinf(camera.GetAngle().x) * dir[3] -
            sinf(camera.GetAngle().x) * dir[2]);

    float zValue =
        (sinf(camera.GetAngle().y) * dir[0] -
            sinf(camera.GetAngle().y) * dir[1]);


    //------------------Va déplacer le character
   // BaseMovement(xValue, yValue);
   // AccelerationFrictionMove(xValue, yValue, zValue); //Bouge la position 
    pb.SetForce({ xValue * maxSpeed , zValue * maxSpeed ,yValue * maxSpeed });

    transf.translation = pos;   //Bouge le transform du character 



}


Vector3 Ch_MainCharacter::GetForwardVector()
{
    Quaternion rotation = camera.offsetTransform.rotation;//{0,0.38268,0,0.92388};//Rotation à 45°
    rotation = QuaternionInvert(rotation);
    Vector3 dir = { 0,0,-1 };                  //Forward
    return Vector3RotateByQuaternion(dir, rotation);
}

Vector3 Ch_MainCharacter::GetVector(Vector3 dir)
{
    //Quaternion rotation = camera.offsetTransform.rotation;//{0,0.38268,0,0.92388};//Rotation à 45°
    Quaternion rotation = transf.rotation;
    rotation = QuaternionInvert(rotation);
    return Vector3RotateByQuaternion(dir, rotation);
}

void Ch_MainCharacter::Death()
{
    SetPos({ 4,20,4 });
    pb.velocity = { 0,0,0 };
}


void Ch_MainCharacter::GoUp()
{
    pb.SetForce({ 0,upDownSpeed,0 });
}



void Ch_MainCharacter::GoDown()
{
    pb.SetForce({ 0,-upDownSpeed,0 });
}


void Ch_MainCharacter::Dash()
{
    if (canDash)
    {
        //pb.velocity = { GetForwardVector().x * dashForce,GetForwardVector().y * dashForce, GetForwardVector().z * dashForce };
        pb.SetForce({ GetForwardVector().x * dashForce,GetForwardVector().y * dashForce, GetForwardVector().z * dashForce });
       // canDash = false;
    }

}
