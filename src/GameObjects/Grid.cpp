#include "GameObjects/Grid.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"
#include "Assets/TextAssets.h"
#include "Assets/ColorAssets.h"
using namespace CursorController;
Grid::Grid(int w, int h) : width(w), height(h) {}

void Grid::Draw() const {
    for (int x = 0; x <= width; x++) {
        if(x == 0) {
            WriteAt(0, 0, TextAssets::WALL_CORNER_TL, ColorAssets::WALL_COLOR);
            WriteAt(0, height, TextAssets::WALL_CORNER_BL, ColorAssets::WALL_COLOR);
        } 
        else if(x == width) {
            WriteAt(x * YtoX, 0, TextAssets::WALL_CORNER_TR, ColorAssets::WALL_COLOR);
            WriteAt(x * YtoX, height, TextAssets::WALL_CORNER_BR, ColorAssets::WALL_COLOR);
        } 
        else {
            WriteAt(x * YtoX, 0, TextAssets::WALL_TB, ColorAssets::WALL_COLOR);
            WriteAt(x * YtoX, height, TextAssets::WALL_TB, ColorAssets::WALL_COLOR);
        }
    }

    for (int y = 1; y < height; y++) {
        WriteAt(0, y, TextAssets::WALL_LR, ColorAssets::WALL_COLOR);
        WriteAt(width * YtoX, y, TextAssets::WALL_LR, ColorAssets::WALL_COLOR);
    }
}


int Grid::Width() const { return width; }
int Grid::Height() const { return height; }
