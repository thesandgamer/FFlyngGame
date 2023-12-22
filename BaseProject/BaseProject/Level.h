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

#include "Utility.h"

#include "rlights.h"

class Level
{
public:
	Level() {};
	~Level() {};
	virtual void Start() ;
	virtual void Update() ;
	virtual void Draw() ;
	virtual void DrawUi() ;

	void Clean();

	void ResetLevel();

protected:

	Ch_MainCharacter character;

	std::vector<CubeActor*> Terrain; //Stoquage des acteurs obstacles et sol
	std::vector<Ennemy*> Ennemies; //Stoquage des acteurs obstacles et sol
	std::vector<EndPortal*> EndPortals;
	std::vector<MovableActor*> MovablesActors;
	std::vector<Interuptor*> Interuptors;

	Light lights[MAX_LIGHTS] = { 0 };

	CubeActor* deathzone;

};

