#include "Utility/Coordinate.h"

// Map enum to point
Point DirectionMap(Direction dir){
    if(dir == Up) return {0, -1};
    if(dir == Down) return {0, 1};
    if(dir == Left) return {-1, 0};
    if(dir == Right) return {1, 0};
    return {0,0};
}