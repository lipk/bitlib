/**
 * Tools for shifting the positions of designated bits in various ways.
 *
 * Function families in this file:
 * scatter, scatter3: spread out a continuous sequence of bits
 * gather, gather3: collect a scattered set of bits into a continuous sequence
 * merge, merge3: interleave 2 or 3 of sequences respectively
 * separate, separate3: deinterleave a sequence into 2 or 3 components
 */

#ifndef BITLIB_SHIFT_H
#define BITLIB_SHIFT_H

#include <stdint.h>

/**
 * Shifts the lower 4 bits of x such that they take up the odd positions of the
 * bit string. The upper 4 bits must be 0 or the result is undefined.
 *
 * Complexity: 6 bit ops
 */
static inline uint8_t scatter_8(uint8_t x)
{
    x = (x | (x << 2)) & 0x33;
    x = (x | (x << 1)) & 0x55;

    return x;
}

/**
 * Shifts the lower 8 bits of x such that they take up the odd positions of the
 * bit string. The upper 8 bits must be 0 or the result is undefined.
 *
 * Complexity: 9 bit ops
 */
static inline uint16_t scatter_16(uint16_t x)
{
    x = (x | (x << 4)) & 0x0f0f;
    x = (x | (x << 2)) & 0x3333;
    x = (x | (x << 1)) & 0x5555;

    return x;
}

/**
 * Shifts the lower 16 bits of x such that they take up the odd positions of the
 * bit string. The upper 16 bits must be 0 or the result is undefined.
 *
 * Complexity: 12 bit ops
 */
static inline uint32_t scatter_32(uint32_t x)
{
    x = (x | (x << 8)) & 0x00ff00ff;
    x = (x | (x << 4)) & 0x0f0f0f0f;
    x = (x | (x << 2)) & 0x33333333;
    x = (x | (x << 1)) & 0x55555555;

    return x;
}

/**
 * Shifts the lower 32 bits of x such that they take up the odd positions of the
 * bit string. The upper 32 bits must be 0 or the result is undefined.
 *
 * Complexity: 15 bit ops
 */
static inline uint64_t scatter_64(uint64_t x)
{
    x = (x | (x << 16)) & 0x0000ffff0000ffff;
    x = (x | (x <<  8)) & 0x00ff00ff00ff00ff;
    x = (x | (x <<  4)) & 0x0f0f0f0f0f0f0f0f;
    x = (x | (x <<  2)) & 0x3333333333333333;
    x = (x | (x <<  1)) & 0x5555555555555555;

    return x;
}

/**
 * Interleave the lower 4 bits of x and y. The bits of x will take up the odd,
 * the bits of y the even positions. The upper 4 bits must be 0 for both, or the
 * result is undefined.
 *
 * Complexity: 13 bit ops
 */
static inline uint8_t merge_8(uint8_t x, uint8_t y)
{
    uint16_t m = (uint16_t)x | ((uint16_t)y << 8);
    m = scatter_16(m);
    return m | (m >> 7);
}

/**
 * Interleave the lower 4 bits of x and y. The bits of x will take up the odd,
 * the bits of y the even positions. The upper 4 bits must be 0 for both, or the
 * result is undefined.
 *
 * This function performs more operations than merge_8, but doesn't use
 * internal variables larger than its operands.
 *
 * Complexity: 14 bit ops
 */
static inline uint8_t merge_nwe_8(uint8_t x, uint8_t y)
{
    x = scatter_8(x);
    y = scatter_8(y);
    return x | (y << 1);
}

/**
 * Interleave the lower 8 bits of x and y. The bits of x will take up the odd,
 * the bits of y the even positions. The upper 8 bits must be 0 for both, or the
 * result is undefined.
 *
 * Complexity: 16 bit ops
 */
static inline uint16_t merge_16(uint16_t x, uint16_t y)
{
    uint32_t m = (uint32_t)x | ((uint32_t)y << 16);
    m = scatter_32(m);
    return m | (m >> 15);
}

/**
 * Interleave the lower 8 bits of x and y. The bits of x will take up the odd,
 * the bits of y the even positions. The upper 8 bits must be 0 for both, or the
 * result is undefined.
 *
 * This function performs more operations than merge_16, but doesn't use
 * internal variables larger than its operands.
 *
 * Complexity: 20 bit ops
 */
static inline uint16_t merge_nwe_16(uint16_t x, uint16_t y)
{
    x = scatter_16(x);
    y = scatter_16(y);
    return x | (y << 1);
}

/**
 * Interleave the lower 16 bits of x and y. The bits of x will take up the odd,
 * the bits of y the even positions. The upper 16 bits must be 0 for both, or
 * the result is undefined.
 *
 * Complexity: 19 bit ops
 */
