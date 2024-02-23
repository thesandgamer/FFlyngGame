#include "PhysicBody.h"

#include <string>

#include "Maths.h"

void PhysicBody::Update()
{
	//Fall();
	ProcessVelocity();
}

void PhysicBody::Draw()
{
	DrawRay({ *refPos,Vector3Normalize(vel) }, Vector3Length(vel), WHITE);
	//DrawRay({ *refPos,{1,0,0}}, 5, WHITE);
	//DrawSphere(*refPos, 5, WHITE);
}

void PhysicBody::AddForce(const Vector3 force)
{

	vel.x += force.x;
	vel.y += force.y;
	vel.z += force.z;

	
	acc.x = vel.x;
	acc.y = vel.y;
	acc.z = vel.z;
}

void PhysicBody::SetForce(Vector3 force)
{
	vel.x = force.x;
	vel.y = force.y;
	vel.z = force.z;


	acc.x = vel.x;
	acc.y = vel.y;
	acc.z = vel.z;
}

void PhysicBody::Reset()
{
	acc = Vector3Zero();
	vel = Vector3Zero();
}

void PhysicBody::Fall()
{
	const float dt = GetFrameTime();


	//refPos->z += ((dt * velocity.z) + (0.5f * acceleration * dt * dt));

	//if (AnticipateCollisions::NextMoveIsColliding(colliderToCheckForCollisions, nextPos)) return;
	if (canFall)
	{
		AddForce({ 0,-9.81f,0 });
	}

	//++ToDo: refacto pour que ça fasse un truc qui marche vraiment bien
	//refPos = &nextPos;



}

void PhysicBody::ProcessVelocity()
{
	float dt = GetFrameTime();

	
	//Vector3CrossProduct();

	//ToDo: Futur position: vérifier la collision au tick suivant, c'est à dire effectuer le déplacement de la collision à sa postion au tick suivant
	// ensuite vérifier si il y a collision avec d'autres collisions, si non attend le check des autres puis effectue son déplacement,
	// par contre si collision on ne déplace pas l'acteur à la position finale mais à la position de l'impact moins la taille de la collision(comment faire ça je sais pas)
	// Long collision: si la boite se déplace très loin on va faire un raycast et replacer à la position de l'impact moins la taille de la collision

	if (colliderToCheckForCollisions != nullptr)
	{
		if (colliderToCheckForCollisions->IsColliding())	//ToDo: il faudrait un check collision at next tick
		{
			//ToDo: clean la partie rebond

			//Calcul de la normal de l'objet collisioné 
			Vector3 normal = colliderToCheckForCollisions->GetNormalOfCollidingObjects();

			//Calcul l'angle d'envoi
			float dotValue = Vector3DotProduct(vel, normal);
			Vector3 crossProduct = Vector3CrossProduct(vel, normal);


			//Calcul le vecteur de renvoi
			
			Vector3 bounce = {  vel.x - 2*(crossProduct.x *normal.x)*normal.x,
								vel.y - 2*(crossProduct.y *normal.y)*normal.y,
								vel.z - 2*(crossProduct.z *normal.z)*normal.z};
			
			Vector3 bounce2 = {  vel.x - 2 * (dotValue * normal.x),
								vel.y - 2 * (dotValue * normal.y),
								vel.z - 2 * (dotValue * normal.z) };

			//ToDo: il faut que le rebond ai moins de force qu'a l'impact
			//Rajoute une force inverse au vecteur d'impact, la force du rebond dépend de boundingValue
			//AddForce({bounce.x* bouncingValue*.9f ,bounce.y* -bouncingValue*.9f,bounce.z* bouncingValue*.9f });

			//SetForce({bounce.x* bouncingValue  ,bounce.y* -bouncingValue,bounce.z* bouncingValue  });
			SetForce({bounce.x* bouncingValue * .9f  ,bounce.y* -bouncingValue * .9f,bounce.z* bouncingValue * .9f });

			std::cout << std::endl;
			std::cout << "velocity: " << vel.x << " " << vel.y << " " << vel.z << std::endl;
			std::cout << "accleration: " << acc.x << " " << acc.y << " " << acc.z << std::endl;
		}
		
	}

	//ToDo:Vérif si la valeur accleration est trop basse on fait plus les calculs



	refPos->x +=  acc.x * dt * dt;
	refPos->y +=  acc.y * dt * dt;
	refPos->z +=  acc.z * dt * dt;
	Fall();


	vel.x -= dt * acc.x * friction;
	vel.y -= dt * acc.y * friction;
	vel.z -= dt * acc.z * friction;

	acc.x = vel.x;
	acc.y = vel.y;
	acc.z = vel.z;

	/*
	if (!Maths::nearZero(acc.x))
	{
		refPos->x += acc.x * dt * dt;
		vel.x -= dt * acc.x * friction;
		acc.x = vel.x;

	}
	else
	{
		vel.x = 0;
		acc.x = 0;
	}
	if (!Maths::nearZero(acc.y))
	{
		refPos->y += acc.y * dt * dt;
		vel.y -= dt * acc.y * friction;
		acc.y = vel.y;

	}
	else
	{
		vel.y = 0;
		acc.y = 0;
	}
	if (!Maths::nearZero(acc.z))
	{
		refPos->z += acc.z * dt * dt;
		vel.z -= dt * acc.z * friction;
		acc.z = vel.z;

	}
	else
	{
		vel.z = 0;
		acc.z = 0;
	}
	*/
	/*
	float magnitude = sqrt(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);
	//L'acclération diminue due à la friction
	acc.x += ((friction / accValue) * vel.x);
	acc.y += ((friction / accValue) * vel.y);
	acc.z += ((friction / accValue) * vel.z);

	
	vel.x += acc.x * dt;
	vel.y += acc.y * dt;
	vel.z += acc.z * dt;

	refPos->x +=  vel.x * dt;
	refPos->y +=  vel.y * dt;
	refPos->z +=  vel.z * dt;
	*/

	/*
	std::cout << std::endl;
	std::cout << "velocity: " << vel.x << " " << vel.y << " " << vel.z << std::endl;
	std::cout << "accleration: " << acc.x << " " << acc.y << " " << acc.z << std::endl;
	*/



}


