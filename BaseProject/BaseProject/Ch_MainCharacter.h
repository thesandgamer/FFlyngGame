#pragma once

#include <iostream>
//#include "reasings.h"             


#include "Ac_LifeSystem.h"
#include "AC_Shoot.h"
#include "MovingCharacter.h"

class ChMainCharacter: public MovingCharacter
{
public:

	void Start() override;
	void Draw() override;
	void DrawUi() override;
	void Update() override;


	
private:

	void ProcessInputs() override;
	//---------For shoot ----------
	AC_Shoot shootingComponent{1,PlayerProjectileCollision};

	//-----------Dash----------
	void Dash();


private:
	float dashForce{ 1500 };
	bool canDash{ true };

	AcLifeSystem lifeManager{20};


};