static inline uint32_t merge_32(uint32_t x, uint32_t y)
{
    uint64_t m = (uint64_t)x | ((uint64_t)y << 32);
    m = scatter_64(m);
    return m | (m >> 31);
}

/**
 * Interleave the lower 16 bits of x and y. The bits of x will take up the odd,
 * the bits of y the even positions. The upper 16 bits must be 0 for both, or
 * the result is undefined.
 *
 * This function performs more operations than merge_32, but doesn't use
 * internal variables larger than its operands.
 *
 * Complexity: 26 bit ops
 */
static inline uint32_t merge_nwe_32(uint32_t x, uint32_t y)
{
    x = scatter_32(x);
    y = scatter_32(y);
    return x | (y << 1);
}

/**
 * Interleave the lower 32 bits of x and y. The bits of x will take up the odd,
 * the bits of y the even positions. The upper 16 bits must be 0 for both, or
 * the result is undefined.
 *
 * Complexity: 32 bit ops
 */
static inline uint64_t merge_64(uint64_t x, uint64_t y)
{
    x = scatter_64(x);
    y = scatter_64(y);
    return x | (y << 1);
}

/**
 * Shift the odd bits of x into the lower half. Non-odd bits must be 0 or the
 * result is undefined.
 *
 * Complexity: 6 bit ops
 */
static inline uint8_t gather_8(uint8_t x)
{
    x = (x | (x >> 1)) & 0x33u;
    x = (x | (x >> 2)) & 0x0fu;
    return x;
}

/**
 * Shift the odd bits of x into the lower half. Non-odd bits must be 0 or the
 * result is undefined.
 *
 * Complexity: 9 bit ops
 */
static inline uint16_t gather_16(uint16_t x)
{
    x = (x | (x >> 1)) & 0x3333;
    x = (x | (x >> 2)) & 0x0f0f;
    x = (x | (x >> 4)) & 0x00ff;
    return x;
}

/**
 * Shift the odd bits of x into the lower half. Non-odd bits must be 0 or the
 * result is undefined.
 *
 * Complexity: 12 bit ops
 */
static inline uint32_t gather_32(uint32_t x)
{
    x = (x | (x >> 1)) & 0x33333333;
    x = (x | (x >> 2)) & 0x0f0f0f0f;
    x = (x | (x >> 4)) & 0x00ff00ff;
    x = (x | (x >> 8)) & 0x0000ffff;
    return x;
}

/**
 * Shift the odd bits of x into the lower half. Non-odd bits must be 0 or the
 * result is undefined.
 *
 * Complexity: 15 bit ops
 */
static inline uint64_t gather_64(uint64_t x)
{
    x = (x | (x >> 1)) & 0x3333333333333333;
    x = (x | (x >> 2)) & 0x0f0f0f0f0f0f0f0f;
    x = (x | (x >> 4)) & 0x00ff00ff00ff00ff;
    x = (x | (x >> 8)) & 0x0000ffff0000ffff;
    x = (x | (x >> 16)) & 0x00000000ffffffff;
    return x;
}

/**
 * Place the odd bits of n into x and the even bits into y. This is faster than
 * calling gather twice.
 *
 * Complexity: 14 bit ops
 */
static inline void separate_8(uint8_t n, uint8_t *x, uint8_t *y)
{
    uint16_t m = ((uint16_t) n | ((uint16_t) n << 7)) & 0x5555;
    m = gather_16(m);
    *x = m & 0x0f;
    *y = m >> 4;
}

/**
 * Place the odd bits of n into x and the even bits into y.
 *
 * This function performs more operations than separate_8, but doesn't use
 * internal variables larger than its operands.
 *
 *
 * Complexity: 15 bit ops
 */
static inline void separate_nwe_8(uint8_t n, uint8_t *x, uint8_t *y)
{
    *x = gather_8(n & 0x55);
    *y = gather_8((n & 0xaa) >> 1);
}

/**
 * Place the odd bits of n into x and the even bits into y. This is faster than
 * calling gather twice.
 *
 * Complexity: 17 bit ops
 */
static inline void separate_16(uint16_t n, uint16_t *x, uint16_t *y)
{
    uint32_t m = ((uint32_t) n | ((uint32_t) n << 15)) & 0x55555555;
    m = gather_32(m);
    *x = m & 0x00ff;
    *y = m >> 8;
}

/**
 * Place the odd bits of n into x and the even bits into y.
 *
 * This function performs more operations than separate_16, but doesn't use
 * internal variables larger than its operands.
 *
 * Complexity: 21 bit ops
 */
