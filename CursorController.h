#pragma once
#include <iostream>
#include <windows.h>
#include <string>

namespace CursorController {

    inline HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    inline bool cursorHidden = false;

    void RemoveCursor();
    void ResetCursor();
    void ClearScreen();
    void SetSquareConsoleFont(short size = 8);
    void WriteAt(int x, int y, const std::string& text);

}
