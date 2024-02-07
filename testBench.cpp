#include "fixed_point.hpp"
#include <iostream>
#include <cmath>
#include <stdlib.h>

// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest/doctest/doctest.h"

#define PRINT_VAL(VAL) std::cout << #VAL << ":\t" << (VAL) << std::endl
#define UNCERTAINTY 0.15

// global variables to set bit width
const unsigned int ARRAY[10] = {0,1,2,3,4,5,6,7,8,9};
short unsigned const decimal = ARRAY[5], fractional=6;

enum Operations {
    ADD,
    SUB,
    MUL,
    DIV,
    MOD
};


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

FixedPoint<decimal, fractional> simpleMod (FixedPoint<decimal, fractional> in1, int in2){
    
    FixedPoint<decimal, fractional> output = (int)in1 % (int)in2; 
    return output;
}



void overflowDetection(double* x1, double* x2, Operations op){
    switch(op){
        case ADD:
            if(*x1+*x2 >= pow(2,(decimal-1))){
                std::cout<< "Overflow detected\n";
            }
            break;
        case SUB:
            if(*x1-*x2 >= pow(2,(decimal-1)) || *x1-*x2 <= -1*(pow(2,(decimal-1))+1)){
                std::cout<< "Overflow detected\n";
            }
            break;
        case MUL:
            if((*x1)*(*x2) >= pow(2,(decimal-1)) || (*x1)*(*x2) <= -1*(pow(2,(decimal-1))+1)){
                std::cout<< "Overflow detected\n";
            }
            break;
        case DIV:
            if((*x1)/(*x2) >= pow(2,(decimal-1)) || (*x1)/(*x2) <= -1*(pow(2,(decimal-1))+1)){
                std::cout<< "Overflow detected\n";
            }
            break;
        case MOD:
            if(((int)*x1%(int)*x2) >= pow(2,(decimal-1)) || ((int)*x1%(int)*x2) <= -1*(pow(2,(decimal-1))+1)){
                std::cout<< "Overflow detected\n";
            }
            break;
    }
}

void edgeCases(double* x1, double* x2, Operations op){
    switch(op){
        case ADD:
            *x1 = 0.75;
            *x2 = 1.1;
            std::cout<< *x1 << " + " << *x2 << std::endl;
            break;
        case SUB:
            *x1 = 0.75;
            *x2 = 1.1;
            std::cout<< *x1 << " - " << *x2 << std::endl;
            break;
        case MUL:
            *x1 = 0.75;
            *x2 = 1.1;
            std::cout<< *x1 << " * " << *x2 << std::endl;
            break;
        case DIV:
            *x1 = 0.75;
            *x2 = 1.1;
            std::cout<< *x1 << " / " << *x2 << std::endl;
            break;
        case MOD:
            *x1 = 5;
            *x2 = (int)3;
            std::cout<< *x1 << " % " << *x2 << std::endl;
            break;
    }
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




int main(const int argc, const char* argv[]){

    // initialize variables
    double in1, in2;

    // simple addition test
    std::cout<< "TESTING ADDITION\n";
    edgeCases(&in1, &in2, ADD);
    FixedPoint<decimal, fractional> a(in1);
    FixedPoint<decimal, fractional> b(in2);
    overflowDetection(&in1, &in2, ADD);
    printSuccess(simpleAdd(a,b), (double)in1+in2);


    // simple subtraction test
    std::cout<< "\nTESTING SUBTRACTION\n";
    edgeCases(&in1, &in2, SUB);
    a = FixedPoint<decimal, fractional>(in1);
    b = FixedPoint<decimal, fractional>(in2);
    overflowDetection(&in1, &in2, SUB);
    printSuccess(simpleAdd(a,b), (double)in1+in2);



    // simple multiplication test   
    std::cout<< "\nTESTING MULTIPLICATION\n";
    edgeCases(&in1, &in2, MUL); 
    a = FixedPoint<decimal, fractional>(in1);
    b = FixedPoint<decimal, fractional>(in2);
    overflowDetection(&in1, &in2, MUL);
    printSuccess(simpleMul(a,b), (double)in1+in2);




    // simple division test
    std::cout<< "\nTESTING DIVISION\n";
    edgeCases(&in1, &in2, DIV);    
    a = FixedPoint<decimal, fractional>(in1);
    b = FixedPoint<decimal, fractional>(in2); 
    overflowDetection(&in1, &in2, DIV);
    printSuccess(simpleDiv(a,b), (double)in1/in2);



    // simple modulo test
    std::cout<< "\nTESTING MODULUS\n";
    edgeCases(&in1, &in2, MOD);
    a = FixedPoint<decimal, fractional>(in1);
    b = FixedPoint<decimal, fractional>(in2);
    overflowDetection(&in1, &in2, MOD);
    printSuccess(simpleMod(a,b), (int)in1%(int)in2);


    return 0;
}


