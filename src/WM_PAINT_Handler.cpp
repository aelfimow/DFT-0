#include <Windows.h>

#include "WndProcParam.h"
#include "WndProcHandler.h"
#include "WM_PAINT_Handler.h"


WM_PAINT_Handler::WM_PAINT_Handler() :
    WndProcHandler {}
{
}

WM_PAINT_Handler::~WM_PAINT_Handler()
{
}

LRESULT WM_PAINT_Handler::operator()(const WndProcParam &param)
{
    PAINTSTRUCT ps;

    [[maybe_unused]] auto hdc = ::BeginPaint(param.hwnd(), &ps);

    ::EndPaint(param.hwnd(), &ps);

    return 0;
}
