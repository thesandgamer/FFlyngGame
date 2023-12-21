#pragma once
#include "Trigger.h"

class EndPortal
{
public:
	EndPortal();
	EndPortal(Vector3 position, Vector3 scale);
	~EndPortal();

	void Start();
	void Draw();
	void Update();

private:
	Trigger trigger{};

};

