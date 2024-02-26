#include "Ch_MainCharacter.h"

#include "Utility.h"  

void ChMainCharacter::Start()
{
    MovingCharacter::Start();
    shootingComponent.Start();

}

void ChMainCharacter::Draw()
{
    MovingCharacter::Draw();
    shootingComponent.Draw();

}

void ChMainCharacter::DrawUi()
{
    MovingCharacter::DrawUi();

    //Dessiner le curseur   
    DrawTextureEx(Utility::GetInstance()->dotTexture, 
        {static_cast<float>(screenWidth) / 2 ,
        static_cast<float>(screenHeight) / 2  },
        0, 0.02f, WHITE);
}

void ChMainCharacter::Update()
{
    MovingCharacter::Update();

    shootingComponent.Update();
}

void ChMainCharacter::ProcessInputs()
{
    MovingCharacter::ProcessInputs();

    if (IsMouseButtonDown(0))
    {
        shootingComponent.Shoot(GetPosition(), Vector3Multiply(GetForwardVector(),{1,1,1}),3500);
    }
    if (IsMouseButtonPressed(1))
    {
        Dash();
    }
}

void ChMainCharacter::Dash()
{
    if (canDash)
    {
        //pb.velocity = { GetForwardVector().x * dashForce,GetForwardVector().y * dashForce, GetForwardVector().z * dashForce };
        pb.AddForce({ GetForwardVector().x * dashForce,GetForwardVector().y * dashForce, GetForwardVector().z * dashForce });
       // canDash = false;
    }

}

