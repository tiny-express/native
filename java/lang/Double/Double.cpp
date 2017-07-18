/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Double.hpp"
#include "../Object/Object.hpp"
#include "../Math/Math.hpp"
#include "../Long/Long.hpp"

using namespace Java::Lang;

/**
     * Returns a representation of the specified floating-point value
     * according to the IEEE 754 floating-point "double
     * format" bit layout, preserving Not-a-Number (NaN) values.
     *
     * Bit 63 (the bit that is selected by the mask
     * {@code 0x8000000000000000L}) represents the sign of the
     * floating-point number. Bits
     * 62-52 (the bits that are selected by the mask
     * {@code 0x7ff0000000000000L}) represent the exponent. Bits 51-0
     * (the bits that are selected by the mask
     * {@code 0x000fffffffffffffL}) represent the significand
     * (sometimes called the mantissa) of the floating-point number.
     *
     * If the argument is positive infinity, the result is
     * {@code 0x7ff0000000000000L}.
     *
     * If the argument is negative infinity, the result is
     * {@code 0xfff0000000000000L}.
     *
     * If the argument is NaN, the result is the {@code long}
     * integer representing the actual NaN value.  Unlike the
     * {@code doubleToLongBits} method,
     * {@code doubleToRawLongBits} does not collapse all the bit
     * patterns encoding a NaN to a single "canonical" NaN
     * value.
     *
     * In all cases, the result is a {@code long} integer that,
     * when given to the {@link #longBitsToDouble(long)} method, will
     * produce a floating-point value the same as the argument to
     * {@code doubleToRawLongBits}.
     *
     * @param   value   a {@code double} precision floating-point number.
     * @return the bits that represent the floating-point number.
     */
static long doubleToRawLongBits(double value);

/**
 * Bit mask to isolate the exponent field of a
 * double.
 */
static long	EXP_BIT_MASK	= 0x7FF0000000000000L;

/**
 * Bit mask to isolate the significand field of a
 * double
 */
static long	SIGNIF_BIT_MASK	= 0x000FFFFFFFFFFFFFL;

/**
 * A constant holding the positive infinity of type
 */
static double POSITIVE_INFINITY_DOUBLE = 1.0 / 0.0; // inf

/**
 * A constant holding the negative infinity of type
 */
static double NEGATIVE_INFINITY_DOUBLE = -1.0 / 0.0; // -inf

/**
 * A constant holding a Not-a-Number (NaN) value of type
 */
static double NOT_A_NUMBER_DOUBLE = 0.0 / 0.0; // -nan

/**
 * A constant holding the largest positive finite value of type
 */
static double MAX_VALUE_DOUBLE = 0x1.fffffffffffffP+1023; // 1.797693134862316e+308

/**
 * A constant holding the smallest positive normal value of type
 */
static double MIN_NORMAL_DOUBLE = 0x1.0p-1022; // 2.225073858507201e-308

/**
 * A constant holding the smallest positive nonzero value of type
 */
static double MIN_VALUE_DOUBLE = 0x0.0000000000001P-1022; // 4.940656458412465e-324

/**
 * Minimum exponent a normalized <code>double</code> number may
 * have.  It is equal to the value returned by
 * <code>Math.ilogb(Double.MIN_NORMAL)</code>.
 */
static int	MIN_EXPONENT	= -1022;

Double::Double() {
	this->original = 0;
	this->string_original = string_from_double(this->original);
}

Double::Double(double original) {
//    if (isNaN(original) || isInfinite(original))
//        return -1;
	this->original = original;
	this->string_original = string_from_double(this->original);
}

Double::Double(const Double &doubleNumber) {
//    if (isNaN(original) || isInfinite(original))
//        return -1;
	this->original = doubleNumber.original;
	this->string_original = string_from_double(this->original);
}

Double::~Double() {
	if (this->string_original != NULL) {
		free(this->string_original);
	}
}

Double Double::parseDouble(String target) {
    return Double(string_to_double(target.toString()));
}

string Double::toString() const {
	return (string) this->string_original;
}

// TODO waiting for FloatingDecimal.toJavaFormatString()
//String Double::toString(double d) {
//    return FloatingDecimal.toJavaFormatString(d);
//}

