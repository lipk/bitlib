# Introduction

Bitlib is a collection of useful algorithms that utilize low-level arithmetic
and bit operation trickery to achieve better performance than naive solutions to
the same problems. Most of these algorithms are well-known and many sources
listing and explaining them can be found online. The goal of Bitlib is to
provide ready-to-go implementations adapted to various bit sizes that can be
integrated into your code with minimal effort.

# Design

## Principles of implementation 

Bitlib is implemented as a header-only C library. All code conforms to the C99
standard and is (hopefully) platform-independent. Interdependencies between
functions are kept to a minimum to enable easy copy-pasting of the code. Note
that while the algorithms included in Bitlib are considered highly efficient,
they are still constrained by the toolset of the C language. Using
platform-specific assembly or compiler intrinsics might yield better results in
many cases (for example, some architectures support single-instruction
population count).

## Naming convention

Typically, there will be more than one function provided for each task. The
variations might differ in the width of parameters, register sizes and types of
instructions used internally. The naming scheme is: OP(_FLAVORS)_WIDTH where OP
is the name of the operation, FLAVORS is an optional sequence of discriminators
describing the features of the implementation and WIDTH is the size of the
operands. For example, `popcount_mul_32` stands for "population count of 32 bit
operands, involving an integer multiplication". Most functions have a default
variation without any "flavors". There are no strict reasoning behind the
default picks, they are simply the ones that I deemed to be likely the best for
most use cases.

An important variation that many functions have is the "nwe" (no width
expansion) flavor. nwe functions are guaranteed not to use internal variables
that are larger than its operands. 64 bit functions are always implicitly nwe.

## Operation count

The total number of operations is included for each function. Note that this
counts the operations of the C code, there is no guarantee that the generated
machine code will have a matching number of instructions.

The total count is broken down into several categories:

* *bit ops* - bitwise logical operations (&, ^, etc)
* *add/subs* - integer addition and subtraction
* *multiply* - integer multiplication
* *compare* - integer comparisons (==, <, etc)
* *branch* - branch points, including `if`s and loop condition checks

Variable assignments are assumed to be performed as a side effect of arithmetic
operations and aren't counted separately.

## Included algorithms

### popcount.h

* `popcount` - Hamming weight of a bit string

### shift.h

* `scatter`, `scatter3` - spread out a continuous sequence of bits
* `gather`, `gather3` - collect a scattered set of bits into a continuous sequence
* `merge`, `merge3` - interleave 2 or 3 of sequences respectively
* `separate`, `separate3` - deinterleave a sequence into 2 or 3 components

### morton.h

* `morton` - calculate a 2D Morton code (same as merge)
* `morton3` - calculate a 3D Morton code (same as merge3)
* `invmorton` - invert a 2D Morton code (same as separate)
* `invmorton3` - invert a 3D Morton code (same as separate3)
* `mortonxm`, `morton3xm` - Morton code of left (x-1) neighbor
* `mortonxp`, `morton3xp` - Morton code of right (x+1) neighbor
* `mortonym`, `morton3ym` - Morton code of top (y-1) neighbor
* `mortonyp`, `morton3yp` - Morton code of bottom (y+1) neighbor
* `morton3zm` - Morton code of back (z-1) neighbor
* `morton3zp` - Morton code of back (z+1) neighbor