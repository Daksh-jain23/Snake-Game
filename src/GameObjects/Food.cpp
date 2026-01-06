#include "GameObjects/Food.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"
using namespace CursorController;

Point& Food::GetPosition(){
    return pos;
}

void Food::SetPos(Point p){
    pos = p;
    WriteAt(p.x * YtoX, p.y, "@");
}