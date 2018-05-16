#include <Windows.h>

#include "WndProcHandler.h"
#include "WM_TIMER_Handler.h"


WM_TIMER_Handler::WM_TIMER_Handler() :
    WndProcHandler {}
{
}

WM_TIMER_Handler::~WM_TIMER_Handler()
{
}

LRESULT WM_TIMER_Handler::operator()(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
    lParam = lParam;
    wParam = wParam;
    hwnd = hwnd;

    (void)::MessageBox(nullptr, TEXT("Tick"), TEXT("WM_TIMER"), 0);

    return 0;
}
