Fixed Point Library
===================

This is a simple library, in the form of 2 hpp files, that gives a program fixed-point functionality. It is designed with the intention of being used in an embedded environment where there is no floating point unit and so fixed-point operations are much more efficient. The best way to get to know the library is by reading `examples.hpp`.

Overview
--------

The problem with fixed point operations is that the programmer typically needs to keep track of what part of an integer is fractional and what part is integer. For example if you are using Q4.12 format (4 bits before the radix point, and 12 bits after the radix point), you have to remember that a conceptual value of "1" is actually stored as "4096". When performing operations between fixed point numbers, its important to keep track of things so you don't combine things in illogical ways.

The fixed-point library fixes this problem by introducing the `FixedPoint<m,f>` type, which stores a number in [Qm.f format](http://en.wikipedia.org/wiki/Fixed-point_arithmetic#Notation). Using the type introduces no runtime overhead because the position of the radix point is only associated with the number at compile time. Using the type has a few benefits:

- The compiler will catch common mistakes where you intended a number to be of a particular format but in fact it isnt
- The type will perform some conversions automatically, for example in adding or comparing numbers of different Q formats.
- The intentions for a particular type are clearly stated. If a function just returns `int16_t` it's not immediately obvious what format it's in, but if it returns `FixedPoint<4,12>` it's unambiguous (both to the user of the function and to the compiler).
- Its more robust to change: if you decide you need more range or resolution for a particular variable, you can safely change it and the compiler will help you find other places where variables need to change format.

Library Contents
----------------

The library consists of 2 files:

	- `fixed_point.hpp` (the primary file to #include)
	- `template_utils.hpp` (some stuff that fixed_point.hpp needs)

In addition there is the 3rd file, `examples.cpp` which contains a `main()` that illustrates the use of the library:

```C++
int main()
{
    // A fixed-point number in Q4.4 signed format (its always signed), with value "5"
    FixedPoint<4,4> a = 5;

    PRINT_VAL(a); // 5.00

    // Move radix point left 1 bit (right shift by 1 bit)
    FixedPoint<3,5> b = a.rightShift<1>();

    PRINT_VAL(b); // 2.50

    // Multiplication (integer and fraction lengths are added together)
    FixedPoint<7,9> c = a * b;

    PRINT_VAL(c); // 12.500

    // Addition (the integer and fraction lengths are the maximum from each operand)
    FixedPoint<4,5> d = a + b;

    PRINT_VAL(d); // 7.500

    // Retrieve value as integer
    int di = d.getValue();
    int di2 = d.round();

    PRINT_VAL(di); // 7
    PRINT_VAL(di2); // 8

    // Convert Q3.5 to Q3.1 (any bit length is ok as long as less than 64 total)
    FixedPoint<3,1> e = a.convert<3,1>();

    PRINT_VAL(e); // 5.0

    // Extend the integer part of the fixed-point number to 12 bits
    FixedPoint<12,5> f = b.extend<12>();

    PRINT_VAL(f); // 2.50

    // Initialize a fixed-point with from given binary data
    FixedPoint<2,6> g = FixedPoint<2,6>::createRaw(0xA0);

    PRINT_VAL(g); // -1.5

    // Fixed-point division
    // Note that dividing Qa.b by Qc.d results in Q(a+d).(b+c)
    // This is symmetrical to multiplication result: Q(a+c).(b+d)
    // To see why this makes sense, look in edgeCases().
    FixedPoint<9,7> h = a / b; // 5.0/2.5 = 2.0
    FixedPoint<7,9> j = b / a; // 2.5/5.0 = 0.5
    FixedPoint<4,7> k = a / FixedPoint<3,0>(3); // 5.0/3.0 = 1.6640625

    PRINT_VAL(h); // 2.000
    PRINT_VAL(j); // 0.500
    PRINT_VAL(k); // 1.664


    // See-also, some edge cases
    edgeCases();

    // See-also, some more operators that can be used
    otherOperators();
}
```