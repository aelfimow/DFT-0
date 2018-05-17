#include <Windows.h>
#include <vector>
#include <list>
#include <complex>
#include <valarray>
#include <cstdint>

#include "Config.h"
#include "DFT_File.h"
#include "FileReader.h"
#include "DiscreteFourierTransform.h"


DFT_File *DFT_File::Inst = nullptr;


DFT_File::DFT_File(FileReader *pFileReader) :
    m_FileReader { pFileReader },
    m_DFT_Bank { }
{
    for (auto k = k_min; k < k_max; ++k)
    {
        m_DFT_Bank.push_back(new DiscreteFourierTransform { k, N });
    }
}

DFT_File::~DFT_File()
{
    delete m_FileReader;

    for (auto &elem: m_DFT_Bank)
    {
        delete elem;
    }
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
