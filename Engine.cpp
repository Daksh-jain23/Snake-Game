#include "CursorController.h"

using namespace std;
using namespace CursorController;

#define XtoY 0.4
class Grid{
    int width,height;
public:
    Grid(int w, int h){
        width = w+1;
        height = h+1;
    }
    void DrawGrid(){
        string s = "#";
        for(int i = 0;i <= width;i++){
            WriteAt(i,0,s);
            WriteAt(i,height,s);
        }
        for(int i = 0;i <= height;i++){
            WriteAt(0,i,s);
            WriteAt(width,i,s);
        }
    }
};
