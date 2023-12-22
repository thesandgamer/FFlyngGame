#pragma once

//++ToDo: Gère la vie, et le fait de prendre des damages,la mort mais aussi un lien avec une barre de vie
class Ac_LifeSystem
{
public:


	void AddLifeBar();//Créer une barre de vie / ou x vies

	void Start();
	void Update();
	void DrawUi();

	void GetLife();
	void TakeDamages(float damages);

private:
	float maxLife;
	float currentLife;


};

