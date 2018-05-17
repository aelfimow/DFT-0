#include <Windows.h>
#include <vector>
#include <cstdint>

#include "DFT_File.h"
#include "FileReader.h"


DFT_File *DFT_File::Inst = nullptr;


DFT_File::DFT_File(FileReader *pFileReader) :
    m_FileReader { pFileReader }
{
}

DFT_File::~DFT_File()
{
    delete m_FileReader;
}

void DFT_File::Create(FileReader *pFileReader)
{
    if (Inst == nullptr)
    {
        Inst = new DFT_File { pFileReader };
    }
}

void DFT_File::Destroy()
{
    delete Inst;
    Inst = nullptr;
}
