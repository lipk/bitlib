/**
 * Functions for calculating the Hamming weight for different input sizes and
 * utilizing a range of techniques, the relative efficiency of which depend on
 * the underlying hardware and input characteristics.
 */

#ifndef BITLIB_POPCOUNT_H
#define BITLIB_POPCOUNT_H

#include <stdint.h>

/**
 * Calculates the Hamming weight of x.
 *
 * Complexity: 7 bit ops, 3 add/subs
 */
static inline uint8_t popcount_8(uint8_t x)
{
    x -= (x >> 1) & 0x55;
    x = (x & 0x33) + ((x >> 2) & 0x33);
    x = (x + (x >> 4)) & 0x0f;
    return x;
}

/**
 * Calculates the Hamming weight of x.
 *
 * Complexity: 9 bit ops, 4 add/subs
 */
static inline uint16_t popcount_16(uint16_t x)
{
    x -= (x >> 1) & 0x5555;
    x = (x & 0x3333) + ((x >> 2) & 0x3333);
    x = (x + (x >> 4)) & 0x0f0f;
    x += x >> 8;
    return x & 0x1f;
}

/**
 * Calculates the Hamming weight of x.
 *
 * Complexity: 10 bit ops, 5 add/subs
 */
static inline uint32_t popcount_32(uint32_t x)
{
    x -= (x >> 1) & 0x55555555;
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f;
    x += x >> 8;
    x += x >> 16;
    return x & 0x3f;
}

/**
 * Calculates the Hamming weight of x.
 *
 * Complexity: 11 bit ops, 6 add/subs
 */
static inline uint64_t popcount_64(uint64_t x)
{
    x -= (x >> 1) & 0x5555555555555555;
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;
    x += x >> 8;
    x += x >> 16;
    x += x >> 32;
    return x & 0x7f;
}

/**
 * Calculates the Hamming weight of x. This function uses less operations than
 * popcount_32 overall, but involves a multiplication.
 *
 * Complexity: 8 bit ops, 3 add/subs, 1 multiply
 */
static inline uint32_t popcount_mul_32(uint32_t x)
{
    x -= (x >> 1) & 0x55555555;
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f;
    return (x * 0x01010101) >> 24;
}

/**
 * Calculates the Hamming weight of x. This function uses less operations than
 * popcount_64 overall, but involves a multiplication.
 *
 * Complexity: 8 bit ops, 3 add/subs, 1 multiply
 */
static inline uint64_t popcount_mul_64(uint64_t x)
{
    x -= (x >> 1) & 0x5555555555555555;
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;
    return (x * 0x0101010101010101) >> 56;
}

/**
 * Calculates the Hamming weight of x. This function might be faster than
 * popcount_32 if there are few set bits in x.
 *
 * Complexity: 1 bit op, 2 subs/adds, 1 compare, 1 branch for each set bit in x
 */
static inline uint32_t popcount_iter_32(uint32_t x)
{
    uint32_t c;
    for (c=0; x > 0; ++c) {
        x &= x - 1;
    }
    return c;
}

/**
 * Calculates the Hamming weight of x. This function might be faster than
 * popcount_64 if there are few set bits in x.
 *
 * Complexity: 1 bit op, 2 subs/adds, 1 compare, 1 branch for each set bit in x
 */
static inline uint64_t popcount_iter_64(uint64_t x)
{
    uint64_t c;
    for (c=0; x > 0; ++c) {
        x &= x - 1;
    }
    return c;
}

#endif //BITLIB_POPCOUNT_H
