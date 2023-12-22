#include "PhysicBody.h"

void PhysicBody::Update()
{
	//Fall();
	ProcessVelocity();
}

void PhysicBody::SetForce(const Vector3 force)
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

	//Y a t'il contact au prochain emplacement:
		//Oui: je d�place et replace au contact
		//Non: je d�place au prochain emplacement

	//Il va falloir v�rifier si il y a collision au prochain emplacement que prendra la collision
	//Si la collision ne colisionne pas on va bouger l'objet � son prochain emplacement
	//Si il y a une collision alors on va calculer o� on doit replacer l'objet puis on va le replacer � cet endroit
	if (colliderToCheckForCollisions != nullptr)
	{
		if (colliderToCheckForCollisions->IsColliding())
		{
			SetForce(Vector3Multiply(velocity,{-2,-2,-2}));
			/*
			refPos->x -= dt * vel.x + 0.5f * acc.x * dt * dt *10;
			refPos->z -= dt * vel.y + 0.5f * acc.y * dt * dt*10;
			refPos->y -= dt * vel.z + 0.5f * acc.z * dt * dt*10;
			*/
			//return;
		}
		
	}



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


