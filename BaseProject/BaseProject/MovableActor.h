#pragma once
#include "CubeActor.h"
#include "IActivable.h"

class MovableActor: public IActivable
{
public:
	MovableActor();
	MovableActor(Vector3 position, Vector3 scale, Color colorP, Vector3 target = {0,0,0}, float speedP = 1 );
	~MovableActor();

	void Start();
	void Draw();
	void Update();

	void Activate();

	Transform transform{ {0,0,0},{0,0,0,0},{1,1,1} };

private:
	BoxCollision collision{ transform.scale };

	Vector3 targetOffsetLocation{0,0,0};
	float speed{ 1 };
	Vector3 baseLocation {0,0,0};
	Color color{ PURPLE };

	void Move();
	void MoveReverse();

	bool inActivation{ false };

};

