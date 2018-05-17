#include <Windows.h>

#include "WndProcHandler.h"
#include "WM_DESTROY_Handler.h"
#include "DFT_File.h"


WM_DESTROY_Handler::WM_DESTROY_Handler() :
    WndProcHandler {}
{
}

WM_DESTROY_Handler::~WM_DESTROY_Handler()
{
}

LRESULT WM_DESTROY_Handler::operator()([[maybe_unused]] HWND hwnd, [[maybe_unused]] WPARAM wParam, [[maybe_unused]] LPARAM lParam)
{
    PostQuitMessage(0);

    DFT_File::Destroy();

    return 0;
}
