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
    bodyCol.showCollisions = true;

    /*
    //---------------
    bodyBox.SetParent(&transf);
    bodyBox.id = 12;
    groundBox.SetParent(&transf);

    forwardRay.SetParent(&transf);//Ajoute le component
    rightRay.SetParent(&transf);//Ajoute le component
    backwarddRay.SetParent(&transf);//Ajoute le component
    leftRay.SetParent(&transf);//Ajoute le component

    //--------------

    groundBox.layer = Layer1;

    forwardRay.layer = Layer1;
    rightRay.layer = Layer1;
    backwarddRay.layer = Layer1;
    leftRay.layer = Layer1;

    //-------------------
    bodyBox.layer = Layer3;
    bodyBox.collideWithLayer = Layer4;//Il ne collisionne avec personne
   // bodyBox.trigger = true;

    
    //-------------//Offset des boites de collision //----------------------------
    groundBox.Offset.translation = { 0,-1.8f,0 };//Place le rayon au pieds

    forwardRay.Offset.translation = { 0,-1.f,0 };
    rightRay.Offset.translation = { 0,-1.f,0 };
    backwarddRay.Offset.translation = { 0,-1.f,0 };
    leftRay.Offset.translation = { 0,-1.f,0 };

    //-----------------
    groundBox.checkingCollision = true;
    bodyBox.checkingCollision = true;

    forwardRay.checkingCollision = true;
    rightRay.checkingCollision = true;
    backwarddRay.checkingCollision = true;
    leftRay.checkingCollision = true;
    //-------
    */
    camera.Start();

    gravity.canFall = false;
    gravity.SetPos(&pos);
    gravity.SetColliderForCollisionCheck(&bodyCol);//Set la boite de collision pour le check des cols de la gravité


    shootingComponent.Start();

}

