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

	void SetPos(Vector3* posRefP) { refPos = posRefP; }

	void AddForce(Vector3 force);

	bool canFall{ true };

	float acceleration{ 100 };
	float deccValue{ -2 };
	float accValue{ .5 };
	Vector3 velocity{ 0,0,0 };	//Vers où se dirige le Body
	Vector3 acc{ 0,0,0 };	//Acceleration du body
	Vector3 vel{ 0,0 ,0 };


	void SetColliderForCollisionCheck(P_Collision* collider) {colliderToCheckForCollisions = collider;}

private:
	Vector3* refPos{nullptr};

	void Fall();
	void ProcessVelocity();

	float bouncingValue {2};

	P_Collision* colliderToCheckForCollisions ;



	
};

