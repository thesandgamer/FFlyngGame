#pragma once
#include "CubeActor.h"
#include "PhysicBody.h"

class PhysicActor : CubeActor
{
public:
	void Start() override;
	~PhysicActor() override;
	void Draw() override;
	void Update() override;

	PhysicActor();

	PhysicActor(const Vector3& posP, const Vector3& sizeP = { 2,2,2 }, const Color& colorP = WHITE);


	PhysicBody& GetPhysicBody() { return  pb; }



private:
	PhysicBody pb;

};

