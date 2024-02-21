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
        //new CubeActor({ 0,1,0 }, { 3,2, 3 },color),
        //new CubeActor({ 5,2,5 }, { 2,4, 2 },color),
        new CubeActor({5,10,-85},{30,8,2},BLUE),//first wall
        new CubeActor({30,0,-65},{15,8,2},BLUE),
        new CubeActor({80,0,-65},{2,8,15},YELLOW),
        new CubeActor({45,0,-45},{2,8,15},BLUE),
       // new CubeActor({-6,4,-35},{2,8,14},GREEN),//Mur 1
        //new CubeActor({6,4,-35},{2,8,14},GREEN), //Mur 2
        new CubeActor({6,4,-65},{2,8,25},GREEN), // Mur 3
        new CubeActor({-6,4,-65},{2,8,25},GREEN),// Mur 4
        new CubeActor({10,4,-77},{10,8,2},GREEN),// Mur 5


    };
    Terrain.assign(cubes.begin(), cubes.end());

    PhysicActors.push_back(new PhysicActor({10,25,4}));

    std::vector<Ennemy* > ennmis = {
       //new Ennemy({ 15,5,10 }, 10)
    };
    Ennemies.assign(ennmis.begin(), ennmis.end());

    Terrain.push_back(new CubeActor({ 0,0,0 }, { 64,10, 64 }, { 239, 123, 69, 255 }));//Créer le sol
    Terrain.push_back(new CubeActor({ 0,3,-30 }, { 10.0f, 0.5f, 15.0f }, { 239, 123, 69, 255 }));// Sol A
    Terrain.push_back(new CubeActor({ 0,5,-60 }, { 10.0f, 0.5f, 15.0f }, { 239, 123, 69, 255 }));// Sol B
    Terrain.push_back(new CubeActor({ 0,8,-80 }, { 10.0f, 0.5f, 15.0f }, { 239, 123, 69, 255 }));// Sol C
    Terrain.push_back(new CubeActor({ 5,8,-81 }, { 20.0f, 0.5f, 7.0f }, { 239, 123, 69, 255 })); // Sol D
    //Terrain.push_back(new CubeActor({ 50,0,-80 }, { 10.0f, 0.5f, 15.0f }, { 239, 123, 69, 255 }));//Sol E
    Terrain.push_back(new CubeActor({ 85,0,-30 }, { 10.0f, 0.5f, 15.0f }, { 239, 123, 69, 255 }));//Sol F
    Terrain.push_back(new CubeActor({ 65,0,-30 }, { 10.0f, 0.5f, 15.0f }, { 239, 123, 69, 255 }));// Sol G
    
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
