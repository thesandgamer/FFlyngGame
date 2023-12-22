#pragma once
#include "Level.h"

class Level0 :
    public Level
{
public:
    Level0();
    ~Level0();

    void Start() override;
    void Update() override;
    void Draw() override;
    void DrawUi() override;

};

