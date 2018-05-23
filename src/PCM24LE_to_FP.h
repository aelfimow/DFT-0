#ifdef PCM24LE_TO_FP_H
#error Already included
#else
#define PCM24LE_TO_FP_H

class PCM24LE_to_FP
{
    public:
        explicit PCM24LE_to_FP(uint8_t b0, uint8_t b1, uint8_t b2);
        ~PCM24LE_to_FP();

        fp_t value() const;

    private:
        fp_t m_value;

    public:
        PCM24LE_to_FP() = delete;
        PCM24LE_to_FP(const PCM24LE_to_FP &instance) = delete;
        PCM24LE_to_FP(const PCM24LE_to_FP &&instance) = delete;
        PCM24LE_to_FP &operator=(const PCM24LE_to_FP &instance) = delete;
        PCM24LE_to_FP &operator=(const PCM24LE_to_FP &&instance) = delete;
};

#endif
