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


	//++ToDo: refacto pour que ça fasse un truc qui marche vraiment bien
	//refPos = &nextPos;



}

void PhysicBody::ProcessVelocity()
{
	float dt = GetFrameTime();

	
	//Vector3CrossProduct();

	
	if (colliderToCheckForCollisions != nullptr)
	{
		if (colliderToCheckForCollisions->IsColliding())	//ToDo: il faudrait un check collision at next tick
		{
			//Calcul de la normal de l'objet collisioné 
			Vector3 normal = colliderToCheckForCollisions->GetNormalOfCollidingObjects();

			//Calcul l'angle d'envoi
			float dotValue = Vector3DotProduct(vel, normal);

			//Calcul le vecteur de renvoi
			Vector3 bounce = { vel.x - 2*dotValue*normal.x,
								vel.y - 2*dotValue*normal.y,
								vel.z - 2*dotValue*normal.z};

			//Rajoute une force inverse au vecteur d'impact, la force du rebond dépend de boundingValue
			AddForce({bounce.x* bouncingValue ,bounce.y* bouncingValue,bounce.z* bouncingValue });
		}
		
	}

	//ToDo:Vérif si la valeur accleration est trop basse on fait plus les calculs
	//if (Maths::nearZero(acc.x))
		

	refPos->x +=  acc.x * dt * dt ;
	refPos->y +=  acc.y * dt * dt;
	refPos->z +=  acc.z * dt * dt;

	vel.x -= dt * acc.x;
	vel.y -= dt * acc.y;
	vel.z -= dt * acc.z;

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

	std::cout << std::endl;
	std::cout << "velocity: " << vel.x << " " << vel.y << " " << vel.z << std::endl;
	std::cout << "accleration: " << acc.x << " " << acc.y << " " << acc.z << std::endl;

	acc.x = vel.x;
	acc.y = vel.y;
	acc.z = vel.z;

}


