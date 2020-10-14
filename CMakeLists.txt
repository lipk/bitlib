cmake_minimum_required(VERSION 3.17)
project(bitlib C)

set(CMAKE_C_STANDARD 99)

set(LIBSRC src/shift.h src/popcount.h)
set(TESTSRC tests/main.c tests/common.h tests/shift.c tests/popcount.c tests/popcount.c)

add_executable(bitlib_test ${TESTSRC} ${LIBSRC})
target_include_directories(bitlib_test PUBLIC src)