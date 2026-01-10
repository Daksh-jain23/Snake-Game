#include "Core/Game.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"
#include "Utility/Random.h"
#include "Assets/TextAssets.h"
#include "Assets/ColorAssets.h"
#include <windows.h>
using namespace CursorController;

Game::Game() : grid(20, 20), snake(10,10,5,10){}

int Game::score = 0;

void Game::Control(){
    if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
        snake.SetDirection(Up);
        return;
    }
    if(GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
        snake.SetDirection(Down);
        return;
    }
    if(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
        snake.SetDirection(Left);
        return;
    }
    if(GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
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
        SpawnFood();
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

            if(IsGameOver()){
                GameOver();
                break;
            }

            WriteAt(0, grid.Height()+2, "Score - " + std::to_string(score), ColorAssets::SCORE_COLOR);
        }
    }
}