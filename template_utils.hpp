#ifndef TEMPLATE_UTILS_H__
#define TEMPLATE_UTILS_H__

#include <stdint.h>

// This is a dummy type meaning that there are too many bits in the data type
struct TooManyBits;

// template <int X>
// struct ROUND_UP_INT_SIZE
// {
//     static int RESULT = ROUND_UP_INT_SIZE<X+1;
// };


/// RETURNS a signed integer type that has at least as many bits as the value of BITS
template <int BITS>
struct GET_INT_WITH_LENGTH
{
    // The default is that an integer with N bits can be represented
    // by an integer with N+1 bits
    typedef typename GET_INT_WITH_LENGTH<BITS+1>::RESULT RESULT;
};

template <>
struct GET_INT_WITH_LENGTH<8>
{
    typedef int8_t RESULT;
};

template <>
struct GET_INT_WITH_LENGTH<16>
{
    typedef int16_t RESULT;
};

template <>
struct GET_INT_WITH_LENGTH<32>
{
    typedef int32_t RESULT;
};

template <>
struct GET_INT_WITH_LENGTH<64>
{
    typedef int64_t RESULT;
};

template <>
struct GET_INT_WITH_LENGTH<128>
{
    typedef TooManyBits RESULT;
};

/// Returns X1 if isX1 is true, else return X2
template <int X1, int X2, bool isX1>
struct PICK_ONE
{
    static const int RESULT; // Undefined
};

/// Returns X1 if (X1 > X2) else returns X2
template <int X1, int X2>
struct GET_MAX
{
    static const int RESULT = PICK_ONE<X1, X2, (X1 > X2)>::RESULT;
};

template <int X1, int X2>
struct PICK_ONE<X1, X2, true>
{
    static const int RESULT = X1;
};

template <int X1, int X2>
struct PICK_ONE<X1, X2, false>
{
    static const int RESULT = X2;
};

template <typename T, int AMOUNT, bool left>
struct SHIFT_IN_DIRECTION
{
    T exec(T value);
};

template <typename T, int AMOUNT>
struct SHIFT_IN_DIRECTION<T, AMOUNT, true>
{
    T exec(T value) { return value << AMOUNT; }
};

template <typename T, int AMOUNT>
struct SHIFT_IN_DIRECTION<T, AMOUNT, false>
{
    T exec(T value) { return value >> (-AMOUNT); }
};


// Shifts a value by a constant amount. Positive = left, negative = right
template <typename T, int AMOUNT>
struct SHIFT
{
    T exec(T value)
    {
        return SHIFT_IN_DIRECTION<T, AMOUNT, (AMOUNT < 0)>::exec(value);
    }
};

template <typename TSRC, typename TDEST, int SHL_AMT, bool IS_LEFT>
struct CONVERT_FIXED_POINT
{
    static TDEST exec(TSRC src);
};

// Convert fixed point by shifting the value left
template <typename TSRC, typename TDEST, int SHL_AMT>
struct CONVERT_FIXED_POINT<TSRC, TDEST, SHL_AMT, true>
{
    static TDEST exec(TSRC src)
    {
        // Because we're left shifting, we need to change the target type before
        // shifting. If the target type gets smaller, we havent lost anything
        // more by changing type first, but if the target type gets bigger then
        // we need the bigger type to ensure all the data is preserved in the 
        // shift
        TDEST intermediate = src;
        intermediate <<= SHL_AMT;
        return intermediate;        
    }
};

// Convert fixed point by shifting the value right
template <typename TSRC, typename TDEST, int SHL_AMT>
struct CONVERT_FIXED_POINT<TSRC, TDEST, SHL_AMT, false>
{
    static TDEST exec(TSRC src)
    {
        // Because we're right shifting, we need to shift before we change the
        // target type. If the target type gets bigger, then the early shift 
        // doesnt matter because the upper bits are independent of the src, but
        // if the target get smaller then the right shift first is important
        // in order not to lose data.
        TSRC intermediate = src;
        intermediate >>= (-SHL_AMT);
        return (TDEST)intermediate;        
    }
};

#endif /* end of include guard: TEMPLATE_UTILS_H__ */
