#pragma once
#include "raylib.h"
#include "raymath.h"
#include <iostream>

struct CameraData
{
	float playerEyesPosition;       // Player eyes position from ground (in meters)
	float targetDistance;           // Camera distance from position to target
	Vector2 angle;                  // Camera angle in plane XZ

};

class AC_FirstPersonCamera
{
public:

	void Start();
	void Draw();
	void Update();

	Camera& GetCamera() { return cam; }

	Vector2 GetAngle() { return camData.angle; }

	void SetParent(Transform* parentTransform) { transform = parentTransform; }

	Transform* transform{};
	Transform offsetTransform{};

	void HeadShake(float strength);

private:
	//Position
	//Rotation

	//Camera
	Camera cam{ 0 };
	CameraData camData{};



	void CameraControl();

};

