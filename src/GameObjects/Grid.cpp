#include "GameObjects/Grid.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"
#include "Assets/TextAssets.h"

using namespace CursorController;
Grid::Grid(int w, int h) : width(w), height(h) {}

void Grid::Draw() const {
    for (int x = 0; x <= width; x++) {
        if(x == 0) {
            WriteAt(0, 0, TextAssets::WALL_CORNER_TL);
            WriteAt(0, height, TextAssets::WALL_CORNER_BL);
        } 
        else if(x == width) {
            WriteAt(x * YtoX, 0, TextAssets::WALL_CORNER_TR);
            WriteAt(x * YtoX, height, TextAssets::WALL_CORNER_BR);
        } 
        else {
            WriteAt(x * YtoX, 0, TextAssets::WALL_TB);
            WriteAt(x * YtoX, height, TextAssets::WALL_TB);
        }
    }

    for (int y = 1; y < height; y++) {
        WriteAt(0, y, TextAssets::WALL_LR);
        WriteAt(width * YtoX, y, TextAssets::WALL_LR);
    }
}


int Grid::Width() const { return width; }
int Grid::Height() const { return height; }
