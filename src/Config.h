#ifdef CONFIG_H
#error Already included
#else
#define CONFIG_H

// Floating point type
using fp_t = double;

constexpr fp_t pi = 3.1415926535897932384626433832795;

// Sample rate
constexpr size_t f_sample = 192000;

// Unknown frequency to be in the middle of DFT bank
constexpr size_t fx = 17200;

// DFT samples
constexpr size_t N = f_sample / 100;

// k-index of the fx frequency
constexpr size_t kx = (fx * N) / f_sample;

// Compute [k_min, k_max]
constexpr size_t Ks = 100;
constexpr size_t k_min = (kx > (Ks / 2)) ? (kx - (Ks / 2)) : 0;
constexpr size_t k_max = kx + (Ks / 2);

static_assert(k_min < k_max);

#endif
