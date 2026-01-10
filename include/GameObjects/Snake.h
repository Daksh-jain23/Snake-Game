#pragma once
#include <deque>
#include "Utility/Coordinate.h"

class Snake{
    std::deque<Point> body;
    bool grow;
    Direction dir;
    double speed;
public:
    Snake(int x, int y, int l, double s);

    // Is growing or not
    void Grow();         

    // Intial Draw (Intialize one before run)
    void InitDraw();

    // Draw the snakes 
    void Draw();    

    // Move
    void Move();

    // Check if colliding with itself or not
    bool CheckSelfCollision();    

    // Set Direction
    void SetDirection(Direction newdir);

    // Get Body
    std::deque<Point>& GetBody();

    // Get Head
    Point& GetHead();

    //
    double GetSpeed() const;
};