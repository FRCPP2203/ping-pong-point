#include "Screen.h"

Screen::Screen()
{
}

void Screen::Init(const char *p_Title)
{
    // set window's title
    SetConsoleTitle(p_Title);

    // disable hightline
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void Screen::GoTo(SHORT p_X, SHORT p_Y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = p_X;
    Position.Y = p_Y;

    SetConsoleCursorPosition(hStdout, Position);
}

void Screen::SetColor(int p_BgColor, int p_TxtColor)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = p_BgColor * 16 + p_TxtColor;
    SetConsoleTextAttribute(hStdout, color_code);
}

void Screen::HideCurSor(BOOL p_SHow)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = !p_SHow;
    SetConsoleCursorInfo(handle, &ConCurInf);
}

void Screen::SetWindowSize(SHORT p_W,  SHORT p_H)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = p_W;
    WindowSize.Bottom = p_H;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void Screen::SetScreenBufferSize(SHORT p_W,  SHORT p_H)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = p_W;
    NewSize.Y = p_H;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void Screen::DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void Screen::DisableCtrButton(bool p_Close, bool p_Min, bool p_Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (p_Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (p_Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (p_Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void Screen::ShowScrollbar(BOOL p_Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, p_Show);
}

void Screen::CloseWindow()
{
}

Screen::~Screen()
{
}
