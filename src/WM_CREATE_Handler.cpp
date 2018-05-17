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
    TCHAR szFileName[MAX_PATH];
    ::ZeroMemory(szFileName, sizeof(szFileName));

    TCHAR szFileTitle[MAX_PATH];
    ::ZeroMemory(szFileTitle, sizeof(szFileTitle));

    OPENFILENAME ofn;
    ::ZeroMemory(&ofn, sizeof(ofn));

    ofn.hwndOwner      = hwnd;
    ofn.lpstrFilter    = TEXT("*");

    ofn.lpstrFile      = szFileName;
    ofn.nMaxFile       = MAX_PATH;

    ofn.lpstrFileTitle = szFileTitle;
    ofn.nMaxFileTitle  = MAX_PATH;

    ofn.lStructSize    = sizeof(ofn);

    auto result = ::GetOpenFileName(&ofn);

    if (result != 0)
    {
        // ofn.lpstrFile and ofn.lpstrFileTitle are valid
    }

    return 0;
}
