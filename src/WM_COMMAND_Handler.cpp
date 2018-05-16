#include <Windows.h>

#include "WndProcHandler.h"
#include "WM_COMMAND_Handler.h"
#include "main.h"


WM_COMMAND_Handler::WM_COMMAND_Handler() :
    WndProcHandler {}
{
}

WM_COMMAND_Handler::~WM_COMMAND_Handler()
{
}

LRESULT WM_COMMAND_Handler::operator()(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
    lParam = lParam;

    auto cmd = LOWORD(wParam);

    if (IDM_APP_START == cmd)
    {
        (void)::MessageBox(nullptr, TEXT("Start"), TEXT("WM_COMMAND"), 0);
        return 0;
    }

    if (IDM_APP_STOP == cmd)
    {
        (void)::MessageBox(nullptr, TEXT("Stop"), TEXT("WM_COMMAND"), 0);
        return 0;
    }

    if (IDM_APP_EXIT == cmd)
    {
        PostMessage(hwnd, WM_CLOSE, 0, 0);
        return 0;
    }

    return 0;
}
