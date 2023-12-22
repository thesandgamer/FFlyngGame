#include "EndPortal.h"
#include "LevelManager.h"

EndPortal::EndPortal()
{
}

EndPortal::EndPortal(Vector3 position, Vector3 scale)
{
	trigger.transform.translation = position;
	trigger.transform.scale = scale;

	trigger.GetCollision()->trigger = true;
	trigger.GetCollision()->checkingCollision = true;
	trigger.GetCollision()->collideWithLayer = Layer3;

	trigger.AddFunctionToTrigger( std::bind(&LevelManager::GoToNextLevel, LevelManager::GetInstance()) );
}

EndPortal::~EndPortal()
{
}

void EndPortal::Start()
{
	trigger.Start();
}

void EndPortal::Draw()
{
	trigger.Draw();
}

void EndPortal::Update()
{
	trigger.Update();
}
