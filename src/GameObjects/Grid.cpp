#include "GameObjects/Grid.h"
#include "Console/CursorController.h"
using namespace CursorController;
Grid::Grid(int w, int h) : width(w), height(h) {}

void Grid::Draw() const {
    for (int x = 0; x <= width; x++) {
        WriteAt(x, 0, "#");
        WriteAt(x, height, "#");
    }
    for (int y = 0; y <= height; y++) {
        WriteAt(0, y, "#");
        WriteAt(width, y, "#");
    }
}

int Grid::Width() const { return width; }
int Grid::Height() const { return height; }
