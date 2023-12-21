#pragma once
#include "BoxCollision.h"
#include <functional>

class Trigger
{
public:

	Trigger();
	Trigger(Vector3 posP, Vector3 sizeP = {1,1,1});
	~Trigger();

	void Start();
	void Draw();
	void Update();

	BoxCollision* GetCollision() { return &collision; }

	void AddFunctionToTrigger(std::function<void()> function);

	Transform transform{ {0,0,0},{0,0,0,0},{1,1,1} };

private:
	void triggered();

	BoxCollision collision{ transform.scale };
	std::vector<std::function<void()>> functionsTriggered;

};

