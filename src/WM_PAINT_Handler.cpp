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

LRESULT WM_PAINT_Handler::operator()(HWND hwnd, [[maybe_unused]] WPARAM wParam, [[maybe_unused]] LPARAM lParam)
{
    PAINTSTRUCT ps;

    [[maybe_unused]] auto hdc = ::BeginPaint(hwnd, &ps);

    ::EndPaint(hwnd, &ps);

    return 0;
}
