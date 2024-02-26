#pragma once
#include "AC_FirstPersonCamera.h"
#include "PhysicBody.h"
#include "SphereCollision.h"

enum CharacterMovementState {
	Grounded,
	InAir,
};



class MovingCharacter
{
public:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void DrawUi();

	void Death();
	void SetPos(Vector3 newPos) { transf.translation = newPos; }
	bool IsGrounded() const { return isGrounded; }

	Vector3 GetPosition() const { return transf.translation; }

	Vector3 GetForwardVector() const;
	P_Collision* GetBodyCollider() { return &bodyCol; }

	Camera& GetCamera() { return camera.GetCamera(); }
	AC_FirstPersonCamera& GetFirstPersonCam() { return camera; }


protected:
	AC_FirstPersonCamera camera{};
	SphereCollision bodyCol{ 2 };

	//-----------For movement----------
	void Move();

	void GoUp();
	void GoDown();

	bool dir[4]{ 0,0,0,0 };

	/**\brief Vitesse de déplacement */
	float maxSpeed{ 60 };
	/**\brief Vitesse de déplacement en Vertical seulement */
	float upDownSpeed{ 30 };


	//---------Inputs
	virtual void ProcessInputs();


	PhysicBody pb {};
	Transform transf{ {0,0,0},{0,0,0,0},{1,1,1} };

	CharacterMovementState state{ InAir };
	bool isGrounded{ false };


public:

	MovingCharacter() = default;
	virtual ~MovingCharacter() = default;

	MovingCharacter(Vector3 startPos,float maxSpeed, float upDownSpeed)
		: maxSpeed(maxSpeed), upDownSpeed(upDownSpeed)
	{
		transf.translation = startPos;
	}

};

