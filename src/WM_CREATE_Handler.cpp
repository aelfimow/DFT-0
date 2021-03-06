#include <Windows.h>
#include <vector>
#include <list>
#include <cstdint>

#include "WndProcParam.h"
#include "WndProcHandler.h"
#include "WM_CREATE_Handler.h"
#include "DFT_File.h"
#include "FileReader.h"


WM_CREATE_Handler::WM_CREATE_Handler() :
    WndProcHandler {}
{
}

WM_CREATE_Handler::~WM_CREATE_Handler()
{
}

LRESULT WM_CREATE_Handler::operator()(const WndProcParam &param)
{
    TCHAR szFileName[MAX_PATH];
    ::ZeroMemory(szFileName, sizeof(szFileName));

    TCHAR szFileTitle[MAX_PATH];
    ::ZeroMemory(szFileTitle, sizeof(szFileTitle));

    OPENFILENAME ofn;
    ::ZeroMemory(&ofn, sizeof(ofn));

    ofn.hwndOwner      = param.hwnd();
    ofn.lpstrFilter    = TEXT("*");

    ofn.lpstrFile      = szFileName;
    ofn.nMaxFile       = MAX_PATH;

    ofn.lpstrFileTitle = szFileTitle;
    ofn.nMaxFileTitle  = MAX_PATH;

    ofn.lStructSize    = sizeof(ofn);

    auto result = ::GetOpenFileName(&ofn);

    if (result != 0)
    {
        DFT_File::Create(new FileReader { ofn.lpstrFile });
    }

    return 0;
}
