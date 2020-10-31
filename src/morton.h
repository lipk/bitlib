/**
 * Tools for working with Morton codes (aka Z-order curve indices) both in 2D
 * and 3D. Many algorithms in this file simply refer to identical operations in
 * shift.h.
 *
 * Function families in this file:
 * morton, morton3: calculate a 2D or 3D Morton code (same as merge/merge3)
 * invmorton, invmorton3: invert a 2D or 3D Morton code (same as separate/separate3)
 * mortonxm, morton3xm: Morton code of left (x-1) neighbor
 * mortonxp, morton3xp: Morton code of right (x+1) neighbor
 * mortonym, morton3ym: Morton code of top (y-1) neighbor
 * mortonyp, morton3yp: Morton code of bottom (y+1) neighbor
 * morton3zm: Morton code of back (z-1) neighbor
 * morton3zp: Morton code of back (z+1) neighbor
 */

#ifndef BITLIB_MORTON_H
#define BITLIB_MORTON_H

#include <stdint.h>
#include "shift.h"

/**
 * Calculate an 8 bit 2D Morton code. Identical to merge_8.
 */
#define morton_8 merge_8

/**
 * Calculate an 8 bit 2D Morton code. Identical to merge_nwe_8.
 */
#define morton_nwe_8 merge_nwe_8

/**
 * Calculate a 16 bit 2D Morton code. Identical to merge_16.
 */
#define morton_16 merge_16

/**
 * Calculate a 16 bit 2D Morton code. Identical to merge_nwe_16.
 */
#define morton_nwe_16 merge_nwe_16

/**
 * Calculate a 32 bit 2D Morton code. Identical to merge_32.
 */
#define morton_32 merge_32

/**
 * Calculate a 64 bit 2D Morton code. Identical to merge_64.
 */
#define morton_64 merge_64

/**
 * Calculate an 8 bit 3D Morton code. Identical to merge3_8.
 */
#define morton3_8 merge3_8

/**
 * Calculate a 16 bit 3D Morton code. Identical to merge3_16.
 */
#define morton3_16 merge3_16

/**
 * Calculate a 32 bit 3D Morton code. Identical to merge3_32.
 */
#define morton3_32 merge3_32

/**
 * Calculate a 64 bit 3D Morton code. Identical to merge3_64.
 */
#define morton3_64 merge3_64

/**
 * Invert an 8 bit 2D Morton code. Identical to separate_8.
 */
#define invmorton_8 separate_8

/**
 * Invert an 8 bit 2D Morton code. Identical to separate_nwe_8.
 */
#define invmorton_nwe_8 separate_nwe_8

/**
 * Invert a 16 bit 2D Morton code. Identical to separate_16.
 */
#define invmorton_16 separate_16

/**
 * Invert a 16 bit 2D Morton code. Identical to separate_nwe_16.
 */
#define invmorton_nwe_16 separate_nwe_16

/**
 * Invert a 32 bit 2D Morton code. Identical to separate_32.
 */
#define invmorton_32 separate_32

/**
 * Invert a 32 bit 2D Morton code. Identical to separate_nwe_32.
 */
#define invmorton_nwe_32 separate_nwe_32

/**
 * Invert a 64 bit Morton code. Identical to separate_64.
 */
#define invmorton_64 separate_64

/**
 * Invert an 8 bit 3D Morton code. Identical to separate3_8.
 */
#define invmorton3_8 separate3_8

/**
 * Invert a 16 bit 3D Morton code. Identical to separate3_16.
 */
#define invmorton3_16 separate3_16

/**
 * Invert a 32 bit 3D Morton code. Identical to separate3_32.
 */
#define invmorton3_32 separate3_32

/**
 * Invert a 64 bit 3D Morton code. Identical to separate3_64.
 */
#define invmorton3_64 separate3_64

