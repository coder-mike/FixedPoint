#include <iostream>


#include <FixedPoint/fixed_point.hpp>
#include <Eigen/Core>


typedef FixedPoint<8, 8> exp_type;

int main(){
    Eigen::Matrix<exp_type, 3, 3> A;
    Eigen::Matrix<exp_type, 3, 3> B;
    Eigen::Matrix<exp_type, 3, 3> C;
    A << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    B << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    C = A*B;
    std::cout <<"A = \n" << A << std::endl;
    std::cout <<"B = \n" << B << std::endl;
    std::cout <<"C = \n" << C << std::endl;
    return 0;
}





