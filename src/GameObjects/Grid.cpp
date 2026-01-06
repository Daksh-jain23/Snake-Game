#include "GameObjects/Grid.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"

using namespace CursorController;
Grid::Grid(int w, int h) : width(w), height(h) {}

void Grid::Draw() const {
    for (int x = 0; x <= width; x++) {
        WriteAt(x * YtoX, 0, "X ");
        WriteAt(x * YtoX, height, "X ");
    }

    for (int y = 1; y <= height; y++) {
        WriteAt(0, y, "X");
        WriteAt(width * YtoX, y, "X");
    }
}


int Grid::Width() const { return width; }
int Grid::Height() const { return height; }