static inline void separate_nwe_16(uint16_t n, uint16_t *x, uint16_t *y)
{
    *x = gather_16(n & 0x5555);
    *y = gather_16((n & 0xaaaa) >> 1);
}

/**
 * Place the odd bits of n into x and the even bits into y. This is faster than
 * calling twice.
 *
 * Complexity: 20 bit ops
 */
static inline void separate_32(uint32_t n, uint32_t *x, uint32_t *y)
{
    uint64_t m = ((uint64_t) n | ((uint64_t) n << 31)) & 0x5555555555555555;
    m = gather_64(m);
    *x = m & 0x0000ffff;
    *y = m >> 16;
}

/**
 * Place the odd bits of n into x and the even bits into y. This function is
 * slower than separate_32, but does not use 64 bit variables.
 *
 * Complexity: 27 bit ops
 */
static inline void separate_nwe_32(uint32_t n, uint32_t *x, uint32_t *y)
{
    *x = gather_32(n & 0x55555555);
    *y = gather_32((n & 0xaaaaaaaa) >> 1);
}

/**
 * Place the odd bits of n into x and the even bits into y.
 *
 * Complexity: 33 bit ops
 */
static inline void separate_64(uint64_t n, uint64_t *x, uint64_t *y)
{
    *x = gather_64(n & 0x5555555555555555);
    *y = gather_64((n & 0xaaaaaaaaaaaaaaaa) >> 1);
}

/**
 * Shift the lowest 3 bits of x such that they take up every third position in
 * the bitstring. The upper bits must be 0 or the result is undefined.
 *
 * Complexity: 6 bit ops
 */
static inline uint8_t scatter3_8(uint8_t x)
{
    x = (x | (x << 4)) & 0xc7;
    x = (x | (x << 2)) & 0x49;
    return x;
}

/**
 * Shift the lowest 6 bits of x such that they take up every third position in
 * the bitstring. The upper bits must be 0 or the result is undefined.
 *
 * Complexity: 9 bit ops
 */
static inline uint16_t scatter3_16(uint16_t x)
{
    x = (x | (x << 8)) & 0xf03f;
    x = (x | (x << 4)) & 0x71c7;
    x = (x | (x << 2)) & 0x9249;
    return x;
}

/**
 * Shift the lowest 11 bits of x such that they take up every third position in
 * the bitstring. The upper bits must be 0 or the result is undefined.
 *
 * Complexity: 12 bit ops
 */
static inline uint32_t scatter3_32(uint32_t x)
{
    x = (x | (x << 16)) & 0xff000fff;
    x = (x | (x << 8)) & 0x3f03f03f;
    x = (x | (x << 4)) & 0xc71c71c7;
    x = (x | (x << 2)) & 0x49249249;
    return x;
}

/**
 * Shift the lowest 22 bits of x such that they take up every third position in
 * the bitstring. The upper bits must be 0 or the result is undefined.
 *
 * Complexity: 15 bit ops
 */
static inline uint64_t scatter3_64(uint64_t x)
{
    x = (x | (x << 32)) & 0xffff000000ffffff;
    x = (x | (x << 16)) & 0x0fff000fff000fff;
    x = (x | (x << 8)) & 0xf03f03f03f03f03f;
    x = (x | (x << 4)) & 0x71c71c71c71c71c7;
    x = (x | (x << 2)) & 0x9249249249249249;
    return x;
}

/**
 * Interleave x, y and z such that the bits of each will take up the first,
 * second and third positions in every triad respectively. The lowest 3 bits of
 * x and y, and the lowest 2 bits of z will be used. The upper bits must be 0
 * for all three, or the result is undefined.
 *
 * Complexity: 19 bit ops
 */
static inline uint8_t merge3_8(uint8_t x, uint8_t y, uint8_t z)
{
    x = scatter3_8(x);
    y = scatter3_8(y);
    z = (z | (z << 4)) & 0xc7;

    return x | (y << 1) | (z << 2);
}

/**
 * Interleave x, y and z such that the bits of each will take up the first,
 * second and third positions in every triad respectively. The lowest 6 bits of
 * x, and the lowest 5 bits of y and z will be used. The upper bits must be 0
 * for all three, or the result is undefined.
 *
 * This function performs more operations than merge3_16, but doesn't use
 * internal variables larger than its operands.
 *
 * Complexity: 31 bit ops
 */
static inline uint16_t merge3_16(uint16_t x, uint16_t y, uint16_t z)
{
    x = scatter3_16(x);
    y = scatter3_16(y);
    z = scatter3_16(z);

    return x | (y << 1) | (z << 2);
}

