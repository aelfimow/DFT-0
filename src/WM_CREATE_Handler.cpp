#include <Windows.h>

#include "WndProcHandler.h"
#include "WM_CREATE_Handler.h"


WM_CREATE_Handler::WM_CREATE_Handler() :
    WndProcHandler {}
{
}

WM_CREATE_Handler::~WM_CREATE_Handler()
{
}

LRESULT WM_CREATE_Handler::operator()([[maybe_unused]] HWND hwnd, [[maybe_unused]] WPARAM wParam, [[maybe_unused]] LPARAM lParam)
{
    return 0;
}
