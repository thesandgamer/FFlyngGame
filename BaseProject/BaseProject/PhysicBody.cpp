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


	//++ToDo: refacto pour que ça fasse un truc qui marche vraiment bien
	//refPos = &nextPos;
	



}

void PhysicBody::ProcessVelocity()
{
	float dt = GetFrameTime();


	//On défnit les valeur maxes

	//Fricction : on réduit l'accélération

	acc.x += deccValue * vel.x;
	acc.y += deccValue * vel.y;
	acc.z += deccValue * vel.z;


	DrawRay({ *refPos,Vector3Normalize(vel) }, 50, WHITE);

	

	if (colliderToCheckForCollisions != nullptr)
	{
		if (colliderToCheckForCollisions->IsColliding())	//ToDo: il faudrait un check collision at next tick
		{
			//ToDo: récupérer la normal de l'impact, le comparer avec la velocité avec un dot product, et appliquer une force inverse en fonction
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

	//On repositionne avec une accélération	
	refPos->x += dt * vel.x + 0.5f * acc.x * dt * dt ;
	refPos->y += dt * vel.y + 0.5f * acc.y * dt * dt;
	refPos->z += dt * vel.z + 0.5f * acc.z * dt * dt;



	//std::cout << "acc: " << acc.x << " " << acc.y << " " << acc.z << std::endl;


	//Acc = accélération de l'acteur, se rapproche de 0 
	//Vel = vélocité de l'acteur : se rapproche de la valeur max de velcité ou de 0 en fonction de si accélère ou décléère

	//Quand on relache la touche, l'accération passe donc à la valeur inverse de vélocité, et va donc diminuer avec le temps


	velocity.x -= dt * acc.x;
	velocity.y -= dt * acc.y;
	velocity.z -= dt * acc.z;

	//std::cout << "velocity: " << velocity.x << " " << velocity.y << " " << velocity.z << std::endl;


	//acc = { 0,0 ,0 };
}


