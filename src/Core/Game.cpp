#include "Core/Game.h"
#include "Console/CursorController.h"
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

bool GameOver(Snake &snake, Grid &grid){
    // Border Collision
    if(snake.GetHead().x == 0 || snake.GetHead().x == grid.Width()) return true;
    if(snake.GetHead().y == 0 || snake.GetHead().y == grid.Height()) return true;

    return snake.CheckSelfCollision();
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
        ResetCursor();
        if(GameOver(snake, grid)){
            WriteAt(grid.Width()/2, grid.Height()/2, "GAME OVER");
            WriteAt(grid.Width(), grid.Height(), " ");
            break;
        }
    }
}