#include <iostream>
#include <fstream>

#include "fixed_point.hpp"
#include "bad.hpp"

OverflowMode OVERFLOW_MODE = OverflowMode::CLAMP;

#define CURR_TYPE FixedPoint<8, 8>

bool double_equals(double a, double b, double epsilon = 0.01){
    return std::abs(a - b) < epsilon;
}

int main(){
    // start reading tests.txt
    std::ifstream infile("tests.txt");
    std::ofstream outfile("results.txt");
    char optype;
    double num1, num2, num3;
    int n, m;
    while(infile >> optype){
        switch (optype){
            case '!':{
                infile >> n >> m;
                outfile << "Creating FixedPoint<" << n << ", " << m << ">" << std::endl;
                break;
            }
            case '#':{// Assignment test
                infile >> num1 >> num2;
                auto p1 = new CURR_TYPE;
                *p1 = num1;
                // now need to check if they are equal
                if(double_equals(p1->getValueF(), num2)){
                    outfile << "OK " << num1 << " == " << num2 << " " << p1->getValueF() << std::endl;
                } else {
                    outfile << "FAIL " << num1 << " != " << num2 << " " << p1->getValueF() << std::endl;
                }
                break;
            }
            case '+':{// Addition test
                infile >> num1 >> num2 >> num3;
                auto p1 = new CURR_TYPE;
                *p1 = num1;
                auto p2 = new CURR_TYPE;
                *p2 = num2;
                // now need to check if they are equal
                if(double_equals((*p1 + *p2).getValueF(), num3)){
                    outfile << "OK " << num1 << " + " << num2 << " == " << num3 << "==" << *p1 + *p2 << std::endl;
                } else {
                    outfile << "FAIL " << num1 << " + " << num2 << " == " << *p1 << " + " << *p2 << " == " << *p1+*p2 << " != " << num3  << std::endl;
                }
                break;
            }
            case '-':{// Subtraction test
                infile >> num1 >> num2 >> num3;
                auto p1 = new CURR_TYPE;
                *p1 = num1;
                auto p2 = new CURR_TYPE;
                *p2 = num2;
                // now need to check if they are equal
                if(double_equals((*p1 - *p2).getValueF(), num3)){
                    outfile << "OK " << num1 << " - " << num2 << " == " << num3 << "==" << *p1 - *p2 << std::endl;
                } else {
                    outfile << "FAIL " << num1 << " - " << num2 << " == " << *p1 << " - " << *p2 << " == " << *p1-*p2 << " != " << num3  << std::endl;
                }
                break;
            }
            case '*':{// Multiplication test
                infile >> num1 >> num2 >> num3;
                auto p1 = new CURR_TYPE;
                *p1 = num1;
                auto p2 = new CURR_TYPE;
                *p2 = num2;
                // now need to check if they are equal
                if(double_equals((*p1 * *p2).getValueF(), num3)){
                    outfile << "OK " << num1 << " * " << num2 << " == " << num3 << "==" << *p1 * *p2 << std::endl;
                } else {
                    outfile << "FAIL " << num1 << " * " << num2 << " == " << *p1 << " * " << *p2 << " == " << *p1 * *p2 << " != " << num3  << std::endl;
                }
                break;
            }
            case '/':{// Division test
                infile >> num1 >> num2 >> num3;
                auto p1 = new CURR_TYPE;
                *p1 = num1;
                auto p2 = new CURR_TYPE;
                *p2 = num2;
                // now need to check if they are equal
                if(double_equals((*p1 / *p2).getValueF(), num3)){
                    outfile << "OK " << num1 << " / " << num2 << " == " << num3 << "==" << *p1 / *p2 << std::endl;
                } else {
                    outfile << "FAIL " << num1 << " / " << num2 << " == " << *p1 << " / " << *p2 << " == " << *p1 / *p2 << " != " << num3  << std::endl;
                }
                break;
            }
            case '(':{//Unary minus test
                infile >> num1 >> num2;
                auto p1 = new CURR_TYPE;
                *p1 = num1;
                // now need to check if they are equal
                if(double_equals(-(*p1).getValueF(), num2)){
                    outfile << "OK -" << num1 << " == " << num2 << "==" << -(*p1) << std::endl;
                } else {
                    outfile << "FAIL -" << num1 << " == " << *p1 << " != " << num2  << std::endl;
                }
                break;
            }
            default:{
                std::cout << "Unknown optype: " << optype << std::endl;
                return 0;
            }
        }
    }
    
}
