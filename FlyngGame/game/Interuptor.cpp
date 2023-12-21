#include "Interuptor.h"

Interuptor::Interuptor()
{
}

Interuptor::Interuptor(Vector3 position, Vector3 scale)
{
	trigger.transform.translation = position;
	trigger.transform.scale = scale;



	trigger.AddFunctionToTrigger( std::bind(&Interuptor::ActivateObjects,this ));
}

Interuptor::~Interuptor()
{
}

void Interuptor::Start()
{
	trigger.GetCollision()->trigger = true;
	trigger.GetCollision()->checkingCollision = true;
	trigger.GetCollision()->collideWithLayer = Layer4;

	trigger.Start();
}

void Interuptor::Draw()
{
	trigger.Draw();
	DrawCube(trigger.transform.translation, trigger.transform.scale.x, trigger.transform.scale.y, trigger.transform.scale.z, RED);
}

void Interuptor::Update()
{
	trigger.Update();
}

void Interuptor::LinkTo(IActivable* toActivate)
{
	objectsLinked.push_back(toActivate);
}

void Interuptor::ActivateObjects()
{
	for (IActivable* obj : objectsLinked)
	{
		obj->Activate();
	}
}
