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

    // Check Win condition
    bool IsWin();

    // On Win
    void Win();

public:
    Game();      
    Game(int x, int y);
    Game(int initLength);
    Game(double speed);
    Game(int x, int y, int initLength);
    Game(int x, int y, double speed);
    Game(int initLength, double speed);
    Game(int x, int y, int initLength, double speed);

    void Run();   // Game Logic
};