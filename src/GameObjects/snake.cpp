#include "GameObjects/Snake.h"
#include "Console/CursorController.h"

Snake::Snake(int x, int y, int l) {
    body.push_front({x, y});
    for(int i = 1;i < l;i++){
        Points p = body.front();
        body.push_back({p.x - 1, p.y});
    }
   
    grow = false;
} 

void Snake::Grow(){
    grow = true;
}




