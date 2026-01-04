#pragma once
#include <deque>

struct Point{
    int x, y;
    bool operator==(const Point &a){
        return (x == a.x) && (y == a.y);
    }
};

enum Direction{Up, Down, Left, Right};

Point DirectionMap(Direction dir);

class Snake{
    std::deque<Point> body;
    bool grow;
    Direction dir = Right;
    double speed;
public:
    Snake(int x, int y, int l, double s);

    // Is growing or not
    void Grow();         

    // Draw the snakes 
    void Draw();    

    // Move
    void Move();

    // Check if colliding with itself or not
    bool CheckSelfCollision();    

    // Set Direction
    void SetDirection(Direction &newdir);

    // Get Body
    std::deque<Point>& GetBody();

    // Get Head
    Point& GetHead();
};