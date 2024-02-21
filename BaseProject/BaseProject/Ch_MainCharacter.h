#pragma once

#include <iostream>
//#include "reasings.h"             

#include "P_Collision.h"
#include "BoxCollision.h"
#include "RaycastCollision.h"

#include "AC_FirstPersonCamera.h"
#include "PhysicBody.h"
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

	PhysicBody pb;

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

	SphereCollision bodyCol{ 2 };

	//----------- Transform ------------

	Vector3 pos{4,20,4};
	Vector3 forwardVector{ 1,0,0 };

	//----GoUp ---------
	void GoUp();
	void GoDown();

	float jumpVelocity = 8;
	float fallMultiplier = 3.5f;
	float lowJumpMultiplier = 2.0f;

	bool isGrounded{ false };

	float airControl{ 0.1f };

	//-----For movement
	void Move();


	bool dir[4]{0,0,0,0};
	Vector3 direction{0,0,0};
	float actualSpeed{0};
	Vector3 acc{ 0,0 ,0};
	Vector3 vel{ 0,0 ,0};


	const float maxSpeed{20};
	const float upDownSpeed{10};
	const float acceleration{0};
	const float deceleration{-2};


	//---------For shoot ----------

	Vector3 GetForwardVector();
	Vector3 GetVector(Vector3 dir);

	AC_Shoot shootingComponent{1,Layer4};

	//-----------Dash----------

	void Dash();
	float dashForce{ 350 };
	bool canDash{ true };



};

