#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <windows.h>

class Screen
{
private:
    static Screen *s_Instance;

public:
    Screen();
    // Register and Create a window
    void Init(const char *p_Title);
    // Move cursor to position(x; y)
    void GoTo(SHORT p_X, SHORT p_Y);
    // Change color text
    void SetColor(int p_BgColor, int p_TxtColor);
    // Hide Cursor
    void HideCurSor(BOOL p_SHow = true);
    // Change Console Window Size
    void SetWindowSize(SHORT p_W, SHORT p_H);
    // Change Screen Buffer Size
    void SetScreenBufferSize(SHORT p_W, SHORT p_H);
    // disable resize window
    void DisableResizeWindow();
    // Disable buttons Minimize, Maximize và Close
    void DisableCtrButton(bool p_Close, bool p_Min, bool p_Max);
    // Hide/Show Scroll bar
    void ShowScrollbar(BOOL p_Show = false);
    void CloseWindow();
    // global functions
    static Screen *GetInstance()
    {
        return s_Instance = (s_Instance == nullptr) ? new Screen() : s_Instance;
    }
    ~Screen();
};
#endif // __SCREEN_H__