char Double::charValue() const {
    string convertResult = string_from_double(this->original);
    char charValueResult = string_to_char(convertResult);
    free(convertResult);
    return charValueResult;
}

string Double::stringValue() const {
        return (string) this->toString();
}

short Double::shortValue() const {
    return (short) this->original;
}

int Double::intValue() const {
    return (int) this->original;
}

long Double::longValue() const {
    return (long) this->original;
}

float Double::floatValue() const {
    return (float) this->original;
}

double Double::doubleValue() const {
    return this->original;
}

byte Double::byteValue() const {
    return (byte) this->original;
}

Double Double::operator+(const Double &target) {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return Double(this->original + target.original);
}

Double Double::operator-(const Double &target) {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return Double(this->original - target.original);
}

Double Double::operator*(const Double &target) {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return Double( this->original * target.original );
}

Double Double::operator/(const Double &target) {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return Double( this->original / target.original );
}

// /**
//  * Make a modulo from this Double with target
//  *
//  * @return Double
//  */
// Double Double::operator%(const Double &target) {
// 	return ( this->original % target.original );
// }

boolean Double::operator==(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (boolean) (this->original == target.original);
}

boolean Double::operator!=(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (boolean) (!this->operator==(target));
}

boolean Double::operator<(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (boolean) (this->original < target.original);
}

boolean Double::operator>(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (boolean) (this->original > target.original);
}

boolean Double::operator>=(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (boolean) (this->original >= target.original);
}

boolean Double::operator<=(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (boolean) (this->original <= target.original);
}

boolean Double::operator&&(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (boolean) (this->original && target.original);
}

boolean Double::operator||(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (boolean) (this->original || target.original);
}

Double Double::operator=(const Double &target) {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    this->original = target.original;
    free(this->string_original);
    this->string_original = string_from_double(this->original);
    return *this;
}

Double Double::operator+=(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (Double) (this->original + target.original);
}

Double Double::operator-=(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (Double) (this->original - target.original);
}

Double Double::operator*=(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (Double) (this->original * target.original);
}

Double Double::operator/=(const Double &target) const {
//    if (isNaN(target.doubleValue()) || isInfinite(target.doubleValue()))
//        return -1;
    return (Double) (this->original / target.original);
}

int Double::compare(double double1, double double2) {
    if (isNaN(double1) || isInfinite(double1))
        return -9999;

    if (isNaN(double2) || isInfinite(double2))
        return -9999;

    if (double1 < double2)
        // Neither value is NaN, thisValue is smaller
        return -1;

    if (double1 > double2)
        // Neither value is NaN, thisValue is larger
        return 1;

    // Cannot use doubleToRawLongBits because of possibility of NaNs.
    long thisBits = Double::doubleToLongBits(double1);
    long anotherBits = Double::doubleToLongBits(double2);

    if (thisBits == anotherBits) {
            // Values are equal
            return 0;

    } else if (thisBits < anotherBits) {
            // (-0.0, 0.0) or (!NaN, NaN)
            return -1;

    } else {
            // (0.0, -0.0) or (NaN, !NaN)
            return 1;
    }
}

int Double::compareTo(Double anotherDouble) {
    return Double::compare(this->original, anotherDouble.original);
}

long Double::doubleToLongBits(double valueDouble) {
    if (isNaN(valueDouble) || isInfinite(valueDouble))
        return -9999;
    long doubleToLongBitsResult = doubleToRawLongBits(valueDouble);

    // Check for NaN based on values of bit fields, maximum
    // exponent and nonzero significand.

    long andOperatorBetweendoubleToLongBitsResultAndEXP_BIT_MASK
            = doubleToLongBitsResult & EXP_BIT_MASK;

    long andOperatorBetweendoubleToLongBitsResultAndSIGNIF_BIT_MASK
            = doubleToLongBitsResult & SIGNIF_BIT_MASK;

    boolean isEqualEXP_BIT_MASK
            = (andOperatorBetweendoubleToLongBitsResultAndEXP_BIT_MASK == EXP_BIT_MASK);

    boolean isNotEqual0L = (andOperatorBetweendoubleToLongBitsResultAndSIGNIF_BIT_MASK != 0L);

    if (isEqualEXP_BIT_MASK && isNotEqual0L )
        doubleToLongBitsResult = 0x7ff8000000000000L;

    return doubleToLongBitsResult;
}

