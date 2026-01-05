#include "Core/Game.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"
#include <windows.h>
using namespace CursorController;

Game::Game() : grid(30, 30), snake(16,16,5,1){}

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
    MoveCursor(grid.Width() * YtoX, grid.Height());
}

void Game::Run(){
    RemoveCursor();
    grid.Draw();
    snake.InitDraw();
    while(true){
        Sleep(400);
        Control();
        snake.Move();
        snake.Draw();

        if(IsGameOver()){
           GameOver();
           break;
        }
    }
}