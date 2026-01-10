#include "GameObjects/Snake.h"
#include "Console/CursorController.h"
#include "Utility/Constants.h"
#include "Assets/TextAssets.h"
#include "Assets/ColorAssets.h"
using namespace CursorController;

/* Intializing snake
x,y - starting head posn
l = intial length
s = speed*/
Snake::Snake(int x, int y, int l, double s) {
    body.push_front({x, y});
    for(int i = 1;i < l;i++){
        Point p = body.front();
        body.push_back({p.x - i, p.y});
    }
    dir = Right;
    grow = false;
    speed = s;
} 

void Snake::Grow(){
    grow = true;
}

void Snake::InitDraw() {
    // draw head
    Point head = body.front();
    WriteAt(head.x * YtoX, head.y, TextAssets::SNAKE_HEAD, ColorAssets::SNAKE_HEAD_COLOR);

    // draw body
    for (int i = 1; i < body.size(); i++) {
        Point p = body[i];
        WriteAt(p.x * YtoX, p.y, TextAssets::SNAKE_BODY, ColorAssets::SNAKE_BODY_COLOR);
    }
}


void Snake::Draw() {
    Point head = body.front();
    WriteAt(head.x * YtoX, head.y, TextAssets::SNAKE_HEAD, ColorAssets::SNAKE_HEAD_COLOR);

    // turn previous head into body
    if (body.size() > 1) {
        Point prev = body[1];
        WriteAt(prev.x * YtoX, prev.y, TextAssets::SNAKE_BODY, ColorAssets::SNAKE_BODY_COLOR);
    }
}


void Snake::Move(){
    Point del = DirectionMap(dir);
    Point head = body.front();
    body.push_front({head.x + del.x, head.y + del.y});
   
    if(grow) grow = false;
    else {
        Point tail = body.back();
        body.pop_back();
        // removing tail
        WriteAt(tail.x * YtoX, tail.y, TextAssets::SPACE);
    }
}

bool Snake::CheckSelfCollision(){
    /*If any part of body is at same posn of head*/ 
    for(int i = 1;i < body.size();i++){
        if(body.front() == body[i]) return true;   
    }
    return false;
}

void Snake::SetDirection(Direction newdir){
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