// TODO waiting for implement
long Double::doubleToRawLongBits(double valueDouble) {
    if (isNaN(valueDouble) || isInfinite(valueDouble))
        return -9999;

}

// TODO Waiting for instanceof , doubleToRawLongBits
boolean Double::equals(const Double &object) {
    if (isNaN(object.doubleValue()) || isInfinite(object.doubleValue()))
        return -1;
    boolean isDouble = instanceof<Double>(object);
    Double* castObjectToDouble = (Double*)&object;
    long doubleToLongBitsObject = doubleToLongBits(castObjectToDouble->original);
    long doubleToLongBitsThis = doubleToLongBits(this->original);
    boolean isEqual = (doubleToLongBitsObject == doubleToLongBitsThis);
    return (isDouble && isEqual);
}

// TODO waiting for doubleToRawLongBits
long Double::hashCode() {
    return Double::hashCode(this->original);
}

// TODO waiting for doubleToRawLongBits
long Double::hashCode(double valuehashCode) {
    long bits = doubleToLongBits(valuehashCode);
    unsigned long rightShiftBits = (unsigned long)bits >> 32;
    return  (bits ^ rightShiftBits);
}

boolean Double::isFinite(double valueDouble) {
    return (Math::abs(valueDouble) <= MAX_VALUE_DOUBLE);
}

boolean Double::isInfinite(double valueDouble) {
    boolean condition1 = (valueDouble == POSITIVE_INFINITY_DOUBLE);
    boolean condition2 = (valueDouble == NEGATIVE_INFINITY_DOUBLE);
    return ( condition1 || condition2 ) ;
}

boolean Double::isInfinite() {
    return isInfinite(this->original);
}

boolean Double::isNaN(double valueDouble) {
    return (valueDouble != valueDouble);
}

boolean Double::isNaN() {
    return isNaN(this->original);
}

// TODO waiting for implement
double Double::longBitsToDouble(long bits){

}

double Double::min(double doubleA, double doubleB) {
    return Math::min(doubleA, doubleB);
}

// TODO waiting for implement
//String Double::toHexString(double doubleValue) {
//    /*
//     * Modeled after the "a" conversion specifier in C99, section
//     * 7.19.6.1; however, the output of this method is more
//     * tightly specified.
//     */
//    if (!isFinite(doubleValue))
//        // For infinity and NaN, use the decimal output.
//        return Double::toString(doubleValue);
//    else {
//        // Initialized to maximum size of output.
//        StringBuilder answer = new StringBuilder(24);
//
//        if (Math::copySign(1.0, doubleValue) == -1.0) // value is negative,
//            answer.append("-"); // so append sign info
//
//        answer.append("0x");
//
//        doubleValue = Math::abs(doubleValue);
//
//        if (doubleValue == 0.0) {
//            answer.append("0.0p0");
//        } else {
//            boolean subnormal = (doubleValue < MIN_NORMAL_DOUBLE);
//
//            // Isolate significand bits and OR in a high-order bit
//            // so that the string representation has a known
//            // length.
//            long signifBits = (Double::doubleToLongBits(doubleValue) & SIGNIF_BIT_MASK) | 0x1000000000000000L;
//
//            // Subnormal values have a 0 implicit bit; normal
//            // values have a 1 implicit bit.
//            answer.append(subnormal ? "0." : "1.");
//
//            // Isolate the low-order 13 digits of the hex
//            // representation.  If all the digits are zero,
//            // replace with a single 0; otherwise, remove all
//            // trailing zeros.
//            String signif = Long::toHexString(signifBits).substring(3,16);
//            answer.append(signif.equals("0000000000000") ? // 13 zeros
//                          "0"
//                                                         : signif.replaceFirst("0{1,12}$", ""));
//
//            answer.append('p');
//            // If the value is subnormal, use the E_min exponent
//            // value for double; otherwise, extract and report d's
//            // exponent (the representation of a subnormal uses
//            // E_min -1).
//            answer.append(subnormal ? MIN_EXPONENT : Math::getExponent(doubleValue));
//        }
//        return answer.toString();
//    }
//}