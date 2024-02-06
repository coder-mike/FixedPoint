#include <iostream>
#include <fstream>

#include "fixed_point.hpp"
#include "bad.hpp"



int main(){
    // start reading tests.txt
    std::ifstream infile("tests.txt");
    std::ofstream outfile("results.txt");
    char optype;
    double num1, num2;
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
                auto p1 = (FixedPoint<1,1>*)get_type(n, m);
                *p1 = num1;
                // now need to check if they are equal
                if(*p1 == num2){
                    outfile << "OK " << num1 << " == " << num2 << " " << *p1 << std::endl;
                } else {
                    outfile << "FAIL " << num1 << " != " << num2 << " " << *p1 << std::endl;
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
