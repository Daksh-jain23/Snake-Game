#pragma once

struct Point{
    int x, y;
    bool operator==(const Point &a){
        return (x == a.x) && (y == a.y);
    }
};

enum Direction{Up, Down, Left, Right};

// Map direction enum to points struct
Point DirectionMap(Direction dir);