/**
 * Interleave x, y and z such that the bits of each will take up the first,
 * second and third positions in every triad respectively. The lowest 11 bits of
 * x and y, and the lowest 10 bits z will be used. The upper bits must be 0 for
 * all three, or the result is undefined.
 *
 * Complexity: 40 bit ops
 */
static inline uint32_t merge3_32(uint32_t x, uint32_t y, uint32_t z)
{
    x = scatter3_32(x);
    y = scatter3_32(y);
    z = scatter3_32(z);

    return x | (y << 1) | (z << 2);
}

/**
 * Interleave x, y and z such that the bits of each will take up the first,
 * second and third positions in every triad respectively. The lowest 22 bits of
 * x, and the lowest 21 bits of y and z will be used. The upper bits must be 0
 * for all three, or the result is undefined.
 *
 * Complexity: 49 bit ops
 */
static inline uint64_t merge3_64(uint64_t x, uint64_t y, uint64_t z)
{
    x = scatter3_64(x);
    y = scatter3_64(y);
    z = scatter3_64(z);

    return x | (y << 1) | (z << 2);
}

/**
 * Shift the first bit of every triad of x into the lowest positions. The second
 * and third bits must be 0 or the result is undefined.
 *
 * Complexity: 6 bit ops
 */
static inline uint8_t gather3_8(uint8_t x)
{

    x = (x | (x >> 2)) & 0xc7;
    x = (x | (x >> 4)) & 0x3f;
    return x;
}

/**
 * Shift the first bit of every triad of x into the lowest positions. The second
 * and third bits must be 0 or the result is undefined.
 *
 * Complexity: 9 bit ops
 */
static inline uint16_t gather3_16(uint16_t x)
{
    x = (x | (x >> 2)) & 0x71c7;
    x = (x | (x >> 4)) & 0xf03f;
    x = (x | (x >> 8)) & 0x0fff;
    return x;
}

/**
 * Shift the first bit of every triad of x into the lowest positions. The second
 * and third bits must be 0 or the result is undefined.
 *
 * Complexity: 12 bit ops
 */
static inline uint32_t gather3_32(uint32_t x)
{
    x = (x | (x >> 2)) & 0xc71c71c7;
    x = (x | (x >> 4)) & 0x3f03f03f;
    x = (x | (x >> 8)) & 0xff000fff;
    x = (x | (x >> 16)) & 0x00ffffff;
    return x;
}

/**
 * Shift the first bit of every triad of x into the lowest positions. The second
 * and third bits must be 0 or the result is undefined.
 *
 * Complexity: 15 bit ops
 */
static inline uint64_t gather3_64(uint64_t x)
{
    x = (x | (x >> 2)) & 0x71c71c71c71c71c7;
    x = (x | (x >> 4)) & 0xf03f03f03f03f03f;
    x = (x | (x >> 8)) & 0x0fff000fff000fff;
    x = (x | (x >> 16)) & 0xffff000000ffffff;
    x = (x | (x >> 32)) & 0x0000ffffffffffff;
    return x;
}

/**
 * Place the first, second and third bits of every triad into the lowest
 * positions of x, y and z respectively.
 *
 * Complexity: 23 bit ops
 */
static inline void separate3_8(uint8_t n, uint8_t *x, uint8_t *y, uint8_t *z)
{
    *x = gather3_8(n & 0x49);
    *y = gather3_8((n >> 1) & 0x49);
    *z = gather3_8((n >> 2) & 0x49);
}

/**
 * Place the first, second and third bits of every triad into the lowest
 * positions of x, y and z respectively.
 *
 * Complexity: 32 bit ops
 */
static inline void separate3_16(uint16_t n, uint16_t *x, uint16_t *y, uint16_t *z)
{
    *x = gather3_16(n & 0x9249);
    *y = gather3_16((n >> 1) & 0x9249);
    *z = gather3_16((n >> 2) & 0x9249);
}

/**
 * Place the first, second and third bits of every triad into the lowest
 * positions of x, y and z respectively.
 *
 * Complexity: 41 bit ops
 */
static inline void separate3_32(uint32_t n, uint32_t *x, uint32_t *y, uint32_t *z)
{
    *x = gather3_32(n & 0x49249249);
    *y = gather3_32((n >> 1) & 0x49249249);
    *z = gather3_32((n >> 2) & 0x49249249);
}

/**
 * Place the first, second and third bits of every triad into the lowest
 * positions of x, y and z respectively.
 *
 * Complexity: 50 bit ops
 */
static inline void separate3_64(uint64_t n, uint64_t *x, uint64_t *y, uint64_t *z)
{
    *x = gather3_64(n & 0x9249249249249249);
    *y = gather3_64((n >> 1) & 0x9249249249249249);
    *z = gather3_64((n >> 2) & 0x9249249249249249);
}

#endif
