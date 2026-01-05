#pragma once
#include "GameObjects/Grid.h"
#include "GameObjects/Snake.h"

class Game{
    Grid grid;    // Grid
    Snake snake;  // Snake

    // Snake Controller
    void Control();

    // Check game over condition
    bool IsGameOver();

    // On Game over
    void GameOver();

public:
    Game();      

    void Run();   // Game Logic
};