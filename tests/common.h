#ifndef BITLIB_COMMON_H
#define BITLIB_COMMON_H

#include <stdio.h>
#include <assert.h>

void test_shift();
void test_popcount();
void test_morton();

#define PRINT_UINT(x) printf("%x\n", (uint32_t)(x))

#endif //BITLIB_COMMON_H
