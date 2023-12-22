#include "Level01.h"

    Level01::Level01()
    {
    }

    Level01::~Level01()
    {
    }

    void Level01::Start()
    {
        Level::Start();
        //----------Création du terrain---------
        Color color = { GetRandomValue(169, 122), GetRandomValue(109, 89), GetRandomValue(163, 128), 255 };
        std::vector<CubeActor* > cubes = {
            // Murs
            //new CubeActor({ 0,1,0 }, { 3,2, 3 },color),
            
          



        };
        Terrain.assign(cubes.begin(), cubes.end());
        std::vector<Ennemy* > ennmis = {
            new Ennemy({ -60,10,0 },25),
            new Ennemy({ -25,10,-30 }, 25), // middle one
            new Ennemy({ -25,15,-55 }, 20),
            new Ennemy({75,8,-70},25)
        };
        Ennemies.assign(ennmis.begin(), ennmis.end());

       //Sol gauche U
        Terrain.push_back(new CubeActor({ 0,0,0 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 }));
        Terrain.push_back(new CubeActor({ -30,-3,0 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 }));
        Terrain.push_back(new CubeActor({ -60,0,0 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 }));
        //sol droite U
        Terrain.push_back(new CubeActor({ -60,3,-30 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 }));
        Terrain.push_back(new CubeActor({ -60,5,-60 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 }));
        Terrain.push_back(new CubeActor({ -30,7,-60 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 }));
       
        
        Terrain.push_back(new CubeActor({ 15,7,-60 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 })); // after jump 
        Terrain.push_back(new CubeActor({ 55,7,-70 }, { 10.0f,5.0f, 3.0f }, { 239, 123, 69, 255 }));
        Terrain.push_back(new CubeActor({ 75,8,-60 }, { 10.0f,5.0f, 3.0f }, { 239, 123, 69, 255 }));
        Terrain.push_back(new CubeActor({ 100,9,-75 }, { 10.0f,5.0f, 3.0f }, { 239, 123, 69, 255 }));
        Terrain.push_back(new CubeActor({ 130,10,-60 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 }));
    }


    void Level01::Update()
    {
        Level::Update();
    }

    void Level01::Draw()
    {
        Level::Draw();
    }

    void Level01::DrawUi()
    {
        Level::DrawUi();
    }
