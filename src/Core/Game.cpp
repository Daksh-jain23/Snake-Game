#include "Core/Game.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"
#include "Utility/Random.h"
#include <windows.h>
using namespace CursorController;

Game::Game() : grid(30, 30), snake(16,16,5,1){}

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
    WriteAt(grid.Width()/2 * YtoX - 5, grid.Height()/2, "GAME OVER!");
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


void Game::Run(){
    RemoveCursor();
    grid.Draw();
    snake.InitDraw();
    Random::Init();
    
    while(true){
        Sleep(400);
        Control();
        snake.Move();
        snake.Draw();
        if(GetAsyncKeyState('F')) SpawnFood();
        if(IsGameOver()){
           GameOver();
           break;
        }
    }
}