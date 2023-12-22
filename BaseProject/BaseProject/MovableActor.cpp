#include "MovableActor.h"

MovableActor::MovableActor()
{
}

MovableActor::MovableActor(Vector3 position, Vector3 scale, Color colorP, Vector3 target,float speedP): color(colorP), targetOffsetLocation(target), speed(speedP)
{
	transform.translation = position;
	transform.scale = scale;

}

MovableActor::~MovableActor()
{
}

void MovableActor::Start()
{
	collision.SetParent(&transform);
	collision.id = 7;
	baseLocation = transform.translation;
}

void MovableActor::Draw()
{
	collision.Draw();
	DrawCube(transform.translation, transform.scale.x, transform.scale.y, transform.scale.z, color);
}

void MovableActor::Update()
{
	if (inActivation)
	{
		Move();
	}
}	


void MovableActor::Activate()
{
	if (inActivation) return;
	inActivation = true;
	std::cout << "Object activated" << std::endl;
}

void MovableActor::Move()
{	
	//Si on arrrive à la destination finale
	if (transform.translation.x >= baseLocation.x + targetOffsetLocation.x &&
		transform.translation.y >= baseLocation.y + targetOffsetLocation.y &&
		transform.translation.z >= baseLocation.z + targetOffsetLocation.z) return;

	transform.translation.x += targetOffsetLocation.x * speed/10;
	transform.translation.y += targetOffsetLocation.y * speed/10;
	transform.translation.z += targetOffsetLocation.z * speed/10;

}

void MovableActor::MoveReverse()
{
}
