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


	//++ToDo: refacto pour que �a fasse un truc qui marche vraiment bien
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
			//ToDo: r�cup�rer la normal de l'impact, le comparer avec la velocit� avec un dot product, et appliquer une force inverse en fonction
			Vector3 normal = colliderToCheckForCollisions->GetNormalOfCollidingObjects();



			float dotValue = Vector3DotProduct(vel, normal);

			Vector3 bounce = { vel.x - 2*dotValue*normal.x,
								vel.y - 2*dotValue*normal.y,
								vel.z - 2*dotValue*normal.z};

			// bounce = velocity - 2(Vector3DotProduct(velocity,normal)) * normal;
			//AddForce(Vector3Multiply(velocity,{-2,-2,-2}));
			AddForce({bounce.x* bouncingValue ,bounce.y* bouncingValue,bounce.z* bouncingValue });

			
			//refPos->x -= dt * vel.x + 0.5f * acc.x * dt * dt *10;
			//refPos->z -= dt * vel.y + 0.5f * acc.y * dt * dt*10;
			//refPos->y -= dt * vel.z + 0.5f * acc.z * dt * dt*10;
			
			//return;
		}
		
	}

	/*
	acc.x = -friction * (vel.x);
	acc.y = -friction * (vel.y);
	acc.z = -friction * (vel.z);
	*/
	

	//ToDo:V�rif si la valeur accleration est trop basse on fait plus les calculs
	//if (Maths::nearZero(acc.x))
		

	refPos->x +=  acc.x * dt * dt ;
	refPos->y +=  acc.y * dt * dt;
	refPos->z +=  acc.z * dt * dt;

	vel.x -= dt * acc.x;
	vel.y -= dt * acc.y;
	vel.z -= dt * acc.z;

	/*
	float magnitude = sqrt(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);
	//L'accl�ration diminue due � la friction
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


