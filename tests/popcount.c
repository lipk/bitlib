#include "common.h"
#include "popcount.h"
#include <assert.h>

void test_popcount_8()
{
    assert(popcount_8(0x53) == 4);
    assert(popcount_8(0x00) == 0);
    assert(popcount_8(0xff) == 8);
    assert(popcount_8(0x0f) == 4);
    assert(popcount_8(0x7a) == 5);
}

void test_popcount_16()
{
    assert(popcount_16(0x9053) == 6);
    assert(popcount_16(0x0000) == 0);
    assert(popcount_16(0xffff) == 16);
    assert(popcount_16(0x00ff) == 8);
    assert(popcount_16(0x557a) == 9);
}

void test_popcount_32()
{
    assert(popcount_32(0x90539053) == 12);
    assert(popcount_32(0x00000000) == 0);
    assert(popcount_32(0xffffffff) == 32);
    assert(popcount_32(0x0000ffff) == 16);
    assert(popcount_32(0x1000557a) == 10);

    assert(popcount_mul_32(0x90539053) == 12);
    assert(popcount_mul_32(0x00000000) == 0);
    assert(popcount_mul_32(0xffffffff) == 32);
    assert(popcount_mul_32(0x0000ffff) == 16);
    assert(popcount_mul_32(0x1000557a) == 10);

    assert(popcount_iter_32(0x90539053) == 12);
    assert(popcount_iter_32(0x00000000) == 0);
    assert(popcount_iter_32(0xffffffff) == 32);
    assert(popcount_iter_32(0x0000ffff) == 16);
    assert(popcount_iter_32(0x1000557a) == 10);
}

void test_popcount_64()
{
    assert(popcount_64(0x9053905390539053) == 24);
    assert(popcount_64(0x0000000000000000) == 0);
    assert(popcount_64(0xffffffffffffffff) == 64);
    assert(popcount_64(0x00000000ffffffff) == 32);
    assert(popcount_64(0x300005001000557a) == 14);

    assert(popcount_mul_64(0x9053905390539053) == 24);
    assert(popcount_mul_64(0x0000000000000000) == 0);
    assert(popcount_mul_64(0xffffffffffffffff) == 64);
    assert(popcount_mul_64(0x00000000ffffffff) == 32);
    assert(popcount_mul_64(0x300005001000557a) == 14);

    assert(popcount_iter_64(0x9053905390539053) == 24);
    assert(popcount_iter_64(0x0000000000000000) == 0);
    assert(popcount_iter_64(0xffffffffffffffff) == 64);
    assert(popcount_iter_64(0x00000000ffffffff) == 32);
    assert(popcount_iter_64(0x300005001000557a) == 14);
}

void test_popcount()
{
    test_popcount_8();
    test_popcount_16();
    test_popcount_32();
    test_popcount_64();
}