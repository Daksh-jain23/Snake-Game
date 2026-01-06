#pragma once
#include "GameObjects/Grid.h"
#include "GameObjects/Snake.h"
#include "GameObjects/Food.h"
class Game{
    Grid grid;    // Grid
    Snake snake;  // Snake
    Food food;    // Food
    static int score;

    // Snake Controller
    void Control();

    // Check game over condition
    bool IsGameOver();

    // On Game over
    void GameOver();

    // Food Spawner
    void SpawnFood();

    // Check Food collision (eating)
    void Eat();

public:
    Game();      

    void Run();   // Game Logic
};