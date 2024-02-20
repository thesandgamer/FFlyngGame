#include "PhysicBody.h"

void PhysicBody::Update()
{
	//Fall();
	ProcessVelocity();
}

void PhysicBody::AddForce(const Vector3 force)
{
	velocity.x += force.x;
	velocity.y += force.y;
	velocity.z += force.z;


	acc.x = velocity.x;
	acc.y = velocity.y;
	acc.z = velocity.z;
	
}

void PhysicBody::Fall()
{
	const float dt = GetFrameTime();


	refPos->z += ((dt * velocity.z) + (0.5f * acceleration * dt * dt));

	//if (AnticipateCollisions::NextMoveIsColliding(colliderToCheckForCollisions, nextPos)) return;


	//++ToDo: refacto pour que �a fasse un truc qui marche vraiment bien
	//refPos = &nextPos;
	



}

void PhysicBody::ProcessVelocity()
{
	float dt = GetFrameTime();


	//On d�fnit les valeur maxes

	//Fricction : on r�duit l'acc�l�ration

	acc.x += deccValue * vel.x;
	acc.y += deccValue * vel.y;
	acc.z += deccValue * vel.z;


	DrawRay({ *refPos,Vector3Normalize(vel) }, 50, WHITE);

	

	if (colliderToCheckForCollisions != nullptr)
	{
		if (colliderToCheckForCollisions->IsColliding())	//ToDo: il faudrait un check collision at next tick
		{
			//ToDo: r�cup�rer la normal de l'impact, le comparer avec la velocit� avec un dot product, et appliquer une force inverse en fonction
			Vector3 normal = colliderToCheckForCollisions->GetNormalOfCollidingObjects();



			float dotValue = Vector3DotProduct(velocity, normal);

			Vector3 bounce = {velocity.x - 2*dotValue*normal.x,
								velocity.y - 2*dotValue*normal.y,
								velocity.z - 2*dotValue*normal.z};

			// bounce = velocity - 2(Vector3DotProduct(velocity,normal)) * normal;
			//AddForce(Vector3Multiply(velocity,{-2,-2,-2}));
			AddForce({bounce.x* bouncingValue ,bounce.y* bouncingValue,bounce.z* bouncingValue });
			/*
			refPos->x -= dt * vel.x + 0.5f * acc.x * dt * dt *10;
			refPos->z -= dt * vel.y + 0.5f * acc.y * dt * dt*10;
			refPos->y -= dt * vel.z + 0.5f * acc.z * dt * dt*10;
			*/
			//return;
		}
		
	}


	std::cout << "velocity: " << velocity.x << " " << velocity.y << " " << velocity.z << std::endl;

	//On repositionne avec une acc�l�ration	
	refPos->x += dt * vel.x + 0.5f * acc.x * dt * dt ;
	refPos->y += dt * vel.y + 0.5f * acc.y * dt * dt;
	refPos->z += dt * vel.z + 0.5f * acc.z * dt * dt;



	//std::cout << "acc: " << acc.x << " " << acc.y << " " << acc.z << std::endl;


	//Acc = acc�l�ration de l'acteur, se rapproche de 0 
	//Vel = v�locit� de l'acteur : se rapproche de la valeur max de velcit� ou de 0 en fonction de si acc�l�re ou d�cl��re

	//Quand on relache la touche, l'acc�ration passe donc � la valeur inverse de v�locit�, et va donc diminuer avec le temps


	velocity.x -= dt * acc.x;
	velocity.y -= dt * acc.y;
	velocity.z -= dt * acc.z;

	//std::cout << "velocity: " << velocity.x << " " << velocity.y << " " << velocity.z << std::endl;


	//acc = { 0,0 ,0 };
}


