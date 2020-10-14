#include "shift.h"
#include "common.h"

#include <assert.h>

void test_scatter()
{
    assert(scatter_8(0x0f) == 0x55);
    assert(scatter_16(0x00ff) == 0x5555);
    assert(scatter_32(0x0000ffff) == 0x55555555);
    assert(scatter_64(0x00000000ffffffff) == 0x5555555555555555);
}

void test_gather()
{
    assert(gather_8(0x55) == 0x0f);
    assert(gather_16(0x5555) == 0x00ff);
    assert(gather_32(0x55555555) == 0x0000ffff);
    assert(gather_64(0x5555555555555555) == 0x00000000ffffffff);
}

void test_merge()
{
    assert(merge_8(0x05, 0x0a) == 0x99);
    assert(merge_nwe_8(0x05, 0x0a) == 0x99);
    assert(merge_16(0x0055, 0x00aa) == 0x9999);
    assert(merge_nwe_16(0x0055, 0x00aa) == 0x9999);
    assert(merge_32(0x00005555, 0x0000aaaa) == 0x99999999);
    assert(merge_nwe_32(0x00005555, 0x0000aaaaa) == 0x99999999);
    assert(merge_64(0x0000000055555555, 0x00000000aaaaaaaa) == 0x9999999999999999);
}

void test_separate()
{
    {
        uint8_t x, y;
        separate_8(0x99, &x, &y);
        assert(x == 0x05);
        assert(y == 0x0a);
    }
    {
        uint8_t x, y;
        separate_nwe_8(0x99, &x, &y);
        assert(x == 0x05);
        assert(y == 0x0a);
    }
    {
        uint16_t x, y;
        separate_16(0x9999, &x, &y);
        assert(x == 0x0055);
        assert(y == 0x00aa);
    }
    {
        uint16_t x, y;
        separate_nwe_16(0x9999, &x, &y);
        assert(x == 0x0055);
        assert(y == 0x00aa);
    }
    {
        uint32_t x, y;
        separate_32(0x99999999, &x, &y);
        assert(x == 0x00005555);
        assert(y == 0x0000aaaa);
    }
    {
        uint32_t x, y;
        separate_nwe_32(0x99999999, &x, &y);
        assert(x == 0x00005555);
        assert(y == 0x0000aaaa);
    }
    {
        uint64_t x, y;
        separate_64(0x9999999999999999, &x, &y);
        assert(x == 0x0000000055555555);
        assert(y == 0x00000000aaaaaaaa);
    }
}

void scatter3_test()
{
    assert(scatter3_8(0x07) == 0x49);
    assert(scatter3_16(0x003f) == 0x9249);
    assert(scatter3_32(0x000007ff) == 0x49249249);
    assert(scatter3_64(0x00000000003fffff) == 0x9249249249249249);
}

void gather3_test()
{
    assert(gather3_8(0x49) == 0x07);
    assert(gather3_16(0x9249) == 0x003f);
    assert(gather3_32(0x49249249) == 0x000007ff);
    assert(gather3_64(0x9249249249249249) == 0x00000000003fffff);
}

void merge3_test()
{
    assert(merge3_8(0x05, 0x05, 0x01) == 0xc7);
    assert(merge3_16(0x0015, 0x0015, 0x0015) == 0x71c7);
    assert(merge3_32(0x00000555, 0x00000555, 0x00000155) == 0xc71c71c7);
    assert(merge3_64(0x0000000000155555, 0x0000000000155555, 0x0000000000155555) == 0x71c71c71c71c71c7);
}

void separate3_test()
{
    {
        uint8_t x, y, z;
        separate3_8(0xc7, &x, &y, &z);
        assert(x == 0x05);
        assert(y == 0x05);
        assert(z == 0x01);
    }
    {
        uint16_t x, y, z;
        separate3_16(0x71c7, &x, &y, &z);
        assert(x == 0x0015);
        assert(y == 0x0015);
        assert(z == 0x0015);
    }
    {
        uint32_t x, y, z;
        separate3_32(0xc71c71c7, &x, &y, &z);
        assert(x == 0x00000555);
        assert(y == 0x00000555);
        assert(z == 0x00000155);
    }
    {
        uint64_t x, y, z;
        separate3_64(0x71c71c71c71c71c7, &x, &y, &z);
        assert(x == 0x0000000000155555);
        assert(y == 0x0000000000155555);
        assert(z == 0x0000000000155555);
    }
}

void test_shift()
{
    test_scatter();
    test_gather();
    test_merge();
    test_separate();
    scatter3_test();
    gather3_test();
    merge3_test();
    separate3_test();
}