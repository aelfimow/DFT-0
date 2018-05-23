#include <cstdint>

#include "Config.h"
#include "PCM24LE_to_FP.h"


PCM24LE_to_FP::PCM24LE_to_FP(uint8_t b0, uint8_t b1, uint8_t b2) :
    m_value { }
{
    const auto value0 = static_cast<size_t>(b0);
    const auto value1 = 256 * static_cast<size_t>(b1);
    const auto value2 = 65536 * static_cast<size_t>(b2);

    const auto sum = value0 + value1 + value2;

    const bool isNegative = (0 != (sum & 0x800000));

    if (isNegative)
    {
        auto sum_conv = ~(sum - 1);

        sum_conv &= 0x00FFFFFF;

        m_value = -static_cast<fp_t>(sum_conv);
    }
    else
    {
        m_value = static_cast<fp_t>(sum);
    }
}

PCM24LE_to_FP::~PCM24LE_to_FP()
{
}

fp_t PCM24LE_to_FP::value() const
{
    return m_value;
}
