#pragma once
#include "P_Collision.h"

class AnticipateCollisions
{
	// Il va prendre en param�tre un collider, la prochaine position o� l'objet doit bouger, 
	// et va retourner un boll�en pour savoir si cette prochaine position collisionne
public:

	static bool NextMoveIsColliding(P_Collision* collider, Vector3 nextPos);

	

};

