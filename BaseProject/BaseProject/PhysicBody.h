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
	void SetForce(Vector3 force);

	void Reset();

	bool canFall{ true };

	/**\ brief A quel point l'objet est ralenti pendant son mouvement  */
	float friction{ 1 };
	float accValue{ 1 };
	/**\ brief A quel point l'objet perd en vitesse quand il collide */
	float elasticity{ .9f };
	Vector3 acc{ 0,0,0 };	//Acceleration du body
	Vector3 vel{ 0,0 ,0 };


	void SetColliderForCollisionCheck(P_Collision* collider) {colliderToCheckForCollisions = collider;}

	/**
	 * \brief Set à quel point l'objet va rebondir
	 * \param bounciness A quel point l'objet va rebondir, à 0 pas de rebond
	 */
	void SetBounciness(float bounciness) { bouncingValue = bounciness; }

private:
	Vector3* refPos{nullptr};

	void Fall();
	void ProcessVelocity();

	float bouncingValue {1};

	P_Collision* colliderToCheckForCollisions ;



	
};

