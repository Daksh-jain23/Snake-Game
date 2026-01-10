#include "GameObjects/Food.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"
#include "Assets/TextAssets.h"
#include "Assets/ColorAssets.h"
using namespace CursorController;

Point& Food::GetPosition(){
    return pos;
}

void Food::SetPos(Point p){
    pos = p;
    WriteAt(p.x * YtoX, p.y, TextAssets::FOOD, ColorAssets::FOOD_COLOR);
}