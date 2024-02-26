#include "LevelCreator.h"



void LevelCreator::Start()
{
	Level::Start();

	//On va lire un fichier composé de couches de numéro
	//Pour chaque 0 on nen vas rien faire
	//Pour chaque 8 on va mettre un Mur
	//Pour chaque 5 on va mettre un ennemi
	//... pour le player start, les portes et les boutons

	//Remove collision of character
	character.GetBodyCollider()->checkingCollision = false;

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
		if (character.GetBodyCollider()->checkingCollision)
		{
			character.GetBodyCollider()->checkingCollision = false;
		}
		else
		{
			character.GetBodyCollider()->checkingCollision = true;
		}
	}


	CalculateWherePosActor();
	if (IsMouseButtonPressed(0))
	{
		AddWallAt(putPos);
	}
	
	/*
	if (IsMouseButtonPressed(1))
	{
		ray = { character.transf.translation,{character.GetForwardVector().x * 15000,character.GetForwardVector().y * 15000,character.GetForwardVector().z * 15000 } };
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
	}*/
}

void LevelCreator::Draw()
{
	Level::Draw();
	//DrawSphere(putPos, 3, GREEN);
	//DrawSphere(hitInfo.position, 2, hitInfo.hit ? RED:GREEN);
	//DrawRay(ray, 10, RED);
	DrawCubeWires(putPos, boxSize.x, boxSize.y, boxSize.z, WHITE);

}

void LevelCreator::CalculateWherePosActor()
{
	//ToDo: il va falloir faire en sorte que si un bloc est déjà présent n'en place pas un nouveau
	Ray ray = { character.GetPosition(),{character.GetForwardVector().x * 15000,character.GetForwardVector().y * 15000,character.GetForwardVector().z * 15000 } };

	Vector3 actorTouchedPos{};
	RayHitInfo info{};
	RayHitInfo bestInfo{};
	bestInfo.distance = INFINITY;

	P_Collision* actorCollided = nullptr;
	for (auto col : CollisionManager::GetInstance()->GetColliders())
	{
		if (col->collisionType == BoxCollider)
		{
			info = GetRayCollisionBox(ray, dynamic_cast<BoxCollision*>(col)->GetBoundingBox());
			if (info.hit)
			{
				if (info.distance < bestInfo.distance)
				{
					bestInfo = info;
					actorCollided = col;
				}

			}
		}
	}

	if (bestInfo.hit)
	{
		hitInfo = bestInfo;
		actorTouchedPos = actorCollided->transform->translation;
	}
	if (bestInfo.hit)
	{
		//Position où on doit placer le cube
		putPos = {
			/*
			(info.position.x),
			 (info.position.y),
			 (info.position.z),*/
			 //On va utiliser la position de l'objet touché et où il à été touché pour avoir la position
			 actorTouchedPos.x + hitInfo.normal.x * boxSize.x,
			 actorTouchedPos.y + hitInfo.normal.y * boxSize.y,
			 actorTouchedPos.z + hitInfo.normal.z * boxSize.z
		};
	}
	else
	{
		/*
		putPos =
		{
			 ((character.transf.translation.x) + character.GetForwardVector().x * 15) ,
			 ((character.transf.translation.y) + character.GetForwardVector().y * 15) ,
			 ((character.transf.translation.z) + character.GetForwardVector().z * 15) ,


		};
		//Changer l'arrondissement pour que quand on pose dans le vide çà se mieux
		putPos = { floor(putPos.x / boxSize.x) * boxSize.x,
				floor(putPos.y / boxSize.y) * boxSize.y,
				floor(putPos.z / boxSize.z) * boxSize.z };
				*/
	}

	//std::cout << putPos.x <<" "<<putPos.y <<" "<<putPos.z << " "<< std::endl;
}

void LevelCreator::AddWallAt(Vector3 pos)
{
	Terrain.push_back(new CubeActor(pos, boxSize, wallColor));

}
