#pragma once
#include <string>
#include <windows.h>

namespace CursorController {

    extern HANDLE hConsole;
    extern bool cursorHidden;

    void RemoveCursor();
    void ResetCursor();
    void ClearScreen();
    void SetSquareConsoleFont(short size = 8);
    void WriteAt(int x, int y, const std::string& text);

}
