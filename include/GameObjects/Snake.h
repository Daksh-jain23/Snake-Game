#pragma once
#include <deque>

struct Points{
    int x, y;
};

enum Direction{Up, Down, Left, Right};

class Snake{
    std::deque<Points> body;
    bool grow;
    Direction dir = Right;

public:
    Snake(int x, int y, int l);

    // Is growing or not
    void Grow();         

    // Draw the snakes 
    void Draw();    

    // Check if colliding with itself or not
    bool CheckSelfCollision();    

    // Gets Current Direction of movement
    Points GetCurrentDirection();       

    // Set Direction
    void SetDirection(Direction newdir);
};