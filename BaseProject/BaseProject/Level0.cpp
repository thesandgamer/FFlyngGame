#include "Level0.h"

Level0::Level0()
{
}

Level0::~Level0()
{
}

void Level0::Start()
{
    //----------------------------


    
    //----------Création du terrain---------
    std::vector<CubeActor* > cubes = {
        new CubeActor({ -34,0,0 }, { 10,64, 64 }, { 138, 103, 34, 255 }),
    };
    Terrain.assign(cubes.begin(), cubes.end());

    PhysicActors.push_back(new PhysicActor({10,25,4}));

    std::vector<Ennemy* > ennmis = {
       //new Ennemy({ 15,5,10 }, 10)
    };
    Ennemies.assign(ennmis.begin(), ennmis.end());

    Terrain.push_back(new CubeActor({ 0,0,0 }, { 64,10, 64 }, { 239, 123, 69, 255 }));//Créer le sol
    
    Level::Start();

}

void Level0::Update()
{
    Level::Update();
}

void Level0::Draw()
{
    Level::Draw();
}

void Level0::DrawUi()
{
    Level::DrawUi();
}
