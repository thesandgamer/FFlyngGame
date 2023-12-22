#include "Level03.h"

Level03::Level03()
{
}

Level03::~Level03()
{
}

void Level03::Start()
{
    
    //----------Création du terrain---------
    Color color = { GetRandomValue(169, 122), GetRandomValue(109, 89), GetRandomValue(163, 128), 255 };
    std::vector<CubeActor* > cubes = {
        // Murs
        //new CubeActor({ 0,1,0 }, { 3,2, 3 },color),





    };

    Terrain.assign(cubes.begin(), cubes.end());
    std::vector<Ennemy* > ennmis = {
        //new Ennemy({ -60,10,0 },25),
       
    };
    Ennemies.assign(ennmis.begin(), ennmis.end());

                    //Sol salle 1 - intérieur avec sauts
    Terrain.push_back(new CubeActor({ 0,0,0 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 })); // début 
    Terrain.push_back(new CubeActor({ -20,0,0 }, { 32.0f,10.0f, 2.0f }, { 239, 123, 69, 255 })); // pont
    Terrain.push_back(new CubeActor({ -40,-20,0 }, { 20.0f,50.0f, 20.0f }, { 239, 123, 69, 255 }));// 2 
    Terrain.push_back(new CubeActor({ -40,-20,-40 }, { 20.0f,50.0f, 20.0f }, { 239, 123, 69, 255 }));// 3 
    Terrain.push_back(new CubeActor({ -70,-7,-55 }, { 20.0f,40.0f, 3.0f }, { 239, 123, 69, 255 })); // mur 
    Terrain.push_back(new CubeActor({ -100,- 20,-40 }, { 20.0f,50.0f, 20.0f }, { 239, 123, 69, 255 }));
    Terrain.push_back(new CubeActor({ -140,0,-15 }, { 20.0f,50.0f, 20.0f }, { 239, 123, 69, 255 }));
    Terrain.push_back(new CubeActor({ -140,0,-50 }, { 20.0f,50.0f, 20.0f }, { 239, 123, 69, 255 }));
    Terrain.push_back(new CubeActor({ -180,-20,-40 }, { 20.0f,50.0f, 20.0f }, { 239, 123, 69, 255 }));

    Terrain.push_back(new CubeActor({ -180,-20,-110 }, { 20.0f,50.0f, 20.0f }, { 239, 123, 69, 255 }));
    Terrain.push_back(new CubeActor({ -170,-10,-80 }, { 3.0f,40.0f, 20.0f }, { 239, 123, 69, 255 })); // mur 2 
                               //mur de la salle 1 
  /* Terrain.push_back(new CubeActor({0,5,10}, {32.0f,15.0f, 2.0f}, {192, 192, 192, 255}));// ici 0 = + tout droit , 5 = hauteur et 10 = plus gauche ou droite
    Terrain.push_back(new CubeActor({ -32,5,10 }, { 32.0f,15.0f, 2.0f }, { 192, 192, 192, 255 }));
    Terrain.push_back(new CubeActor({ 0,5,-10 }, { 32.0f,15.0f, 2.0f }, { 192, 192, 192, 255 }));
  //Terrain.push_back(new CubeActor({ -32,5,-10 }, { 32.0f,15.0f, 2.0f }, { 192, 192, 192, 255 }));
    //Terrain.push_back(new CubeActor({ 0,20,0 }, { 32.0f,10.0f, 32.0f }, { 239, 123, 69, 255 }));// roof but spawn in 
                               */
                               //Corridor Sol//
    Terrain.push_back(new CubeActor({ -180,-20,-130 }, { 20.0f,50.0f, 20.0f }, { 0, 102, 204, 255 }));
    Terrain.push_back(new CubeActor({ -180,-20,-150 }, { 20.0f,50.0f, 20.0f }, { 0, 102, 204, 255 }));

                                //Porte//
    MovableActor* Door0 = new MovableActor({ -180,8,-120 }, { 7,7,4 }, YELLOW, { 0,10,0 }, 0.5f);
    MovablesActors.emplace_back(Door0);

                                //Interrupteur//
    Interuptor* Interuptor0 = new Interuptor({ -173,8,-118 }, { 2,2,2 });
    Interuptor0->LinkTo(Door0);
    Interuptors.emplace_back(Interuptor0);

                             //Mur Corridor//
    Terrain.push_back(new CubeActor({ -190,0,-140 }, { 2.0f,32.0f, 48.0f }, { 204 , 255, 100, 255 }));// H
    Terrain.push_back(new CubeActor({ -170,0,-140 }, { 2.0f,32.0f, 48.0f }, { 204 , 255, 255, 255 }));// H
    Terrain.push_back(new CubeActor({ -173,8,-120 }, { 7.0f,10.0f, 2.0f }, { 204 , 255, 255, 255 }));// V
    Terrain.push_back(new CubeActor({ -187,8,-120 }, { 7.0f,10.0f, 2.0f }, { 204 , 255, 255, 255 }));// V

                                 //Pilliers//
    Terrain.push_back(new CubeActor({ -100,-20,-210 }, { 5.0f,50.0f, 5.0f }, { 153, 51, 255, 255 }));// avant dernier
    Terrain.push_back(new CubeActor({ -60,-20,-230 }, { 5.0f,50.0f, 5.0f }, { 153, 51, 255, 255 }));// pillier de fin
    Terrain.push_back(new CubeActor({ -180,-20,-180 }, { 5.0f,50.0f, 5.0f }, { 153, 51, 255, 255 }));//premier pillier
    
   
    Terrain.push_back(new CubeActor({ -170,-20,-190 }, { 5.0f,50.0f, 5.0f }, { 153, 51, 255, 255 }));//2E pillier
    //Terrain.push_back(new CubeActor({ -120,-20,-230 }, { 5.0f,50.0f, 5.0f }, { 153, 51, 100, 255 }));
    Terrain.push_back(new CubeActor({ -140,-20,-180 }, { 5.0f,50.0f, 5.0f }, { 153, 51, 255, 255 }));//3e pillier
    Terrain.push_back(new CubeActor({ -120,-20,-205 }, { 5.0f,50.0f, 5.0f }, { 153, 51, 255, 255 })); // 4e pillier

    Terrain.push_back(new CubeActor({ -40,-20,-230 }, { 20.0f,50.0f, 20.0f }, { 0, 204, 0, 255 })); // fin 

                                //End// 
    EndPortals.emplace_back(new EndPortal({ -40,5,-230 }, { 3,3,3 }));
    Level::Start();
}


void Level03::Update()
{
    Level::Update();
}

void Level03::Draw()
{
    Level::Draw();
}

void Level03::DrawUi()
{
    Level::DrawUi();
}