void Ch_MainCharacter::Draw()
{
    camera.Draw();
    DrawCube({transf.translation.x,transf.translation.y-0.5f,transf.translation.z}, 0.1f, 0.1f, 0.1f, LIME);//Dessine son corps
    bodyCol.Draw();
    /*
    groundBox.Draw();
    //bodyBox.Draw();

    forwardRay.Draw();
    rightRay.Draw();
    leftRay.Draw();
    backwarddRay.Draw();

    */
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
    //Process Gravity

    //--On va d'abord effectuer l'anticipation du mouvement de la gravité
    //Si cette anticipation ne collide pas appliquer le mouvement
    //gravity.canFall = (groundBox.IsColliding()) ? false : true;gravity.Update();
    gravity.Update();

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

    ProcessCollisions();

    Move();

    camera.Update();

   // ProcessJump();

    shootingComponent.Update();

    //if (isGrounded) canDash = true;





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

    if (IsKeyPressed(KEY_SPACE)) Jump();
    if (IsKeyReleased(KEY_SPACE)) StopJumping();

    if (IsKeyDown(KEY_SPACE))
    {
        Jump();
    }
    else if (IsKeyDown(KEY_LEFT_CONTROL))
    {
        GoDown();
    }


    if (IsMouseButtonDown(0))
    {  
        shootingComponent.Shoot(pos, Vector3Multiply(GetForwardVector(),{1,1,1}),110);
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
    gravity.SetForce({ xValue * maxSpeed , yValue * maxSpeed ,zValue * maxSpeed });

    transf.translation = pos;   //Bouge le transform du character 



}

void Ch_MainCharacter::BaseMovement(float xValue, float yValue)
{
    maxSpeed = 10;

    xValue *= maxSpeed;
    yValue *= maxSpeed;

    pos.x += xValue * GetFrameTime();
    pos.z += yValue * GetFrameTime();
}

void Ch_MainCharacter::AccelerationFrictionMove(float xValue, float yValue, float zValue)
{
    float dt = GetFrameTime();
    
    //On défnit les valeur maxes
    xValue *= maxSpeed;
    yValue *= maxSpeed;
    zValue *= maxSpeed;

    acc.x = xValue;
    acc.y = yValue;
    acc.z = zValue;

    //Fricction : on réduit l'accélération
    acc.x += deceleration * vel.x;
    acc.y += deceleration * vel.y;
    acc.z += deceleration * vel.z;

    //On repositionne avec une accélération
    pos.x += dt * vel.x + 0.5f * acc.x * dt * dt;
    pos.z += dt * vel.y + 0.5f * acc.y * dt * dt;
    pos.y += dt * vel.z + 0.5f * acc.z * dt * dt;

    //On augmente la vélocité
    vel.x += dt * acc.x;
    vel.y += dt * acc.y;
    vel.z += dt * acc.z;

    acc = { 0,0 ,0};
}

void Ch_MainCharacter::MoveWithEasing(float xValue, float yValue)
{
    //Utiliser du lerp avec du easing pour lerper la valeur de 
    //actual speed entre 0 et max speed
    //puis changer la position avec xValue * actual speed
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
}

void Ch_MainCharacter::ProcessCollisions()
{
    //++ToDo: faire en sorte qu'en cas de collisions, replace à la position d'avant
    //Voir la prochaine position, voir si ça collide, si ça collide on avance pas 

    /*
    forwardRay.SetDirection(GetVector({ 0,0,-1 }));
    rightRay.SetDirection(GetVector({ 1,0,0 }));
    backwarddRay.SetDirection(GetVector({ 0,0,1 }));
    leftRay.SetDirection(GetVector({ -1,0,0 }));

    //Place Ray to futur position
    forwardRay.Transform->translation = pos;
    rightRay.Transform->translation = pos;
    backwarddRay.Transform->translation = pos;
    leftRay.Transform->translation = pos;
    */
    //Change State

   // state = (groundBox.IsColliding()) ? InAir : Grounded;
   // isGrounded = groundBox.IsColliding();

    //std::cout << "X: " << vel.x << " Y: " << vel.y << "\n";
    //++ToDo: faire en sorte de bien faire les collisions
    //---------------
    /*
    if (forwardRay.IsColliding()) {
        collisionDirection |= Front;    //Ajoute collision front
        dir[0] = false;
        vel = { 0,0 };
    }
    else collisionDirection ^= Front;

    if (rightRay.IsColliding()) {
        collisionDirection |= Right;    //Ajoute collision 
        dir[2] = false;
        vel = { 0,0 };
    }
    else collisionDirection ^= Right;    //Enlève collision 

    if (backwarddRay.IsColliding()) {
        collisionDirection |= Back;    //Ajoute collision 
        dir[1] = false;
        vel = { 0,0 };
    }
    else collisionDirection ^= Back;

    if (leftRay.IsColliding()) {
        collisionDirection |= Left;    //Ajoute collision 
        dir[3] = false;
        vel = { 0,0 };
    }
    else collisionDirection ^= Left;
    */

    //Détécter si on touche un mur, arrète la chute, et on peut resauter

}

void Ch_MainCharacter::Jump()
{
    gravity.SetForce({ 0,0,maxSpeed });
    /*
    if (!isGrounded) return;
   // if (state == InAir) return;
    gravity.velocity = { 0,jumpVelocity,0 };//Ajoute une force de saut
    inJump = true;
    //Pour désactiver la collision pour pouvoir décoller du sol
    groundBox.checkingCollision = false;
    groundBox.collisions = {};

    Sound jmp = Utility::GetInstance()->jumpSound;
    //PlaySound(jmp);*/

}

void Ch_MainCharacter::ProcessJump()
{
    /*
    float dt = GetFrameTime();


    if (gravity.velocity.y < 0) //Quand on chute
    {
        gravity.velocity.y += 1 * -GRAVITY_VALUE * (fallMultiplier - 1) * dt;
        groundBox.checkingCollision = true;


    }
    else if (gravity.velocity.y > 0 && !IsKeyDown(KEY_SPACE))//Quand on est en saut sans appuyer sur la touche de saut
    {
        gravity.velocity.y += 1 * -GRAVITY_VALUE * (lowJumpMultiplier - 1) * dt;

    }*/
}

void Ch_MainCharacter::StopJumping()
{

}

void Ch_MainCharacter::GoDown()
{
    gravity.SetForce({ 0,0,-maxSpeed });
}


void Ch_MainCharacter::Dash()
{
    if (canDash)
    {
        //gravity.velocity = { GetForwardVector().x * dashForce,GetForwardVector().y * dashForce, GetForwardVector().z * dashForce };
        gravity.SetForce({ GetForwardVector().x * dashForce,GetForwardVector().y * dashForce, GetForwardVector().z * dashForce });
       // canDash = false;
    }

}
