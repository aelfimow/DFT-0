#include <Windows.h>
#include <map>

#include "MainWindow.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    hPrevInstance = hPrevInstance;
    szCmdLine = szCmdLine;

    MainWindow::Create(hInstance, iCmdShow);
    MainWindow::Show();
    MainWindow::Run();
    MainWindow::Destroy();

    return 0;
}
