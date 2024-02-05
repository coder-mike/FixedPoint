#include "fixed_point.hpp"

#include <iostream>

#define PRINT_VAL(VAL) std::cout << #VAL << ":\t" << (VAL) << std::endl



void assignment_test(){
    // Something is wrong here
    FixedPoint<0, 1> aa = 1;
    PRINT_VAL(aa);
    FixedPoint<0, 5> aaa = 1;
    PRINT_VAL(aaa);
    // This uses 8 bits in this case, need to cast the number to the right type every time!
    FixedPoint<0, 0> aaaa = 127;
    PRINT_VAL(aaaa);
    FixedPoint<0, 0> aaaaa = 128;
    PRINT_VAL(aaaaa);
    FixedPoint<0, 2> bb = 1;
    PRINT_VAL(bb);
    FixedPoint<0, 2> cc = 2;
    PRINT_VAL(cc);
    FixedPoint<1, 1> a(1);
    std::cout << "a: " << a << std::endl;
    FixedPoint<2, 2> b(1);
    std::cout << "b: " << b << std::endl;
    FixedPoint<2, 2> c(2);
    std::cout << "c: " << c << std::endl;
    FixedPoint<2, 2> d(3);
    std::cout << "d: " << d << std::endl;
    FixedPoint<2, 2> e(4);
    std::cout << "e: " << e << std::endl;
    FixedPoint<2, 2> f(5);
    std::cout << "f: " << f << std::endl;
    FixedPoint<2, 2> g = 6;
    std::cout << "g: " << g << std::endl;
    FixedPoint<2, 2> h = 70;
    std::cout << "h: " << h << std::endl;
}


int main(){

    assignment_test();


}





