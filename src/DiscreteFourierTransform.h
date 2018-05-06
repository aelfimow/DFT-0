#ifdef DISCRETE_FOURIER_TRANSFORM_H
#error Already included
#else
#define DISCRETE_FOURIER_TRANSFORM_H

class DiscreteFourierTransform
{
    public:
        explicit DiscreteFourierTransform(size_t k, size_t N);
        ~DiscreteFourierTransform();

        std::complex<fp_t> compute(const std::valarray<fp_t> &samples);

    private:
        const size_t m_k;
        const size_t m_N;
        std::valarray<std::complex<fp_t>> m_exp;

    public:
        DiscreteFourierTransform() = delete;
        DiscreteFourierTransform(const DiscreteFourierTransform &instance) = delete;
        DiscreteFourierTransform(const DiscreteFourierTransform &&instance) = delete;
        DiscreteFourierTransform &operator=(const DiscreteFourierTransform &instance) = delete;
        DiscreteFourierTransform &operator=(const DiscreteFourierTransform &&instance) = delete;
};

#endif
