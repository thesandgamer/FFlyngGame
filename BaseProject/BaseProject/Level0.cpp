#include "Level0.h"


void Level0::Start()
{
    //----------------------------
    chara = new MovingCharacter();
    chara->SetPos({ 50,10,0 });
    
    //----------Création du terrain---------
    std::vector<CubeActor* > cubes = {
        new CubeActor({ -34,0,0 }, { 10,64, 64 }, { 138, 103, 34, 255 }),
        new CubeActor({ 34,0,0 }, { 10,64, 64 },  { 100, 120, 110, 255 }),

        new CubeActor({ 0,0,-34 }, { 64,64, 10 }, { 0, 0, 244, 255 }),
        new CubeActor({ 0,0,34 }, { 64,64, 10 },  { 0, 144, 0, 255 }),
    };
    Terrain.assign(cubes.begin(), cubes.end());

    //PhysicActors.push_back(new PhysicActor({0,170,0}));
    //MovingActors.push_back(new   MovingActor({ 10,25,4 }));

    /*
    std::vector<Ennemy* > ennmis = {
       new Ennemy({ 50,50,0 }, 20)
    };
    Ennemies.assign(ennmis.begin(), ennmis.end());*/

    Terrain.push_back(new CubeActor({ 0,0,0 }, { 64,10, 64 }, { 239, 123, 69, 255 }));//Créer le sol
    
    Level::Start();

    chara->GetBodyCollider()->checkingCollision = false;


}

void Level0::Update()
{
	Level::Update();
    if (IsMouseButtonReleased(0))
    {
        Vector3 newPos = Vector3Add(chara->GetPosition(),Vector3Multiply(chara->GetForwardVector(), { 10,10,10}));
        PhysicActors.push_back(new PhysicActor(newPos));
        PhysicActors.at(PhysicActors.size() - 1)->Start();
        PhysicActors.at(PhysicActors.size() - 1)->GetPhysicBody().AddForce(Vector3Multiply(chara->GetForwardVector(), { 2000,2000,2000 }));

    }

}

