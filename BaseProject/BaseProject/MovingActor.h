#pragma once
#include "CubeActor.h"
#include "PhysicBody.h"

class MovingActor
{
public:
	virtual void Start();
	virtual void Update();
	virtual void Draw();

	void SetPos(Vector3 newPos) { transf.translation = newPos; }
	bool IsGrounded() const { return isGrounded; }
	Vector3 GetPosition() const { return transf.translation; }

protected:
	bool gravity = false;

	PhysicBody pb{};
	Transform transf{ {0,40,0},{0,0,0,0},{1,1,1} };
	bool isGrounded{ false };

	P_Collision* bodyCol = nullptr;


public:

	MovingActor() = default;
	MovingActor(Vector3 spawnPos);
};

