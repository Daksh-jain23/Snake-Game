#include "Engine.cpp"
using namespace CursorController;

int main(){
    SetSquareConsoleFont(8);
    RemoveCursor();
    ClearScreen();
    
    Grid grid(100,100*XtoY);
    grid.DrawGrid();


}