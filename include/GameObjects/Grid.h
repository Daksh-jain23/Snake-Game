#pragma once

class Grid {
public:
    Grid(int w, int h);
    void Draw() const;    // Draw Grid

    int Width() const;    // Get width
    int Height() const;   // Get height

private:
    int width, height;
};
