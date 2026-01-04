#pragma once

class Grid {
public:
    Grid(int w, int h);
    void Draw() const;

    int Width() const;
    int Height() const;

private:
    int width, height;
};