/**
 * Calculate the Morton code of the top neighbor (x; y-1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonym_8(uint8_t m)
{
    return ((m & 0xaa) - 1 & 0xaa) | (m & 0x55);
}

/**
 * Calculate the Morton code of the top neighbor (x; y-1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonym_16(uint16_t m)
{
    return ((m & 0xaaaa) - 1 & 0xaaaa) | (m & 0x5555);
}

/**
 * Calculate the Morton code of the top neighbor (x; y-1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonym_32(uint32_t m)
{
    return ((m & 0xaaaaaaaa) - 1 & 0xaaaaaaaa) | (m & 0x55555555);
}

/**
 * Calculate the Morton code of the top neighbor (x; y-1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonym_64(uint64_t m)
{
    return ((m & 0xaaaaaaaaaaaaaaaa) - 1 & 0xaaaaaaaaaaaaaaaa) | (m & 0x5555555555555555);
}

/**
 * Calculate the Morton code of the bottom neighbor (x; y+1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonyp_8(uint8_t m)
{
    return ((m | 0x55) + 1 & 0xaa) | (m & 0x55);
}

/**
 * Calculate the Morton code of the bottom neighbor (x; y+1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonyp_16(uint16_t m)
{
    return ((m | 0x5555) + 1 & 0xaaaa) | (m & 0x5555);
}

/**
 * Calculate the Morton code of the bottom neighbor (x; y+1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonyp_32(uint32_t m)
{
    return ((m | 0x55555555) + 1 & 0xaaaaaaaa) | (m & 0x55555555);
}

/**
 * Calculate the Morton code of the bottom neighbor (x; y+1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonyp_64(uint64_t m)
{
    return ((m | 0x5555555555555555) + 1 & 0xaaaaaaaaaaaaaaaa) | (m & 0x5555555555555555);
}

/**
 * Calculate the Morton code of the left neighbor (x-1; y) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonxm_8(uint8_t m)
{
    return ((m & 0x55) - 1 & 0x55) | (m & 0xaa);
}

/**
 * Calculate the Morton code of the left neighbor (x-1; y) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonxm_16(uint16_t m)
{
    return ((m & 0x5555) - 1 & 0x5555) | (m & 0xaaaa);
}

/**
 * Calculate the Morton code of the left neighbor (x-1; y) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonxm_32(uint32_t m)
{
    return ((m & 0x55555555) - 1 & 0x55555555) | (m & 0xaaaaaaaa);
}

/**
 * Calculate the Morton code of the left neighbor (x-1; y) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonxm_64(uint64_t m)
{
    return ((m & 0x5555555555555555) - 1 & 0x5555555555555555) | (m & 0xaaaaaaaaaaaaaaaa);
}

/**
 * Calculate the Morton code of the right neighbor (x+1; y) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonxp_8(uint8_t m)
{
    return ((m | 0xaa) + 1 & 0x55) | (m & 0xaa);
}

/**
 * Calculate the Morton code of the right neighbor (x+1; y) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonxp_16(uint16_t m)
{
    return ((m | 0xaaaa) + 1 & 0x5555) | (m & 0xaaaa);
}

/**
 * Calculate the Morton code of the right neighbor (x+1; y) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonxp_32(uint32_t m)
{
    return ((m | 0xaaaaaaaa) + 1 & 0x55555555) | (m & 0xaaaaaaaa);
}

/**
 * Calculate the Morton code of the right neighbor (x+1; y) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonxp_64(uint64_t m)
{
    return ((m | 0xaaaaaaaaaaaaaaaa) + 1 & 0x5555555555555555) | (m & 0xaaaaaaaaaaaaaaaa);
}

/**
 * Calculate the Morton code of the top neighbor (x; y-1; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonym3_8(uint8_t m)
{
    return ((m & 0x92) - 1 & 0x92) | (m & 0x6d);
}

/**
 * Calculate the Morton code of the top neighbor (x; y-1; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonym3_16(uint16_t m)
{
    return ((m & 0x2492) - 1 & 0x2492) | (m & 0xdb6d);
}

/**
 * Calculate the Morton code of the top neighbor (x; y-1; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonym3_32(uint32_t m)
{
    return ((m & 0x92492492) - 1 & 0x92492492) | (m & 0x6db6db6d);
}

/**
 * Calculate the Morton code of the top neighbor (x; y-1; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonym3_64(uint64_t m)
{
    return ((m & 0x2492492492492492) - 1 & 0x2492492492492492) | (m & 0xdb6db6db6db6db6d);
}

/**
 * Calculate the Morton code of the bottom neighbor (x; y+1; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonyp3_8(uint8_t m)
{
    return ((m | 0x6d) + 1 & 0x92) | (m & 0x6d);
}

/**
 * Calculate the Morton code of the bottom neighbor (x; y+1; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonyp3_16(uint16_t m)
{
    return ((m | 0xdb6d) + 1 & 0x2492) | (m & 0xdb6d);
}

/**
 * Calculate the Morton code of the bottom neighbor (x; y+1; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonyp3_32(uint32_t m)
{
    return ((m | 0x6db6db6d) + 1 & 0x92492492) | (m & 0x6db6db6d);
}

/**
 * Calculate the Morton code of the bottom neighbor (x; y+1; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonyp3_64(uint64_t m)
{
    return ((m | 0xdb6db6db6db6db6d) + 1 & 0x2492492492492492) | (m & 0xdb6db6db6db6db6d);
}

/**
 * Calculate the Morton code of the left neighbor (x-1; y; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonxm3_8(uint8_t m)
{
    return ((m & 0x49) - 1 & 0x49) | (m & 0xb6);
}

/**
 * Calculate the Morton code of the left neighbor (x-1; y; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonxm3_16(uint16_t m)
{
    return ((m & 0x9249) - 1 & 0x9249) | (m & 0x6db6);
}

/**
 * Calculate the Morton code of the left neighbor (x-1; y; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonxm3_32(uint32_t m)
{
    return ((m & 0x49249249) - 1 & 0x49249249) | (m & 0xb6db6db6);
}

/**
 * Calculate the Morton code of the left neighbor (x-1; y; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonxm3_64(uint64_t m)
{
    return ((m & 0x9249249249249249) - 1 & 0x9249249249249249) | (m & 0x6db6db6db6db6db6);
}

/**
 * Calculate the Morton code of the right neighbor (x+1; y; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonxp3_8(uint8_t m)
{
    return ((m | 0xb6) + 1 & 0x49) | (m & 0xb6);
}

/**
 * Calculate the Morton code of the right neighbor (x+1; y; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonxp3_16(uint16_t m)
{
    return ((m | 0x6db6) + 1 & 0x9249) | (m & 0x6db6);
}

/**
 * Calculate the Morton code of the right neighbor (x+1; y; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonxp3_32(uint32_t m)
{
    return ((m | 0xb6db6db6) + 1 & 0x49249249) | (m & 0xb6db6db6);
}

/**
 * Calculate the Morton code of the right neighbor (x+1; y; z) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonxp3_64(uint64_t m)
{
    return ((m | 0x6db6db6db6db6db6) + 1 & 0x9249249249249249) | (m & 0x6db6db6db6db6db6);
}

/**
 * Calculate the Morton code of the right neighbor (x; y; z-1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonzm3_8(uint8_t m)
{
    return ((m & 0x24) - 1 & 0x24) | (m & 0xdb);
}

/**
 * Calculate the Morton code of the right neighbor (x; y; z-1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonzm3_16(uint16_t m)
{
    return ((m & 0x4924) - 1 & 0x4924) | (m & 0xb6db);
}

/**
 * Calculate the Morton code of the right neighbor (x; y; z-1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonzm3_32(uint32_t m)
{
    return ((m & 0x24924924) - 1 & 0x24924924) | (m & 0xdb6db6db);
}

/**
 * Calculate the Morton code of the right neighbor (x; y; z-1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonzm3_64(uint64_t m)
{
    return ((m & 0x4924924924924924) - 1 & 0x4924924924924924) | (m & 0xb6db6db6db6db6db);
}

/**
 * Calculate the Morton code of the right neighbor (x; y; z+1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint8_t mortonzp3_8(uint8_t m)
{
    return ((m | 0xdb) + 1 & 0x24) | (m & 0xdb);
}

/**
 * Calculate the Morton code of the right neighbor (x; y; z+1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint16_t mortonzp3_16(uint16_t m)
{
    return ((m | 0xb6db) + 1 & 0x4924) | (m & 0xb6db);
}

/**
 * Calculate the Morton code of the right neighbor (x; y; z+1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint32_t mortonzp3_32(uint32_t m)
{
    return ((m | 0xdb6db6db) + 1 & 0x24924924) | (m & 0xdb6db6db);
}

/**
 * Calculate the Morton code of the right neighbor (x; y; z+1) of m.
 *
 * Complexity: 4 bit ops, 1 add/subs
 */
static inline uint64_t mortonzp3_64(uint64_t m)
{
    return ((m | 0xb6db6db6db6db6db) + 1 & 0x4924924924924924) | (m & 0xb6db6db6db6db6db);
}


#endif //BITLIB_MORTON_H
