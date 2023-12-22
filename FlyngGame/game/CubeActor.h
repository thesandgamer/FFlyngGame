#pragma once
#include "BoxCollision.h"

class CubeActor
{
public:
	CubeActor();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="posP"></param>
	/// <param name="sizeP"></param>
	/// <param name="colorP"></param>
	CubeActor(Vector3 posP,Vector3 sizeP,Color colorP);
	~CubeActor();

	void Start();
	void Draw();
	void Update();

	Vector3* GetPos() { return &transform.translation; }
	Vector3* GetSize() { return &transform.scale; }

	BoxCollision* GetCollision() { return &collision; }

	Transform transform{{0,0,0},{0,0,0,0},{1,1,1}};


private:
	BoxCollision collision{ transform.scale};
	Color color{ PURPLE };

	Model cubeModel;

};

