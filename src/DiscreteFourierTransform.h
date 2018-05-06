#ifdef DISCRETE_FOURIER_TRANSFORM_H
#error Already included
#else
#define DISCRETE_FOURIER_TRANSFORM_H

class DiscreteFourierTransform
{
    public:
        DiscreteFourierTransform();
        ~DiscreteFourierTransform();

    public:
        DiscreteFourierTransform(const DiscreteFourierTransform &instance) = delete;
        DiscreteFourierTransform(const DiscreteFourierTransform &&instance) = delete;
        DiscreteFourierTransform &operator=(const DiscreteFourierTransform &instance) = delete;
        DiscreteFourierTransform &operator=(const DiscreteFourierTransform &&instance) = delete;
};

#endif
