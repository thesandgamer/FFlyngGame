#include "AnticipateCollisions.h"


bool AnticipateCollisions::NextMoveIsColliding(P_Collision* collider, Vector3 nextPos)
{
	if (collider == nullptr) return false;
	collider->transform->translation = nextPos;
	if (collider->IsColliding())
	{
		return true;
	}
	return false;
}
