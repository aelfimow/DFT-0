#include <Windows.h>

#include "WndProcParam.h"
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

LRESULT WM_COMMAND_Handler::operator()(const WndProcParam &param)
{
    auto cmd = LOWORD(param.wParam());

    if (IDM_APP_START == cmd)
    {
        ::SetTimer(param.hwnd(), m_TimerID, 10000, nullptr);
        return 0;
    }

    if (IDM_APP_STOP == cmd)
    {
        ::KillTimer(param.hwnd(), m_TimerID);
        return 0;
    }

    if (IDM_APP_EXIT == cmd)
    {
        ::PostMessage(param.hwnd(), WM_CLOSE, 0, 0);
        return 0;
    }

    return 0;
}
