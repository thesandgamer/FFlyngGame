#include "Ennemy.h"

#include <algorithm>

Ennemy::Ennemy() : MovingActor()
{
	bodyCol = new SphereCollision(2);

}

Ennemy::Ennemy(Vector3 pos, float detectionRadius) : MovingActor()
{
	bodyCol = new SphereCollision(2);
	transf.translation = pos;
	//On ajoute le trigger pour la détéction
	//bodyCol->layer = BodyColliders;

	//----Trigger
	triggerCollider = SphereCollision(detectionRadius);//Peut être juste avoir une fonction set radius
	triggerCollider.trigger = true; //Cette collision sera un trigger
	triggerCollider.SetParent(&transf);
	triggerCollider.collideWithLayer = PlayerCollider;	//Collideavec le alyer 4 = body du player
	triggerCollider.layer = BodyColliders;	//La sphere de détéction est sur la layer2
	triggerCollider.checkingCollision = true;

	triggerCollider.id = 8;

	
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
	DrawSphere(transf.translation, 2, RED);
	triggerCollider.Draw();
}

void Ennemy::Update()
{
	MovingActor::Update();

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
