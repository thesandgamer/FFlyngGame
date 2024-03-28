#pragma once
#include <iostream>

#include <vector>
#include <string>

#include "raylib.h"
#include "Ch_MainCharacter.h"
#include "CollisionManager.h"
#include "CubeActor.h"
#include "Ennemy.h"
#include "EndPortal.h"
#include "MovableActor.h"
#include "Interuptor.h"
#include "PhysicActor.h"

#include "Utility.h"

#include "rlights.h"

class Level
{
public:
	Level() = default;
	virtual ~Level() = default;
	virtual void Init();
	virtual void Start() ;
	virtual void Update() ;
	virtual void Draw() ;
	virtual void DrawUi() ;

	void Clean();

	void ResetLevel();
			
protected:

	MovingCharacter* chara {nullptr};

	std::vector<CubeActor*> Terrain; //Stoquage des acteurs obstacles et sol
	std::vector<Ennemy*> Ennemies; 
	std::vector<EndPortal*> EndPortals;
	std::vector<MovableActor*> MovablesActors;
	std::vector<MovingActor*> MovingActors;
	std::vector<Interuptor*> Interuptors;

	std::vector<PhysicActor*> PhysicActors; 


	Light lights[MAX_LIGHTS] = {{0}};

	//ToDo: rajouet le A* et faire en sorte de l'injecter dans ce qui l'utilise

	//Setup A* grid with is size
	AStar::AStarManager* aStar;

	//CubeActor* deathzone;

};

