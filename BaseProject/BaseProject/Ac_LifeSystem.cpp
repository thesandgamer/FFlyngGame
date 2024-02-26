#include "Ac_LifeSystem.h"

#include "Maths.h"
#include "raylib.h"

double mapValue(double value, double fromLow, double fromHigh, double toLow,double toHigh)
{
	return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

void AcLifeSystem::AddLifeBar()
{
}

void AcLifeSystem::Start()
{
}

void AcLifeSystem::Update()
{
}

void AcLifeSystem::DrawUi()
{
	//Transformer ça en classe fillbar
	DrawRectangle(40, 40, 128, 32, WHITE);
	DrawRectangle(40, 40, mapValue(currentLife,0,maxLife,0,128), 32, GREEN);
}


void AcLifeSystem::TakeDamages(float damages)
{
	if (currentLife - damages > 0)
	{
		currentLife -= damages;
	}
	else
	{
		currentLife = 0;
	}
}

void AcLifeSystem::GainLife(float gain)
{
	if (currentLife + gain <= maxLife)
	{
		currentLife += gain;
	}
	else
	{
		currentLife = maxLife;
	}
}
