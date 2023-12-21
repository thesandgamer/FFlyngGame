#pragma once
#include "Trigger.h"
#include "IActivable.h"


class Interuptor
{
public:
	Interuptor();
	Interuptor(Vector3 position, Vector3 scale);
	~Interuptor();

	void Start();
	void Draw();
	void Update();

	void LinkTo(IActivable* toActivate);


private:
	Trigger trigger{};
	std::vector<IActivable*> objectsLinked;

	void ActivateObjects();

};

