#pragma once
#include "CubeActor.h"
#include "PhysicBody.h"

class MovingActor
{
public:
	virtual void Init();
	virtual void Start();
	virtual void Update();
	virtual void Draw();

	void SetPos(Vector3 newPos) { transf.translation = newPos; }
	bool IsGrounded() const { return isGrounded; }
	Vector3 GetPosition() const { return transf.translation; }

	P_Collision* GetCollider() const { return bodyCol; }

protected:
	bool gravity = false;

	PhysicBody pb{};
	Transform transf{ {0,40,0},{0,0,0,0},{1,1,1} };
	bool isGrounded{ false };

	P_Collision* bodyCol = new BoxCollision();


public:

	MovingActor();
	MovingActor(Vector3 spawnPos);
};

