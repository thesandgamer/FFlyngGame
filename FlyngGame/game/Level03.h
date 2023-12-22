#pragma once
#include "Level.h"
class Level03 :
    public Level
{
public:
    Level03();
    ~Level03();

    void Start() override;
    void Update() override;
    void Draw() override;
    void DrawUi() override;

};
;
