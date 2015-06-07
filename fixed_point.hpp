#ifndef FIXED_POINT_H__
#define FIXED_POINT_H__

#include <ostream>
#include <iomanip>

#include "template_utils.hpp"

/// A fixed-point integer type
/** \tparam INT_BITS The number of bits before the radix point
 *  \tparam FRAC_BITS The number of bits after the radix point
 *  \warning INT_BITS and FRAC_BITS must be non-negative, and their sum cannot exceed 64
 *
 *  Fixed point numbers are signed, so FixedPoint<5,2>, for example, has a
 *  range of -16.00 to +15.75
 *
 *  The internal storage (FixedPoint::raw_) is rounded up to the next highest
 *  power of 2, so a 17 bit number occupies 32 physical bits. Consider that the
 *  multiplication of a 5 bit fixed point (which occupies 8 bits of space) with
 *  an 10 bit fixed point (which occupies 16 bits of space) results in a 15 bit
 *  fixed point which occupies 16 bits of space.
 */
template <int INT_BITS, int FRAC_BITS>
struct FixedPoint
{
public:

    /// The integer type used internally to store the value
    typedef typename GET_INT_WITH_LENGTH<INT_BITS + FRAC_BITS>::RESULT RawType;

    /// This is a type big enough to hold the largest integer value
    typedef typename GET_INT_WITH_LENGTH<INT_BITS>::RESULT IntType;

    /// This is the type that can handle the largest rounded integer value
    /** Note that this is slightly different to IntType because FixedPoint<3,1>(3.5).round() == 4 */
    typedef typename GET_INT_WITH_LENGTH<INT_BITS + 1>::RESULT RoundType;



    typedef FixedPoint<INT_BITS, FRAC_BITS> ThisType;

    struct RawValue
    {
        RawValue(RawType aValue) : value(aValue) { }
        RawType value;
    };

    ///Aiding Functions for conflicting int intialization
    static ThisType fromInt(IntType value) { return ThisType(RawValue(value << FRAC_BITS));}
    static ThisType fromFloat(float value) { return ThisType(RawType(value * (1 << FRAC_BITS)));}

    /// Create a fixed-point with equivalent integer value
    /** For example in 4.12 fixed-point, the number "2" is 0010.000000000000  */
    FixedPoint(int value) : raw_(value << FRAC_BITS) { }

    FixedPoint(double value) : raw_((RawType)(value * (1 << FRAC_BITS))) { }
    FixedPoint(float value) : raw_((RawType)(value * (1 << FRAC_BITS))) { }

    /// Default constructor
    FixedPoint() : raw_(0) { }

    FixedPoint(RawValue value): raw_(value.value) { }

    /// Create a fixed-point with a predefined raw_ value, with no manipulation
    static FixedPoint<INT_BITS, FRAC_BITS> createRaw(RawType aData) { return FixedPoint<INT_BITS, FRAC_BITS>(RawValue(aData)); }

    /// Returns a new fixed-point that reinterprets the binary raw_.
    /** \warning This should be used sparingly since returns a number whos
      * value is not the necessarily same.
      * \note To just move the radix point, rather use LeftShift or RightShift  */
    template <int INT_BITS_NEW, int FRAC_BITS_NEW>
    FixedPoint<INT_BITS_NEW, FRAC_BITS_NEW> reinterpret()
    {
        return FixedPoint<INT_BITS_NEW, FRAC_BITS_NEW>::createRaw(raw_);
    }

    /// Make the integral part larger
    template <int INT_BITS_NEW>
    FixedPoint<INT_BITS_NEW, FRAC_BITS> extend()
    {
        return FixedPoint<INT_BITS_NEW, FRAC_BITS>::createRaw(raw_);
    }

    /// Returns a new fixed-point in a new format which is similar in value to the original
    /** This may result in loss of raw_ if the number of bits for either the
      * integer or fractional part are less than the original. */
    template <int INT_BITS_NEW, int FRAC_BITS_NEW>
    FixedPoint<INT_BITS_NEW, FRAC_BITS_NEW> convert() const
    {
        typedef typename FixedPoint<INT_BITS_NEW, FRAC_BITS_NEW>::RawType TargetRawType;

        return FixedPoint<INT_BITS_NEW, FRAC_BITS_NEW>::createRaw(
            CONVERT_FIXED_POINT<
                RawType,
                TargetRawType,
                (FRAC_BITS_NEW - FRAC_BITS),
                (FRAC_BITS_NEW > FRAC_BITS)
                >:: exec(raw_));
    }

