#pragma once

#include <iostream>
//#include "reasings.h"             

#include "P_Collision.h"
#include "BoxCollision.h"
#include "RaycastCollision.h"

#include "AC_FirstPersonCamera.h"
#include "Gravity.h"
#include "AC_Shoot.h"
#include "SphereCollision.h"

enum CharacterMovementState {
	Grounded,
	InAir,
};

class Ch_MainCharacter
{
public:

	void Start();
	void Draw();
	void DrawUi();
	void Update();

	Camera& GetCamera() { return camera.GetCamera(); }
	AC_FirstPersonCamera& GetFirstPersonCam() { return camera; }

	void ProcessInputs();

	P_Collision* GetGroundCollider() { return &bodyCol; }
	P_Collision* GetForwardRayRay() { return &bodyCol; }
	P_Collision* GetBodyCollider() { return &bodyCol; }

	Gravity gravity;

	CharacterMovementState state{ Grounded };

	Transform transf{ {0,0,0},{0,0,0,0},{1,1,1} };
	
	bool IsGrounded() { return isGrounded; }

	
	void SetPos(Vector3 newPos) { pos = newPos; }

	void Death();

private:
	//----------COmponenets---------
	//++ToDo: vector de component parent*
	AC_FirstPersonCamera camera{};

	//----
	//BoxCollision bodyBox{ Vector3{1,1.80f,1} };
	void ProcessCollisions();

	SphereCollision bodyCol{ 2 };
	/*
	BoxCollision groundBox{Vector3{0.8,0.2f,0.8f} };
	BoxCollision bodyBox{Vector3{0.5,1.5f,0.5f} };

	RaycastCollision forwardRay{ {1,0,0},.50f };
	RaycastCollision rightRay{ {1,0,0},.50f };
	RaycastCollision backwarddRay{ {1,0,0},.50f };
	RaycastCollision leftRay{ {1,0,0},0.50f };
	*/
	//Créer 4 boites de collisions 
	std::uint8_t collisionDirection;

	//----------- Transform ------------

	Vector3 pos{4,20,4};
	Vector3 forwardVector{ 1,0,0 };

	//----Jump ---------
	void Jump();
	void ProcessJump();
	void StopJumping();
	void GoDown();

	float jumpVelocity = 8;
	float fallMultiplier = 3.5f;
	float lowJumpMultiplier = 2.0f;

	bool inJump;
	bool isGrounded{ false };

	float airControl{ 0.1f };

	//-----For movement
	void Move();

	void BaseMovement(float xValue, float yValue);
	void AccelerationFrictionMove(float xValue, float yValue, float zValue = 0);
	void MoveWithEasing(float xValue, float yValue);

	bool dir[4]{0,0,0,0};
	Vector3 direction{0,0,0};
	float actualSpeed{0};
	Vector3 acc{ 0,0 ,0};
	Vector3 vel{ 0,0 ,0};


	float maxSpeed{100};
	float acceleration{0};
	float deceleration{-2};


	//---------For shoot ----------

	Vector3 GetForwardVector();
	Vector3 GetVector(Vector3 dir);

	AC_Shoot shootingComponent{1,Layer4};

	//-----------Dash----------

	//++ToDo: faire en sorte qu'on puisse dash quand on est au sol(pb avec gravity) ou pas en fonction du design
	void Dash();
	float dashForce{ 20 };
	bool canDash{ true };



};

