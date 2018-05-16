#include <Windows.h>

#include "WndProcHandler.h"
#include "WM_PAINT_Handler.h"


WM_PAINT_Handler::WM_PAINT_Handler() :
    WndProcHandler {}
{
}

WM_PAINT_Handler::~WM_PAINT_Handler()
{
}

LRESULT WM_PAINT_Handler::operator()(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
    lParam = lParam;
    wParam = wParam;
    hwnd = hwnd;

    PAINTSTRUCT ps;

    auto hdc = ::BeginPaint(hwnd, &ps);

    ::EndPaint(hwnd, &ps);

    return 0;
}
