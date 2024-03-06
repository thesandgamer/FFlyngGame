#pragma once
#include "AC_FirstPersonCamera.h"
#include "MovingActor.h"
#include "SphereCollision.h"

enum CharacterMovementState {
	Grounded,
	InAir,
};



class MovingCharacter : public MovingActor
{
public:
	void Start() override;
	void Update() override;
	void Draw() override;
	virtual void DrawUi();

	void Death();

	Vector3 GetForwardVector() const override;

	Camera& GetCamera() { return camera.GetCamera(); }
	AC_FirstPersonCamera& GetFirstPersonCam() { return camera; }


protected:
	AC_FirstPersonCamera camera{};

	//-----------For movement----------
	void Move();

	void GoUp();
	void GoDown();

	bool dir[4]{ 0,0,0,0 };

	/**\brief Vitesse de déplacement */
	float maxSpeed{ 70 };
	/**\brief Vitesse de déplacement en Vertical seulement */
	float upDownSpeed{ 50 };

	/** \brief A quel point le déplacement perd en vitesse*/
	float friction{ 1.5f };


	//---------Inputs
	virtual void ProcessInputs();

	CharacterMovementState state{ InAir };


public:

	MovingCharacter();
	virtual ~MovingCharacter() = default;

	MovingCharacter(Vector3 startPos, float maxSpeed, float upDownSpeed);

};

