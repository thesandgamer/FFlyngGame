#pragma once
#include "P_Collision.h"

class AnticipateCollisions
{
	// Il va prendre en paramètre un collider, la prochaine position où l'objet doit bouger, 
	// et va retourner un bolléen pour savoir si cette prochaine position collisionne
public:

	static bool NextMoveIsColliding(P_Collision* collider, Vector3 nextPos);

	

};

