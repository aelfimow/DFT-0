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
#include "PCM24LE_to_FP.h"


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
    delete Inst;
    Inst = new DFT_File { pFileReader };
}

void DFT_File::Destroy()
{
    delete Inst;
    Inst = nullptr;
}

void DFT_File::Compute()
{
    constexpr size_t maxBytes { 3 * N };

    const auto rawData = Inst->m_FileReader->read(maxBytes);

    if (maxBytes != rawData.size())
    {
        return;
    }

    std::valarray<fp_t> samples(N);

    for (size_t n = 0; n < N; ++n)
    {
        const auto i = 3 * n;

        const PCM24LE_to_FP pcm_conv { rawData[i], rawData[i + 1], rawData[i + 2] };

        samples[n] = pcm_conv.value();
    }

    std::vector<std::complex<fp_t>> result;

    for (auto it = Inst->m_DFT_Bank.begin(); it != Inst->m_DFT_Bank.end(); ++it)
    {
        auto pDFT = *it;

        result.push_back(pDFT->compute(samples));
    }
}
