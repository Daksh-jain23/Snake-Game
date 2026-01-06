#pragma once
#include "Utility/Coordinate.h"

class Food{
    Point pos;
public: 
    // gives food location
    Point& GetPosition();

    // Set posn and draw
    void SetPos(Point p);
};