    /// Multiplication with another fixed-point
    template <int INT_BITS2, int FRAC_BITS2>
    FixedPoint<INT_BITS + INT_BITS2, FRAC_BITS + FRAC_BITS2>
        operator *(FixedPoint<INT_BITS2, FRAC_BITS2> value) const
    {
        return FixedPoint<INT_BITS + INT_BITS2, FRAC_BITS + FRAC_BITS2>::createRaw(raw_ * value.getRaw());
    }

    /// Addition with an integer
    FixedPoint<INT_BITS, FRAC_BITS> operator +(IntType value) const
    {
        return *this + FixedPoint<INT_BITS, FRAC_BITS>(value);
    }

    /// Addition with another fixed point
    template <int INT_BITS2, int FRAC_BITS2>
    FixedPoint<GET_MAX<INT_BITS, INT_BITS2>::RESULT, GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT>
        operator+(FixedPoint<INT_BITS2, FRAC_BITS2> value) const
    {
        // How many bits are in the result?
        static const int INT_BITS_RES = GET_MAX<INT_BITS, INT_BITS2>::RESULT;
        static const int FRAC_BITS_RES = GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT;

        // This is the type of the result
        typedef FixedPoint<INT_BITS_RES, FRAC_BITS_RES> ResultType;

        // Convert both operands to result type
        ResultType op1(this->convert<INT_BITS_RES, FRAC_BITS_RES>());
        ResultType op2(value.convert<INT_BITS_RES, FRAC_BITS_RES>());

        // Then the addition is trivial
        return ResultType::createRaw(op1.getRaw() + op2.getRaw());
    }

    template <int INT_BITS2, int FRAC_BITS2>
    ThisType& operator+=(FixedPoint<INT_BITS2, FRAC_BITS2> value)
    {
        raw_ += value.convert<INT_BITS, FRAC_BITS>().getRaw();
        return *this;
    }

    ThisType& operator+=(IntType value)
    {
        raw_ += ThisType(value).getRaw();
        return *this;
    }

    ThisType& operator-=(IntType value)
    {
        raw_ -= ThisType(value).getRaw();
        return *this;
    }

    template <int INT_BITS2, int FRAC_BITS2>
    ThisType& operator-=(FixedPoint<INT_BITS2, FRAC_BITS2> value)
    {
        raw_ -= value.convert<INT_BITS, FRAC_BITS>().getRaw();
        return *this;
    }

    /// Subtraction operator
    template <int INT_BITS2, int FRAC_BITS2>
    FixedPoint<GET_MAX<INT_BITS, INT_BITS2>::RESULT, GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT>
        operator-(FixedPoint<INT_BITS2, FRAC_BITS2> value) const
    {
        // How many bits are in the result?
        static const int INT_BITS_RES = GET_MAX<INT_BITS, INT_BITS2>::RESULT;
        static const int FRAC_BITS_RES = GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT;

        // This is the type of the result
        typedef FixedPoint<INT_BITS_RES, FRAC_BITS_RES> ResultType;

        // Convert both operands to result type
        ResultType op1(this->convert<INT_BITS_RES, FRAC_BITS_RES>());
        ResultType op2(value.convert<INT_BITS_RES, FRAC_BITS_RES>());

        // Then the addition is trivial
        return ResultType::createRaw(op1.getRaw() - op2.getRaw());
    }

    template <int INT_BITS2, int FRAC_BITS2>
    bool operator < (FixedPoint<INT_BITS2, FRAC_BITS2> other) const
    {
        // How many bits are in the result?
        static const int INT_BITS_RES = GET_MAX<INT_BITS, INT_BITS2>::RESULT;
        static const int FRAC_BITS_RES = GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT;

        // This is the type of the result
        typedef FixedPoint<INT_BITS_RES, FRAC_BITS_RES> ResultType;

        // Convert both operands to result type
        ResultType op1(this->convert<INT_BITS_RES, FRAC_BITS_RES>());
        ResultType op2(other.convert<INT_BITS_RES, FRAC_BITS_RES>());

        // Then the operation is trivial
        return op1.getRaw() < op2.getRaw();
    }

