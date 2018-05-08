#include <Windows.h>
#include <vector>
#include <cstdint>

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

std::vector<uint8_t> FileReader::read(size_t maxBytes)
{
    std::vector<uint8_t> buffer(maxBytes);
    DWORD readBytes = 0;

    auto ReadFileResult = ::ReadFile(m_hFile, buffer.data(), buffer.size(), &readBytes, nullptr);

    if (FALSE == ReadFileResult)
    {
        std::vector<uint8_t> emptyBuffer;
        return emptyBuffer;
    }

    if (0 == readBytes)
    {
        std::vector<uint8_t> emptyBuffer;
        return emptyBuffer;
    }

    if (readBytes == buffer.size())
    {
        return buffer;
    }

    buffer.resize(readBytes);

    return buffer;
}
