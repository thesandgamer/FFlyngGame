#include "LevelCreator.h"



void LevelCreator::Start()
{
	Level::Start();

	//On va lire un fichier composé de couches de numéro
	//Pour chaque 0 on nen vas rien faire
	//Pour chaque 8 on va mettre un Mur
	//Pour chaque 5 on va mettre un ennemi
	//... pour le player start, les portes et les boutons



	for (int xx = 0; xx < 20.; ++xx)
	{
		for (int zz = 0; zz < 20; ++zz)
		{
			Vector3 pos = { origin.x + boxSize.x * xx,origin.x + boxSize.y  ,origin.z + boxSize.z *zz };
			Terrain.push_back(new CubeActor({ pos.x,pos.y,pos.z }, boxSize, wallColor));
		}
	}
}

void LevelCreator::Update()
{
	Level::Update();


	if (IsKeyReleased(KEY_K))
	{

		Ray ray = { character.transf.translation,{character.GetForwardVector().x * 15000,character.GetForwardVector().y * 15000,character.GetForwardVector().z * 15000 } };
		RayHitInfo info= {};
		for (auto col : CollisionManager::GetInstance()->GetColliders())
		{
			if (col->collisionType == BoxCollider)
			{
;				 info = GetRayCollisionBox(ray, static_cast<BoxCollision*>(col)->GetBoundingBox());
				 if (info.hit)
				 {
					 DrawSphere(info.position, 10, GREEN);
					 break;
				 }
			}
		}

		Vector3 putPos= {};

		if(info.hit)
		{
			//Position où on doit placer le cube
			putPos = {

				(info.position.x),
				 (info.position.y),
				 (info.position.z),
			};
		}
		else
		{
			putPos =
			{
				 ((character.transf.translation.x) + character.GetForwardVector().x * 15) ,
				 ((character.transf.translation.y) + character.GetForwardVector().y * 15) ,
				 ((character.transf.translation.z) + character.GetForwardVector().z * 15) ,
			};

		}
		//Transforme la position en position grille
		putPos = { std::round(putPos.x / boxSize.x) * boxSize.x,std::round(putPos.y / boxSize.y) * boxSize.y,std::round(putPos.z / boxSize.z) * boxSize.z };

		AddWallAt(putPos);

	
	}
}

void LevelCreator::AddWallAt(Vector3 pos)
{
	Terrain.push_back(new CubeActor(pos, boxSize, wallColor));

}
