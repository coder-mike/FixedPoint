#include "fixed_point.hpp"

// a function that will return the correct type for the FixedPoint
void* get_type(int n, int m){
    switch (n) {
        case 0:
            switch (m) {
                case 0:{return new FixedPoint<0, 0>;}
                case 1:{return new FixedPoint<0, 1>;}
                case 2:{return new FixedPoint<0, 2>;}
                case 3:{return new FixedPoint<0, 3>;}
                case 4:{return new FixedPoint<0, 4>;}
                case 5:{return new FixedPoint<0, 5>;}
                case 6:{return new FixedPoint<0, 6>;}
                case 7:{return new FixedPoint<0, 7>;}
                case 8:{return new FixedPoint<0, 8>;}
                case 9:{return new FixedPoint<0, 9>;}
                case 10:{return new FixedPoint<0, 10>;}
                case 11:{return new FixedPoint<0, 11>;}
                case 12:{return new FixedPoint<0, 12>;}
                case 13:{return new FixedPoint<0, 13>;}
                case 14:{return new FixedPoint<0, 14>;}
                case 15:{return new FixedPoint<0, 15>;}
                case 16:{return new FixedPoint<0, 16>;}
                default:
                    return nullptr;
            }
        case 1:
            switch (m) {
                case 0:
                    return new FixedPoint<1, 0>;
                case 1:
                    return new FixedPoint<1, 1>;
                case 2:
                    return new FixedPoint<1, 2>;
                case 3:
                    return new FixedPoint<1, 3>;
                case 4:
                    return new FixedPoint<1, 4>;
                case 5:
                    return new FixedPoint<1, 5>;
                case 6:
                    return new FixedPoint<1, 6>;
                case 7:
                    return new FixedPoint<1, 7>;
                case 8:
                    return new FixedPoint<1, 8>;
                case 9:
                    return new FixedPoint<1, 9>;
                case 10:
                    return new FixedPoint<1, 10>;
                case 11:
                    return new FixedPoint<1, 11>;
                case 12:
                    return new FixedPoint<1, 12>;
                case 13:
                    return new FixedPoint<1, 13>;
                case 14:
                    return new FixedPoint<1, 14>;
                case 15:
                    return new FixedPoint<1, 15>;
                case 16:
                    return new FixedPoint<1, 16>;
                default:
                    return nullptr;
            }
        case 2:
            switch (m) {
                case 0:
                    return new FixedPoint<2, 0>;
                case 1:
                    return new FixedPoint<2, 1>;
                case 2:
                    return new FixedPoint<2, 2>;
                case 3:
                    return new FixedPoint<2, 3>;
                case 4:
                    return new FixedPoint<2, 4>;
                case 5:
                    return new FixedPoint<2, 5>;
                case 6:
                    return new FixedPoint<2, 6>;
                case 7:
                    return new FixedPoint<2, 7>;
                case 8:
                    return new FixedPoint<2, 8>;
                case 9:
                    return new FixedPoint<2, 9>;
                case 10:
                    return new FixedPoint<2, 10>;
                case 11:
                    return new FixedPoint<2, 11>;
                case 12:
                    return new FixedPoint<2, 12>;
                case 13:
                    return new FixedPoint<2, 13>;
                case 14:
                    return new FixedPoint<2, 14>;
                case 15:
                    return new FixedPoint<2, 15>;
                case 16:
                    return new FixedPoint<2, 16>;
                default:
                    return nullptr;
            }
        case 3:
            switch (m) {
                case 0:
                    return new FixedPoint<3, 0>;
                case 1:
                    return new FixedPoint<3, 1>;
                case 2:
                    return new FixedPoint<3, 2>;
                case 3:
                    return new FixedPoint<3, 3>;
                case 4:
                    return new FixedPoint<3, 4>;
                case 5:
                    return new FixedPoint<3, 5>;
                case 6:
                    return new FixedPoint<3, 6>;
                case 7:
                    return new FixedPoint<3, 7>;
                case 8:
                    return new FixedPoint<3, 8>;
                case 9:
                    return new FixedPoint<3, 9>;
                case 10:
                    return new FixedPoint<3, 10>;
                case 11:
                    return new FixedPoint<3, 11>;
                case 12:
                    return new FixedPoint<3, 12>;
                case 13:
                    return new FixedPoint<3, 13>;
                case 14:
                    return new FixedPoint<3, 14>;
                case 15:
                    return new FixedPoint<3, 15>;
                case 16:
                    return new FixedPoint<3, 16>;
                default:
                    return nullptr;
            }
        case 4:
            switch (m) {
                case 0:
                    return new FixedPoint<4, 0>;
                case 1:
                    return new FixedPoint<4, 1>;
                case 2:
                    return new FixedPoint<4, 2>;
                case 3:
                    return new FixedPoint<4, 3>;
                case 4:
                    return new FixedPoint<4, 4>;
                case 5:
                    return new FixedPoint<4, 5>;
                case 6:
                    return new FixedPoint<4, 6>;
                case 7:
                    return new FixedPoint<4, 7>;
                case 8:
                    return new FixedPoint<4, 8>;
                case 9:
                    return new FixedPoint<4, 9>;
                case 10:
                    return new FixedPoint<4, 10>;
                case 11:
                    return new FixedPoint<4, 11>;
                case 12:
                    return new FixedPoint<4, 12>;
                case 13:
                    return new FixedPoint<4, 13>;
                case 14:
                    return new FixedPoint<4, 14>;
                case 15:
                    return new FixedPoint<4, 15>;
                case 16:
                    return new FixedPoint<4, 16>;
                default:
                    return nullptr;
            }
        case 5:
            switch (m) {
                case 0:
                    return new FixedPoint<5, 0>;
                case 1:
                    return new FixedPoint<5, 1>;
                case 2:
                    return new FixedPoint<5, 2>;
                case 3:
                    return new FixedPoint<5, 3>;
                case 4:
                    return new FixedPoint<5, 4>;
                case 5:
                    return new FixedPoint<5, 5>;
                case 6:
                    return new FixedPoint<5, 6>;
                case 7:
                    return new FixedPoint<5, 7>;
                case 8:
                    return new FixedPoint<5, 8>;
                case 9:
                    return new FixedPoint<5, 9>;
                case 10:
                    return new FixedPoint<5, 10>;
                case 11:
                    return new FixedPoint<5, 11>;
                case 12:
                    return new FixedPoint<5, 12>;
                case 13:
                    return new FixedPoint<5, 13>;
                case 14:
                    return new FixedPoint<5, 14>;
                case 15:
                    return new FixedPoint<5, 15>;
                case 16:
                    return new FixedPoint<5, 16>;
                default:
                    return nullptr;
            }
        case 6:
            switch (m) {
                case 0:
                    return new FixedPoint<6, 0>;
                case 1:
                    return new FixedPoint<6, 1>;
                case 2:
                    return new FixedPoint<6, 2>;
                case 3:
                    return new FixedPoint<6, 3>;
                case 4:
                    return new FixedPoint<6, 4>;
                case 5:
                    return new FixedPoint<6, 5>;
                case 6:
                    return new FixedPoint<6, 6>;
                case 7:
                    return new FixedPoint<6, 7>;
                case 8:
                    return new FixedPoint<6, 8>;
                case 9:
                    return new FixedPoint<6, 9>;
                case 10:
                    return new FixedPoint<6, 10>;
                case 11:
                    return new FixedPoint<6, 11>;
                case 12:
                    return new FixedPoint<6, 12>;
                case 13:
                    return new FixedPoint<6, 13>;
                case 14:
                    return new FixedPoint<6, 14>;
                case 15:
                    return new FixedPoint<6, 15>;
                case 16:
                    return new FixedPoint<6, 16>;
                default:
                    return nullptr;
            }
        case 7:
            switch (m) {
                case 0:
                    return new FixedPoint<7, 0>;
                case 1:
                    return new FixedPoint<7, 1>;
                case 2:
                    return new FixedPoint<7, 2>;
                case 3:
                    return new FixedPoint<7, 3>;
                case 4:
                    return new FixedPoint<7, 4>;
                case 5:
                    return new FixedPoint<7, 5>;
                case 6:
                    return new FixedPoint<7, 6>;
                case 7:
                    return new FixedPoint<7, 7>;
                case 8:
                    return new FixedPoint<7, 8>;
                case 9:
                    return new FixedPoint<7, 9>;
                case 10:
                    return new FixedPoint<7, 10>;
                case 11:
                    return new FixedPoint<7, 11>;
                case 12:
                    return new FixedPoint<7, 12>;
                case 13:
                    return new FixedPoint<7, 13>;
                case 14:
                    return new FixedPoint<7, 14>;
                case 15:
                    return new FixedPoint<7, 15>;
                case 16:
                    return new FixedPoint<7, 16>;
                default:
                    return nullptr;
            }
        case 8:
            switch (m) {
                case 0:
                    return new FixedPoint<8, 0>;
                case 1:
                    return new FixedPoint<8, 1>;
                case 2:
                    return new FixedPoint<8, 2>;
                case 3:
                    return new FixedPoint<8, 3>;
                case 4:
                    return new FixedPoint<8, 4>;
                case 5:
                    return new FixedPoint<8, 5>;
                case 6:
                    return new FixedPoint<8, 6>;
                case 7:
                    return new FixedPoint<8, 7>;
                case 8:
                    return new FixedPoint<8, 8>;
                case 9:
                    return new FixedPoint<8, 9>;
                case 10:
                    return new FixedPoint<8, 10>;
                case 11:
                    return new FixedPoint<8, 11>;
                case 12:
                    return new FixedPoint<8, 12>;
                case 13:
                    return new FixedPoint<8, 13>;
                case 14:
                    return new FixedPoint<8, 14>;
                case 15:
                    return new FixedPoint<8, 15>;
                case 16:
                    return new FixedPoint<8, 16>;
                default:
                    return nullptr;
            }
        case 9:
            switch (m) {
                case 0:
                    return new FixedPoint<9, 0>;
                case 1:
                    return new FixedPoint<9, 1>;
                case 2:
                    return new FixedPoint<9, 2>;
                case 3:
                    return new FixedPoint<9, 3>;
                case 4:
                    return new FixedPoint<9, 4>;
                case 5:
                    return new FixedPoint<9, 5>;
                case 6:
                    return new FixedPoint<9, 6>;
                case 7:
                    return new FixedPoint<9, 7>;
                case 8:
                    return new FixedPoint<9, 8>;
                case 9:
                    return new FixedPoint<9, 9>;
                case 10:
                    return new FixedPoint<9, 10>;
                case 11:
                    return new FixedPoint<9, 11>;
                case 12:
                    return new FixedPoint<9, 12>;
                case 13:
                    return new FixedPoint<9, 13>;
                case 14:
                    return new FixedPoint<9, 14>;
                case 15:
                    return new FixedPoint<9, 15>;
                case 16:
                    return new FixedPoint<9, 16>;
                default:
                    return nullptr;
            }
        case 10:
            switch (m) {
                case 0:
                    return new FixedPoint<10, 0>;
                case 1:
                    return new FixedPoint<10, 1>;
                case 2:
                    return new FixedPoint<10, 2>;
                case 3:
                    return new FixedPoint<10, 3>;
                case 4:
                    return new FixedPoint<10, 4>;
                case 5:
                    return new FixedPoint<10, 5>;
                case 6:
                    return new FixedPoint<10, 6>;
                case 7:
                    return new FixedPoint<10, 7>;
                case 8:
                    return new FixedPoint<10, 8>;
                case 9:
                    return new FixedPoint<10, 9>;
                case 10:
                    return new FixedPoint<10, 10>;
                case 11:
                    return new FixedPoint<10, 11>;
                case 12:
                    return new FixedPoint<10, 12>;
                case 13:
                    return new FixedPoint<10, 13>;
                case 14:
                    return new FixedPoint<10, 14>;
                case 15:
                    return new FixedPoint<10, 15>;
                case 16:
                    return new FixedPoint<10, 16>;
                default:
                    return nullptr;
            }
        case 11:
            switch (m) {
                case 0:
                    return new FixedPoint<11, 0>;
                case 1:
                    return new FixedPoint<11, 1>;
                case 2:
                    return new FixedPoint<11, 2>;
                case 3:
                    return new FixedPoint<11, 3>;
                case 4:
                    return new FixedPoint<11, 4>;
                case 5:
                    return new FixedPoint<11, 5>;
                case 6:
                    return new FixedPoint<11, 6>;
                case 7:
                    return new FixedPoint<11, 7>;
                case 8:
                    return new FixedPoint<11, 8>;
                case 9:
                    return new FixedPoint<11, 9>;
                case 10:
                    return new FixedPoint<11, 10>;
                case 11:
                    return new FixedPoint<11, 11>;
                case 12:
                    return new FixedPoint<11, 12>;
                case 13:
                    return new FixedPoint<11, 13>;
                case 14:
                    return new FixedPoint<11, 14>;
                case 15:
                    return new FixedPoint<11, 15>;
                case 16:
                    return new FixedPoint<11, 16>;
                default:
                    return nullptr;
            }
        case 12:
            switch (m) {
                case 0:
                    return new FixedPoint<12, 0>;
                case 1:
                    return new FixedPoint<12, 1>;
                case 2:
                    return new FixedPoint<12, 2>;
                case 3:
                    return new FixedPoint<12, 3>;
                case 4:
                    return new FixedPoint<12, 4>;
                case 5:
                    return new FixedPoint<12, 5>;
                case 6:
                    return new FixedPoint<12, 6>;
                case 7:
                    return new FixedPoint<12, 7>;
                case 8:
                    return new FixedPoint<12, 8>;
                case 9:
                    return new FixedPoint<12, 9>;
                case 10:
                    return new FixedPoint<12, 10>;
                case 11:
                    return new FixedPoint<12, 11>;
                case 12:
                    return new FixedPoint<12, 12>;
                case 13:
                    return new FixedPoint<12, 13>;
                case 14:
                    return new FixedPoint<12, 14>;
                case 15:
                    return new FixedPoint<12, 15>;
                case 16:
                    return new FixedPoint<12, 16>;
                default:
                    return nullptr;
            }
        case 13:
            switch (m) {
                case 0:
                    return new FixedPoint<13, 0>;
                case 1:
                    return new FixedPoint<13, 1>;
                case 2:
                    return new FixedPoint<13, 2>;
                case 3:
                    return new FixedPoint<13, 3>;
                case 4:
                    return new FixedPoint<13, 4>;
                case 5:
                    return new FixedPoint<13, 5>;
                case 6:
                    return new FixedPoint<13, 6>;
                case 7:
                    return new FixedPoint<13, 7>;
                case 8:
                    return new FixedPoint<13, 8>;
                case 9:
                    return new FixedPoint<13, 9>;
                case 10:
                    return new FixedPoint<13, 10>;
                case 11:
                    return new FixedPoint<13, 11>;
                case 12:
                    return new FixedPoint<13, 12>;
                case 13:
                    return new FixedPoint<13, 13>;
                case 14:
                    return new FixedPoint<13, 14>;
                case 15:
                    return new FixedPoint<13, 15>;
                case 16:
                    return new FixedPoint<13, 16>;
                default:
                    return nullptr;
            }
        case 14:
            switch (m) {
                case 0:
                    return new FixedPoint<14, 0>;
                case 1:
                    return new FixedPoint<14, 1>;
                case 2:
                    return new FixedPoint<14, 2>;
                case 3:
                    return new FixedPoint<14, 3>;
                case 4:
                    return new FixedPoint<14, 4>;
                case 5:
                    return new FixedPoint<14, 5>;
                case 6:
                    return new FixedPoint<14, 6>;
                case 7:
                    return new FixedPoint<14, 7>;
                case 8:
                    return new FixedPoint<14, 8>;
                case 9:
                    return new FixedPoint<14, 9>;
                case 10:
                    return new FixedPoint<14, 10>;
                case 11:
                    return new FixedPoint<14, 11>;
                case 12:
                    return new FixedPoint<14, 12>;
                case 13:
                    return new FixedPoint<14, 13>;
                case 14:
                    return new FixedPoint<14, 14>;
                case 15:
                    return new FixedPoint<14, 15>;
                case 16:
                    return new FixedPoint<14, 16>;
                default:
                    return nullptr;
            }
        case 15:
            switch (m) {
                case 0:
                    return new FixedPoint<15, 0>;
                case 1:
                    return new FixedPoint<15, 1>;
                case 2:
                    return new FixedPoint<15, 2>;
                case 3:
                    return new FixedPoint<15, 3>;
                case 4:
                    return new FixedPoint<15, 4>;
                case 5:
                    return new FixedPoint<15, 5>;
                case 6:
                    return new FixedPoint<15, 6>;
                case 7:
                    return new FixedPoint<15, 7>;
                case 8:
                    return new FixedPoint<15, 8>;
                case 9:
                    return new FixedPoint<15, 9>;
                case 10:
                    return new FixedPoint<15, 10>;
                case 11:
                    return new FixedPoint<15, 11>;
                case 12:
                    return new FixedPoint<15, 12>;
                case 13:
                    return new FixedPoint<15, 13>;
                case 14:
                    return new FixedPoint<15, 14>;
                case 15:
                    return new FixedPoint<15, 15>;
                case 16:
                    return new FixedPoint<15, 16>;
                default:
                    return nullptr;
            }
        case 16:
            switch (m) {
                case 0:
                    return new FixedPoint<16, 0>;
                case 1:
                    return new FixedPoint<16, 1>;
                case 2:
                    return new FixedPoint<16, 2>;
                case 3:
                    return new FixedPoint<16, 3>;
                case 4:
                    return new FixedPoint<16, 4>;
                case 5:
                    return new FixedPoint<16, 5>;
                case 6:
                    return new FixedPoint<16, 6>;
                case 7:
                    return new FixedPoint<16, 7>;
                case 8:
                    return new FixedPoint<16, 8>;
                case 9:
                    return new FixedPoint<16, 9>;
                case 10:
                    return new FixedPoint<16, 10>;
                case 11:
                    return new FixedPoint<16, 11>;
                case 12:
                    return new FixedPoint<16, 12>;
                case 13:
                    return new FixedPoint<16, 13>;
                case 14:
                    return new FixedPoint<16, 14>;
                case 15:
                    return new FixedPoint<16, 15>;
                case 16:
                    return new FixedPoint<16, 16>;
                default:
                    return nullptr;
            }
        default:
            return nullptr;
    }
}