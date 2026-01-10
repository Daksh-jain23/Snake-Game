#include "Core/Game.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"
#include "Utility/Random.h"
#include "Assets/TextAssets.h"
#include "Assets/ColorAssets.h"
#include <windows.h>
using namespace CursorController;

Game::Game() : grid(20, 20), snake(10, 10, 3, 10.0){}

Game::Game(int x, int y) : grid(x, y), snake(x/2, y/2, 3, 10.0){}
Game::Game(int initLength) : grid(20, 20), snake(10, 10, initLength, 10.0){};
Game::Game(double speed) : grid(20, 20), snake(10, 10, 3, speed){}

Game::Game(int x, int y, int initLength) : grid(x, y), snake(x/2, y/2, initLength, 10.0){}
Game::Game(int x, int y, double speed) : grid(x, y), snake(x/2, y/2, 3, speed){}
Game::Game(int initLength, double speed) : grid(20, 20), snake(10, 10, initLength, speed){}

Game::Game(int x, int y, int initLength, double speed) : grid(x, y), snake(x/2, y/2, initLength, speed){}

int Game::score = 0;

void Game::Control(){
    if((GetAsyncKeyState(VK_UP) & 0x8000) || (GetAsyncKeyState('W') & 0x8000)) {
        snake.SetDirection(Up);
        return;
    }
    if((GetAsyncKeyState(VK_DOWN) & 0x8000) || (GetAsyncKeyState('S') & 0x8000)) {
        snake.SetDirection(Down);
        return;
    }
    if((GetAsyncKeyState(VK_LEFT) & 0x8000) || (GetAsyncKeyState('A') & 0x8000)) {
        snake.SetDirection(Left);
        return;
    }
    if((GetAsyncKeyState(VK_RIGHT) & 0x8000) || (GetAsyncKeyState('D') & 0x8000)) {
        snake.SetDirection(Right);
        return;
    }
}

bool Game::IsGameOver(){
    // Border Collision
    if(snake.GetHead().x == 0 || snake.GetHead().x == grid.Width()) return true;
    if(snake.GetHead().y == 0 || snake.GetHead().y == grid.Height()) return true;

    return snake.CheckSelfCollision();
}

void Game::GameOver(){
    WriteAt(0, grid.Height()/2-TextAssets::TextHeight/2, TextAssets::GAME_OVER, ColorAssets::GAME_OVER_COLOR);
    MoveCursor(0, grid.Height() + 10);
}

bool Game::IsWin(){
    return snake.GetBody().size() >= (grid.Width() - 1) * (grid.Height() - 1);
}

void Game::Win(){
    WriteAt(0, grid.Height()/2-TextAssets::TextHeight/2, TextAssets::WIN, ColorAssets::TITLE_COLOR);
    MoveCursor(0, grid.Height() + 10);
}

void Game::SpawnFood(){
    Point foodPos;
    while(true){
        foodPos.x = Random::GetRandomInt(1, grid.Width() - 1);
        foodPos.y = Random::GetRandomInt(1, grid.Height() - 1);

        bool _not_colliding_with_body = true;
        for(auto &p : snake.GetBody()){
            if(p == foodPos){
                _not_colliding_with_body = false;
                break;
            }
        }

        if(_not_colliding_with_body) break;
    }

    food.SetPos(foodPos);
}

void Game::Eat(){
    if(snake.GetHead() == food.GetPosition()){
        score++;
        snake.Grow();
        if(!IsWin()) SpawnFood();
    }
}

void Game::Run(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ClearScreen();
    RemoveCursor();
    Random::Init();

    grid.Draw();
    snake.InitDraw();
    SpawnFood();

    const int frameDelay = 10; 
    int moveTimer = 0;
    int moveDelay = 1000 / snake.GetSpeed();

    while(true){
        Control();

        Sleep(frameDelay);
        moveTimer += frameDelay;

        if(moveTimer >= moveDelay){
            moveTimer = 0;

            Eat();
            snake.Move();
            snake.Draw();

            if(IsWin()){
                Win();
                break;
            }

            if(IsGameOver()){
                GameOver();
                break;
            }

            WriteAt(0, grid.Height()+1, "Score - " + std::to_string(score), ColorAssets::SCORE_COLOR);
        }
    }
}