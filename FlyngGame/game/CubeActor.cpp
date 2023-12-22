#include "CubeActor.h"
#include "Utility.h"

CubeActor::CubeActor()
{
}

CubeActor::CubeActor(Vector3 posP, Vector3 sizeP,Color colorP): color(colorP)
{
	transform.translation = posP;
	transform.scale = sizeP;

	collision.SetParent(&transform);
	collision.id = 7;

	cubeModel = LoadModelFromMesh(GenMeshCube(sizeP.x, sizeP.y, sizeP.z));
	Utility::GetInstance()->AddModel(&cubeModel);
	cubeModel.materials[0].shader = *Utility::GetInstance()->shader;
}

CubeActor::~CubeActor()
{
}

void CubeActor::Start()
{
}

void CubeActor::Draw()
{
	DrawModel(cubeModel, transform.translation, 1.0f, color);
	//DrawCube(transform.translation, transform.scale.x, transform.scale.y, transform.scale.z, color);
	collision.Draw();

}

void CubeActor::Update()
{
}
