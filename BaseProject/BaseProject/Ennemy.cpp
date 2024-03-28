#include "Ennemy.h"

#include <algorithm>

#include "AStarDrawRaylib.h"
#include "easings.h"

Ennemy::Ennemy() : MovingActor()
{
	bodyCol = new SphereCollision(2);

}

Ennemy::Ennemy(Vector3 pos, float detectionRadius) : MovingActor()
{
	transf.translation = pos;

	//----Trigger
	triggerCollider = SphereCollision(detectionRadius);//Peut être juste avoir une fonction set radius
	triggerCollider.trigger = true; //Cette collision sera un trigger
	triggerCollider.SetParent(&transf);
	triggerCollider.collideWithLayer = PlayerCollider;	//Collideavec le alyer 4 = body du player
	triggerCollider.layer = BodyColliders;	//La sphere de détéction est sur la layer2
	triggerCollider.checkingCollision = true;

	triggerCollider.id = 8;

	
}

void Ennemy::Init()
{
	bodyCol = new SphereCollision(10);

	MovingActor::Init();

	bodyCol->checkingCollision = true;

}


void Ennemy::Start()
{
	MovingActor::Start();
	shootComponenet.Start();
	bodyCol->layer = EnnemyCollider;
	bodyCol->collideWithLayer = PlayerProjectileCollision;
	
}

void Ennemy::Draw()
{
	MovingActor::Draw();

	shootComponenet.Draw();
	//---On va dessiner l'apparence de l'ennemi
	DrawSphere(transf.translation, 10, ORANGE);
	triggerCollider.Draw();

	if (AStar::HavePath(currentPath))
	{
		astarLink->DrawAStarDebug(&currentPath, true);
	}
}

void Ennemy::Update()
{
	MovingActor::Update();
	MakeMovement();

	shootComponenet.Update();
	if (triggerCollider.IsColliding())
	{
		//Si il peut lui tirer dessus il va lui lancer un projectile
		P_Collision* tar = *std::prev(triggerCollider.collisions.end());
		target = tar->transform;
		//std::cout << "last collide: " << (*(triggerCollider.collisions.end()))->layer << std::endl;

	}
	else
	{
		target = nullptr;
	}

	if (target) Shoot();//SI peut tirer et à une target tire


}

void Ennemy::MoveToLocation(Vector3* posToGo)
{
	
	if(astarLink)
	{
		const AStar::Vector3Pos startPos = dynamic_cast<AStarDrawRaylib*>(astarLink->GetDrawing())->PosInWorldToPosInGrid(transf.translation);
		const AStar::Vector3Pos endPos = dynamic_cast<AStarDrawRaylib*>(astarLink->GetDrawing())->PosInWorldToPosInGrid(*posToGo);

		if (startPos == endPos)
		{
			std::cout << "ERROR: Same start and end location" << std::endl;

		}

		currentPath= astarLink->GetPath(startPos, endPos);
		it = 0;
		currentTime = 0;

	}
	else
	{
		std::cout << "ERROR: Try to move with A* but no AstarManager lined" << std::endl;
	}

	
}


void Ennemy::Shoot()
{
	if (target == nullptr)
	{
		std::cout << "Ennemy have no target" << std::endl; 
		return;
	}

	Vector3 direction{0,0,0};
	//Look at: where target, vector up
	Vector3 v = { (target->translation.x - transf.translation.x),
		(target->translation.y - transf.translation.y),
	(target->translation.z - transf.translation.z) };
	float unit = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	direction = {
		(1 / unit) * v.x,
		(1 / unit) * v.y,
		(1 / unit) * v.z,
	};

	shootComponenet.Shoot(transf.translation,direction,1000);
}

void Ennemy::ReloadShoot()
{
}

void Ennemy::MakeMovement()
{
	if (currentPath.empty()) return;
	
	if (it < currentPath.size()) //Si on est arrivé à la fin des position où aller
	{
		AStar::Vector3Pos pos = currentPath[it];
		Vector3 posToGo = dynamic_cast<AStarDrawRaylib*>(astarLink->GetDrawing())->PosInGridToPosInWorld(pos);

		//transf.translation = posToGo;


		//-------------Moving the ennemy to the target-----------------------//
		//ToDo: faire que le mouvement utilise la physique
		//transf.translation.x = EaseQuadInOut(currentTime, transf.translation.x, posToGo.x - transf.translation.x, 100);//On va au x suivant suivant un lerping
		//transf.translation.y = EaseQuadInOut(currentTime, transf.translation.y, posToGo.y - transf.translation.y, 100);//On va au y suivant suivant un lerping
		//transf.translation.z = EaseQuadInOut(currentTime, transf.translation.z, posToGo.z - transf.translation.z, 100);//On va au y suivant suivant un lerping

		pb.AddForce(Vector3Multiply(Vector3Normalize(posToGo),{15,15,15,}));

		//std::cout << posToGo.x << " " << posToGo.y << " " << posToGo.z << " \n";
		//std::cout << transf.translation.x << " " << transf.translation.y << " " << transf.translation.z <<std::endl;
		currentTime++;

		if (almostEqual(transf.translation.x, posToGo.x, 40.0f) &&
			almostEqual(transf.translation.y, posToGo.y, 40.0f)&&
			almostEqual(transf.translation.z, posToGo.z, 40.0f))
		{
			it++;
			currentTime = 0;
			std::cout << "Go to next point" << std::endl;

		}
	}
	else
	{
		currentPath = {};
	}


	
	

}