    template <int INT_BITS2, int FRAC_BITS2>
    bool operator > (FixedPoint<INT_BITS2, FRAC_BITS2> other) const
    {
        // How many bits are in the result?
        static const int INT_BITS_RES = GET_MAX<INT_BITS, INT_BITS2>::RESULT;
        static const int FRAC_BITS_RES = GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT;

        // This is the type of the result
        typedef FixedPoint<INT_BITS_RES, FRAC_BITS_RES> ResultType;

        // Convert both operands to result type
        ResultType op1(this->convert<INT_BITS_RES, FRAC_BITS_RES>());
        ResultType op2(other.convert<INT_BITS_RES, FRAC_BITS_RES>());

        // Then the operation is trivial
        return op1.getRaw() > op2.getRaw();
    }

    template <int INT_BITS2, int FRAC_BITS2>
    bool operator >= (FixedPoint<INT_BITS2, FRAC_BITS2> other) const
    {
        // How many bits are in the result?
        static const int INT_BITS_RES = GET_MAX<INT_BITS, INT_BITS2>::RESULT;
        static const int FRAC_BITS_RES = GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT;

        // This is the type of the result
        typedef FixedPoint<INT_BITS_RES, FRAC_BITS_RES> ResultType;

        // Convert both operands to result type
        ResultType op1(this->convert<INT_BITS_RES, FRAC_BITS_RES>());
        ResultType op2(other.convert<INT_BITS_RES, FRAC_BITS_RES>());

        // Then the operation is trivial
        return op1.getRaw() >= op2.getRaw();
    }

    template <int INT_BITS2, int FRAC_BITS2>
    bool operator <= (FixedPoint<INT_BITS2, FRAC_BITS2> other) const
    {
        // How many bits are in the result?
        static const int INT_BITS_RES = GET_MAX<INT_BITS, INT_BITS2>::RESULT;
        static const int FRAC_BITS_RES = GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT;

        // This is the type of the result
        typedef FixedPoint<INT_BITS_RES, FRAC_BITS_RES> ResultType;

        // Convert both operands to result type
        ResultType op1(this->convert<INT_BITS_RES, FRAC_BITS_RES>());
        ResultType op2(other.convert<INT_BITS_RES, FRAC_BITS_RES>());

        // Then the operation is trivial
        return op1.getRaw() <= op2.getRaw();
    }

    template <int INT_BITS2, int FRAC_BITS2>
    bool operator ==(FixedPoint<INT_BITS2, FRAC_BITS2> other) const
    {
        // How many bits are in the result?
        static const int INT_BITS_RES = GET_MAX<INT_BITS, INT_BITS2>::RESULT;
        static const int FRAC_BITS_RES = GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT;

        // This is the type of the result
        typedef FixedPoint<INT_BITS_RES, FRAC_BITS_RES> ResultType;

        // Convert both operands to result type
        ResultType op1(this->convert<INT_BITS_RES, FRAC_BITS_RES>());
        ResultType op2(other.convert<INT_BITS_RES, FRAC_BITS_RES>());

        // Then the operation is trivial
        return op1.getRaw() == op2.getRaw();
    }

    template <int INT_BITS2, int FRAC_BITS2>
    bool operator != (FixedPoint<INT_BITS2, FRAC_BITS2> other) const
    {
        // How many bits are in the result?
        static const int INT_BITS_RES = GET_MAX<INT_BITS, INT_BITS2>::RESULT;
        static const int FRAC_BITS_RES = GET_MAX<FRAC_BITS, FRAC_BITS2>::RESULT;

        // This is the type of the result
        typedef FixedPoint<INT_BITS_RES, FRAC_BITS_RES> ResultType;

        // Convert both operands to result type
        ResultType op1(this->convert<INT_BITS_RES, FRAC_BITS_RES>());
        ResultType op2(other.convert<INT_BITS_RES, FRAC_BITS_RES>());

        // Then the operation is trivial
        return op1.getRaw() != op2.getRaw();
    }

