#include "Level0.h"


void Level0::Start()
{
    //----------------------------
    chara = new ChMainCharacter();

    
    //----------Création du terrain---------
    std::vector<CubeActor* > cubes = {
        new CubeActor({ -34,0,0 }, { 10,64, 64 }, { 138, 103, 34, 255 }),
        new CubeActor({ 34,0,0 }, { 10,64, 64 },  { 138, 103, 34, 255 }),

        new CubeActor({ 0,0,-34 }, { 64,64, 10 }, { 0, 0, 244, 255 }),
        new CubeActor({ 0,0,34 }, { 64,64, 10 },  { 0, 0, 244, 255 }),
    };
    Terrain.assign(cubes.begin(), cubes.end());

    PhysicActors.push_back(new PhysicActor({10,25,4}));

    std::vector<Ennemy* > ennmis = {
       new Ennemy({ 0,0,0 }, 20)
    };
    Ennemies.assign(ennmis.begin(), ennmis.end());

    Terrain.push_back(new CubeActor({ 0,0,0 }, { 64,10, 64 }, { 239, 123, 69, 255 }));//Créer le sol
    
    Level::Start();

}

