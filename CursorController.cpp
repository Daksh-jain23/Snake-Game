#include <windows.h>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <thread>
#include <iostream>
#include <functional>
#include <deque>
using namespace std;

#define XtoY 0.4

class CursorController {
    inline static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    inline static bool cursorHidden = false;
public:
    static void RemoveCursor() {
        if (cursorHidden) return;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        if (GetConsoleCursorInfo(hConsole, &info)) {
            CONSOLE_CURSOR_INFO newInfo = info;
            newInfo.dwSize = 100;
            newInfo.bVisible = FALSE;
            SetConsoleCursorInfo(hConsole, &newInfo);
            cursorHidden = true;
        }
    }

    static void ResetCursor() {
        if (!hConsole) hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {0, 0};
        SetConsoleCursorPosition(hConsole, pos);
    }

    static void ClearScreen() {
        if (!hConsole) hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD cellsWritten;
        DWORD cellCount;
        COORD homeCoords = {0, 0};

        GetConsoleScreenBufferInfo(hConsole, &csbi);
        cellCount = csbi.dwSize.X * csbi.dwSize.Y;

        // Clear characters
        FillConsoleOutputCharacterA(
            hConsole,
            ' ',
            cellCount,
            homeCoords,
            &cellsWritten
        );

        // Clear attributes
        FillConsoleOutputAttribute(
            hConsole,
            csbi.wAttributes,
            cellCount,
            homeCoords,
            &cellsWritten
        );

        SetConsoleCursorPosition(hConsole, homeCoords);
    }

    static void SetSquareConsoleFont(short size = 8) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
        cfi.nFont = 0;
        cfi.dwFontSize.X = size; // width
        cfi.dwFontSize.Y = size; // height (same → square)
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_NORMAL;
        wcscpy_s(cfi.FaceName, L"Consolas");

        SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
    }

    static void WriteAt(int x, int y, const string& text) {
        if (!hConsole) hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
        SetConsoleCursorPosition(hConsole, pos);
        DWORD written = 0;
        WriteConsoleA(hConsole, text.c_str(), static_cast<DWORD>(text.size()), &written, nullptr);
    }
};




