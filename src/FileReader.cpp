#include <Windows.h>

#include "FileReader.h"


FileReader::FileReader(const TCHAR *pName) :
    m_hFile { ::CreateFile(
            pName,
            GENERIC_READ,
            0,
            nullptr,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            nullptr) }
{
}

FileReader::~FileReader()
{
    ::CloseHandle(m_hFile);
}
