#include "Core/Game.h"

Game::Game() : grid(48, 48){}

void Game::Run(){
    grid.Draw();
}