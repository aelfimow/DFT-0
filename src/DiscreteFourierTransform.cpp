#include <complex>
#include <valarray>
#include <numeric>

#include "Config.h"
#include "DiscreteFourierTransform.h"


DiscreteFourierTransform::DiscreteFourierTransform(size_t k, size_t N) :
    m_exp(N)
{
    std::valarray<fp_t> ns(N);
    std::iota(std::begin(ns), std::end(ns), 0.0);

    const fp_t N_fp = static_cast<fp_t>(N);
    const fp_t k_fp = (-2.0 * pi * static_cast<fp_t>(k)) / N_fp;
    std::valarray<fp_t> ks(N);
    std::fill(std::begin(ks), std::end(ks), k_fp);

    const std::valarray<fp_t> im = ns * ks;

    for (size_t i = 0; i < N; ++i)
    {
        std::complex<fp_t> tmp { 0.0, im[i] };

        m_exp[i] = std::exp(tmp);
    }
}

DiscreteFourierTransform::~DiscreteFourierTransform()
{
}

std::complex<fp_t> DiscreteFourierTransform::compute(const std::valarray<fp_t> &samples)
{
    std::complex<fp_t> result;

    return result;
}
