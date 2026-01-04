#include "GameObjects/Grid.h"
#include "Console/CursorController.h"

Grid::Grid(int w, int h) : width(w), height(h) {}

void Grid::Draw() const {
    for (int x = 0; x <= width; x++) {
        CursorController::WriteAt(x, 0, "#");
        CursorController::WriteAt(x, height, "#");
    }
    for (int y = 0; y <= height; y++) {
        CursorController::WriteAt(0, y, "#");
        CursorController::WriteAt(width, y, "#");
    }
}

int Grid::Width() const { return width; }
int Grid::Height() const { return height; }
