#pragma once
#include "Level.h"
class Level01 :
    public Level
{
public:
    Level01();
    ~Level01();

    void Start() override;
    void Update() override;
    void Draw() override;
    void DrawUi() override;

};
;

