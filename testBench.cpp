#include "fixed_point.hpp"
#include <iostream>
#include <cmath>
#include <stdlib.h>

// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest/doctest/doctest.h"

#define PRINT_VAL(VAL) std::cout << #VAL << ":\t" << (VAL) << std::endl
#define UNCERTAINTY 0.15

// global variables to set bit width
short int const decimal = 4, fractional=6;


FixedPoint<decimal, fractional> simpleAdd (FixedPoint<decimal, fractional> in1, FixedPoint<decimal, fractional> in2){
    
    FixedPoint<decimal, fractional> output = in1 + in2; 
    return output;
}

FixedPoint<decimal, fractional> simpleSub (FixedPoint<decimal, fractional> in1, FixedPoint<decimal, fractional> in2){
    
    FixedPoint<decimal, fractional> output = in1 - in2; 
    return output;
}

FixedPoint<decimal, fractional> simpleMul (FixedPoint<decimal, fractional> in1, FixedPoint<decimal, fractional> in2){
    
    FixedPoint<decimal, fractional> output = in1 * in2; 
    return output;
}

FixedPoint<decimal, fractional> simpleDiv (FixedPoint<decimal, fractional> in1, FixedPoint<decimal, fractional> in2){
    
    FixedPoint<decimal, fractional> output = in1 / in2; 
    return output;
}

FixedPoint<decimal, fractional> simpleMod (FixedPoint<decimal, fractional> in1, FixedPoint<decimal, fractional> in2){
    
    FixedPoint<decimal, fractional> output = (int)in1 % (int)in2; 
    return output;
}


void printSuccess(FixedPoint<decimal, fractional> fxPoint, double dbl){
    
    double dblTemp = dbl;
    double fxTemp = (double)fxPoint;
    if(dbl < 0){
        dblTemp = -1*dbl;
    }

    if(fxTemp < 0){
        fxTemp = -1*fxTemp;
    }

    double upper = dblTemp * (1+UNCERTAINTY);
    double lower = dblTemp * (1-UNCERTAINTY);

    std::cout<< "Fixed Point: " << fxPoint <<"\tDouble: "
     <<dbl<<std::endl;

    if(fxTemp > upper || fxTemp < lower){
        std::cout << "\033[1;31mFAILURE\033[0m\n";
    }
    else{
        std::cout << "\033[1;32mSUCCESS\033[0m\n";
    }
}


int main(){

    // simple addition test
    double in1 = 0.75, in2 = 1.1;
    std::cout<< "TESTING ADDITION\n\n";
    FixedPoint<decimal, fractional> a(in1);
    FixedPoint<decimal, fractional> b(in2);
    
    if(in1+in2 >= pow(2,(decimal-1))){
        std::cout<< "Overflow detected\n";
    }

    printSuccess(simpleAdd(a,b), (double)in1+in2);


    // simple subtraction test
    in1 = 0.75, in2 = -1.0;
    a = FixedPoint<decimal, fractional>(in1);
    b = FixedPoint<decimal, fractional>(in2);

    std::cout<< "\nTESTING SUBTRACTION\n\n";
    if(in1-in2 >= pow(2,(decimal-1)) || in1-in2 <= -1*(pow(2,(decimal-1))+1)){
        std::cout<< "Overflow detected\n";
    }

    printSuccess(simpleAdd(a,b), (double)in1+in2);



    // simple multiplication test
    in1 = 2, in2 = 2;
    
    a = FixedPoint<decimal, fractional>(in1);
    b = FixedPoint<decimal, fractional>(in2);

    std::cout<< "\nTESTING MULTIPLICATION\n\n";
    
    if((in1*in2) >= pow(2,(decimal-1)) || (in1*in2) <= -1*(pow(2,(decimal-1))+1)){
        std::cout<< "Overflow detected\n";
    }
    printSuccess(simpleMul(a,b), (double)in1+in2);




    // simple division test
    in1 = -2.5, in2 = 2.5;
    
    a = FixedPoint<decimal, fractional>(in1);
    b = FixedPoint<decimal, fractional>(in2);

    std::cout<< "\nTESTING DIVISION\n\n";
    
    if((in1*in2) >= pow(2,(decimal-1)) || (in1*in2) <= -1*(pow(2,(decimal-1))+1)){
        std::cout<< "Overflow detected\n";
    }
    printSuccess(simpleDiv(a,b), (double)in1/in2);



    // simple modulo test
    in1 = 13, in2 = 2;
    
    a = FixedPoint<decimal, fractional>(in1);
    b = FixedPoint<decimal, fractional>(in2);

    std::cout<< "\nTESTING MODULUS\n\n";
    
    if((in1*in2) >= pow(2,(decimal-1)) || (in1*in2) <= -1*(pow(2,(decimal-1))+1)){
        std::cout<< "Overflow detected\n";
    }
    printSuccess(simpleMod(a,b), (int)in1%(int)in2);



    
    return 0;
}