    /// Divide operator
    template <int INT_BITS2, int FRAC_BITS2>
    FixedPoint<INT_BITS + FRAC_BITS2, FRAC_BITS + INT_BITS2>
        operator/(FixedPoint<INT_BITS2, FRAC_BITS2> divisor) const
    {
        // (A/2^B)/(C/2^D) = (A/C)/2^(B-D);

        typedef FixedPoint<INT_BITS + FRAC_BITS2, FRAC_BITS + INT_BITS2> ResultType;
        typedef typename GET_INT_WITH_LENGTH<INT_BITS + FRAC_BITS + FRAC_BITS2 + INT_BITS2>::RESULT IntermediateType;

        // Expand the dividend so we don't lose resolution
        IntermediateType intermediate(raw_);
        // Shift the dividend. FRAC_BITS2 cancels with the fractional bits in
        // divisor, and INT_BITS2 adds the required resolution.
        intermediate <<= FRAC_BITS2 + INT_BITS2;
        intermediate /= divisor.getRaw();

        return ResultType::createRaw(intermediate);
    }

    FixedPoint<INT_BITS, FRAC_BITS>& operator=(const FixedPoint<INT_BITS, FRAC_BITS> value)
    {
        raw_ = value.getRaw();
        return *this;
    }

    FixedPoint<INT_BITS, FRAC_BITS>& operator=(const IntType value)
    {
        raw_ = FixedPoint<INT_BITS, FRAC_BITS>(value).getRaw();
        return *this;
    }

    FixedPoint<INT_BITS, FRAC_BITS>& operator=(const float value)
    {
        raw_ = FixedPoint<INT_BITS, FRAC_BITS>(value).getRaw();
        return *this;
    }

    FixedPoint<INT_BITS, FRAC_BITS>& operator=(const double value)
    {
        raw_ = FixedPoint<INT_BITS, FRAC_BITS>(value).getRaw();
        return *this;
    }

    /// Shift left by literal amount (just moves radix right)
    template <int AMT>
    FixedPoint<INT_BITS + AMT, FRAC_BITS - AMT> leftShift() const
    {
        return FixedPoint<INT_BITS + AMT, FRAC_BITS - AMT>::createRaw(raw_);
    }

    /// Shift right by literal amount (just moves radix left)
    template <int AMT>
    FixedPoint<INT_BITS - AMT, FRAC_BITS + AMT> rightShift() const
    {
        /// \todo Check that this does the right thing arithmetically with negative numbers
        return FixedPoint<INT_BITS - AMT, FRAC_BITS + AMT>::createRaw(raw_);
    }

    /// Write to an output stream
    std::ostream& emit(std::ostream& os) const
    {
        return os << std::fixed << std::setprecision((FRAC_BITS * 3 + 9) / 10) << getValueF();
    }

    /// For debugging: return the number of bits before the radix
    int getIntegralLength() const { return INT_BITS; }
    /// For debugging: return the number of bits after the radix
    int getFractionalLength() const { return FRAC_BITS; }
    /// Get the value as a floating point
    double getValueF() const { return ((double)raw_)/(1 << FRAC_BITS); }
    /// Get the value truncated to an integer
    IntType getValue() const { return (IntType)(raw_ >> FRAC_BITS); }
    /// Get the value rounded to an integer (only works if FRAC_BITS > 0)
    RoundType round() const { return (RoundType)((raw_ + ((1 << FRAC_BITS) - 1)) >> FRAC_BITS); }
    /// Returns the raw internal binary contents
    RawType getRaw() const { return raw_; }

    static const int BIT_LENGTH = INT_BITS + FRAC_BITS;
    static const int FRAC_BITS_LENGTH = FRAC_BITS;
    static const int EXP_BITS_LENGTH = FRAC_BITS;


private:

    RawType raw_;
};

// Make the fixed-point struct  ostream outputtable
template <int INT_BITS, int FRAC_BITS>
std::ostream& operator<< (std::ostream &stream, const FixedPoint<INT_BITS, FRAC_BITS> &fixedPoint)
{
    return fixedPoint.emit(stream);
}

#endif /* end of include guard: FIXED_POINT_H__ */
