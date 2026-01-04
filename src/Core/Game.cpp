#include <Core/Game.h>

Game::Game() : grid(100, 100*XtoY){}

void Game::Run(){
    grid.Draw();
}