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

