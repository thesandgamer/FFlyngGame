#pragma once
#include "raylib.h"
#include "raymath.h"

#include <iostream>
#include "P_Collision.h"
#include "AnticipateCollisions.h"

#define GRAVITY_VALUE 9.807

class PhysicBody
{
public:
	void Update();
	void Draw();

	void SetPos(Vector3* posRefP) { refPos = posRefP; }

	void AddForce(Vector3 force);

	void Reset();

	bool canFall{ true };

	float friction{ -2 };
	float accValue{ 1 };
	Vector3 acc{ 0,0,0 };	//Acceleration du body
	Vector3 vel{ 0,0 ,0 };


	void SetColliderForCollisionCheck(P_Collision* collider) {colliderToCheckForCollisions = collider;}

	void SetBounciness(float bounciness) { bouncingValue = bounciness; }

private:
	Vector3* refPos{nullptr};

	void Fall();
	void ProcessVelocity();

	float bouncingValue {2};

	P_Collision* colliderToCheckForCollisions ;



	
};

