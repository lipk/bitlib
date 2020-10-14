/**
 * Tools for working with Morton codes (aka Z-order curve indices) both in 2D
 * and 3D. Many algorithms in this file simply refer to identical operations in
 * shift.h.
 *
 * Function families in this file:
 * morton, morton3: calculate a 2D or 3D Morton code (same as merge/merge3)
 * invmorton, invmorton3: invert a 2D or 3D Morton code (same as separate/separate3)
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

#endif //BITLIB_MORTON_H
