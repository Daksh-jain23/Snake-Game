#pragma once
#include "GameObjects/Grid.h"
#include "GameObjects/Snake.h"

class Game{
    Grid grid;    // Grid
    Snake snake;  // Snake

    // Snake Controller
    void Control();


    public:
    Game();      

    void Run();   // Game Logic
};