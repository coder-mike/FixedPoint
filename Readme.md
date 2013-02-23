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

In addition there is the 3rd file, `examples.cpp` which contains a `main()` that illustrates the use of the library.

