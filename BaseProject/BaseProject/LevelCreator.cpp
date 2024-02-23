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

	if (IsKeyPressed(KEY_C))
	{
		if (character.GetGroundCollider()->checkingCollision)
		{
			character.GetGroundCollider()->checkingCollision = false;
		}
		else
		{
			character.GetGroundCollider()->checkingCollision = true;
		}
	}

	if (IsMouseButtonPressed(0))
	{
		//ToDo: il va falloir faire en sorte que si un bloc est déjà présent n'en place pas un nouveau
		Ray ray = { character.transf.translation,{character.GetForwardVector().x * 15000,character.GetForwardVector().y * 15000,character.GetForwardVector().z * 15000 } };
		RayHitInfo info= {};
		std::cout << CollisionManager::GetInstance()->GetColliders().size() << std::endl;
		for (auto col : CollisionManager::GetInstance()->GetColliders())
		{
			if (col->collisionType == BoxCollider)
			{
;				 info = GetRayCollisionBox(ray, dynamic_cast<BoxCollision*>(col)->GetBoundingBox());
				 if (info.hit)
				 {
					 break;
				 }
			}
		}

	

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
		//Il va falloir arrondir
		putPos = {   (putPos.x / boxSize.x) * boxSize.x,
						(putPos.y / boxSize.y) * boxSize.y,
						(putPos.z / boxSize.z) * boxSize.z };


		//AddWallAt(putPos);
	}

	if (IsMouseButtonPressed(1))
	{
		Ray ray = { character.transf.translation,{character.GetForwardVector().x * 15000,character.GetForwardVector().y * 15000,character.GetForwardVector().z * 15000 } };
		RayHitInfo info = {};
		for (const auto col : CollisionManager::GetInstance()->GetColliders())
		{
			if (col->collisionType == BoxCollider)
			{
		;		info = GetRayCollisionBox(ray, dynamic_cast<BoxCollision*>(col)->GetBoundingBox());
				if (info.hit)
				{
					//Il faut récupérer l'objet touché pour le détruire 
					break;
				}
			}
		}
	}
}

void LevelCreator::Draw()
{
	Level::Draw();
	DrawSphere(putPos, 3, GREEN);

}

void LevelCreator::AddWallAt(Vector3 pos)
{
	Terrain.push_back(new CubeActor(pos, boxSize, wallColor));

}
