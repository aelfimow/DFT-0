#include <Windows.h>

#include "WndProcHandler.h"
#include "WM_COMMAND_Handler.h"
#include "main.h"


WM_COMMAND_Handler::WM_COMMAND_Handler() :
    WndProcHandler {},
    m_TimerID { 1 }
{
}

WM_COMMAND_Handler::~WM_COMMAND_Handler()
{
}

LRESULT WM_COMMAND_Handler::operator()(HWND hwnd, WPARAM wParam, [[maybe_unused]] LPARAM lParam)
{
    auto cmd = LOWORD(wParam);

    if (IDM_APP_START == cmd)
    {
        ::SetTimer(hwnd, m_TimerID, 10000, nullptr);
        return 0;
    }

    if (IDM_APP_STOP == cmd)
    {
        ::KillTimer(hwnd, m_TimerID);
        return 0;
    }

    if (IDM_APP_EXIT == cmd)
    {
        ::PostMessage(hwnd, WM_CLOSE, 0, 0);
        return 0;
    }

    return 0;
}
