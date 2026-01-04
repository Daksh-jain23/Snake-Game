#include "GameObjects/Snake.h"
#include "Console/CursorController.h"
#include "utility/Constants.h"
using namespace CursorController;

Point DirectionMap(Direction dir){
    if(dir == Up) return {0, 1};
    if(dir == Down) return {0, -1};
    if(dir == Left) return {-1, 0};
    if(dir == Right) return {1, 0};
}

Snake::Snake(int x, int y, int l, double s) {
    body.push_front({x, y});
    for(int i = 1;i < l;i++){
        Point p = body.front();
        body.push_back({p.x - 1, p.y});
    }
   
    grow = false;
    speed = s;
} 

void Snake::Grow(){
    grow = true;
}

void Snake::Draw(){
    Point head = body.front();
    WriteAt(head.x * YtoX, head.y, "@");
    for(int i = 1;i < body.size();i++){
        Point a = body[i];
        WriteAt(a.x * YtoX, a.y, "O");
    }
}

void Snake::Move(){
    Point a = DirectionMap(dir);
    Point head = body.front();
    body.push_front({head.x + a.x, head.y + a.y});
    if(!grow) body.pop_back();
}

bool Snake::CheckSelfCollision(){
    for(int i = 1;i < body.size();i++){
        if(body.front() == body[i]) return true;
    }
    return false;
}

void Snake::SetDirection(Direction &newdir){
    if(dir == Up && newdir == Down) return;
    if(dir == Down && newdir == Up) return;
    if(dir == Left && newdir == Right) return;
    if(dir == Right && newdir == Left) return;

    dir = newdir;
}

std::deque<Point>& Snake::GetBody(){
    return body;
}

Point& Snake::GetHead(){
    return body.front();
}