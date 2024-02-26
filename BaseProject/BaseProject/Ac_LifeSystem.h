#pragma once

//++ToDo: G�re la vie, et le fait de prendre des damages,la mort mais aussi un lien avec une barre de vie
class AcLifeSystem
{
public:
	AcLifeSystem(float maxLife)
		: maxLife(maxLife), currentLife(maxLife)
	{
	}

	void AddLifeBar();//Cr�er une barre de vie / ou x vies

	void Start();
	void Update();
	void DrawUi();

	float GetLife() { return currentLife; }
	void TakeDamages(float damages);
	void GainLife(float gain);

private:
	float maxLife;
	float currentLife;


};

