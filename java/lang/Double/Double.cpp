/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
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
#include <stdio.h>
#include <cstdlib>


using namespace Java::Lang;

/**
 * Returns a representation of the specified floating-point value
 * according to the IEEE 754 floating-point "double
 * format" bit layout
 *
 * @param   value   a {@code double} precision floating-point number.
 * @return the bits that represent the floating-point number.
 */
static long doubleToRawLongBits(double value);

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

// TODO Fix error leak, and pass all test case
/**
 * Convert double to binary 32 bit
 * (Single-precision floating-point format
 * In IEEE 754-2008)
 *
 * @param double
 * @return string binary 32 bit of input
 */
string Double::doubleToBinary32StringType(double doubleInput)
{
    string integerPartNormalizeForm = (string) malloc (31*sizeof(char));
    string fractionPartNormalizeForm = (string) malloc (31*sizeof(char));
    string doubleInputNormalizeForm = (string) malloc (31*sizeof(char));
    string resultDoubleToBinary32StringType = (string) malloc (31*sizeof(char));

    int powerExponentBase2;
    int integerPartDoubleInput;
    
    int sizeOfIntegerPartNormalizeForm;
    int sizeOfFractionPartNormalizeForm;
    int sizeOfDoubleInputNormalizeForm;

    int sizeOfExponentPartBinary32 = 8;

    int i;
    int index;
    int indexOfDotDoubleInputNormalizeForm;
    int indexFirstBit1DoubleInputNormalizeForm;
    int indexBeginFractionPartResultDoubleToBinary32StringType;

    int exponentBiasBinary32 = 127;
    int exponentDoubleInput;

    double fractionPartDoubleInput;

    /** Assign value '0' to integerPartNormalizeForm */
    for (int i = 0 ; i<= 31; i++) {
        integerPartNormalizeForm[i] = '0';
        fractionPartNormalizeForm[i] = '0';
        doubleInputNormalizeForm[i] = '0';
        resultDoubleToBinary32StringType[i] = '0';
    }
    resultDoubleToBinary32StringType[32] = '\0';

    /** Check if doubleInput == 0 */
    if(doubleInput == 0){
        free(integerPartNormalizeForm);
        free(fractionPartNormalizeForm);
        free(doubleInputNormalizeForm);
        return  strdup(resultDoubleToBinary32StringType);
    }

    /** Check if doubleInput == POSITIVE_INFINITY_DOUBLE */
    if(doubleInput == POSITIVE_INFINITY_DOUBLE){
        free(integerPartNormalizeForm);
        free(fractionPartNormalizeForm);
        free(doubleInputNormalizeForm);
        resultDoubleToBinary32StringType
                = (string) "01111111100000000000000000000000";
        return  strdup(resultDoubleToBinary32StringType);
    }

    /** Check if doubleInput == POSITIVE_INFINITY_DOUBLE */
    if(doubleInput == NEGATIVE_INFINITY_DOUBLE){
        free(integerPartNormalizeForm);
        free(fractionPartNormalizeForm);
        free(doubleInputNormalizeForm);
        resultDoubleToBinary32StringType
                = (string) "11111111100000000000000000000000";
        return  strdup(resultDoubleToBinary32StringType);
    }

    /** Get size of integerPartNormalizeForm  */
    integerPartDoubleInput = abs((int) floor(doubleInput));
    sizeOfIntegerPartNormalizeForm = 0;

    if (integerPartDoubleInput == 0) {
        sizeOfIntegerPartNormalizeForm = 1;
    }

    if (integerPartDoubleInput != 0) {
        while (integerPartDoubleInput != 0) {
            sizeOfIntegerPartNormalizeForm++;
            integerPartDoubleInput = integerPartDoubleInput >> 1;
        }
    }

    /** Assign value to integerPartNormalizeForm */
    integerPartDoubleInput = abs((int) floor(doubleInput));
    index = sizeOfIntegerPartNormalizeForm -1;

    while (integerPartDoubleInput != 0) {

        if ( (integerPartDoubleInput & 1) == 1) {
            integerPartNormalizeForm[index] = '1';
        }

        if ( (integerPartDoubleInput & 1) == 0) {
            integerPartNormalizeForm[index] = '0';
        }

        index--;
        integerPartDoubleInput = integerPartDoubleInput >> 1;
    }

    /** Assign value to fractionPartNormalizeForm */
    fractionPartDoubleInput = doubleInput - integerPartDoubleInput;
    index = 0;

    while (fractionPartDoubleInput != 0) {
        fractionPartDoubleInput = fractionPartDoubleInput * 2;

        int integerPart = (int) floor(fractionPartDoubleInput);

        if (integerPart == 1) {
            fractionPartNormalizeForm[index] = '1';
        }

        if (integerPart == 0) {
            fractionPartNormalizeForm[index] = '0';
        }

        index++;
        fractionPartDoubleInput = fractionPartDoubleInput - integerPart;
    }

    /** Assign value to sizeOfFractionPartNormalizeForm */
    sizeOfFractionPartNormalizeForm = index;

    /** Assign value to doubleInputNormalizeForm */

        /** Copy value from integerPartNormalizeForm to doubleInputNormalizeForm */
        for(int i = 0; i < sizeOfIntegerPartNormalizeForm; i++) {
            doubleInputNormalizeForm[i] = integerPartNormalizeForm[i];
        }

        /** Assign value to indexOfDotDoubleInputNormalizeForm */
        indexOfDotDoubleInputNormalizeForm = sizeOfIntegerPartNormalizeForm;

        /** Assign '.' between integerPart and fractionPart */
        doubleInputNormalizeForm [indexOfDotDoubleInputNormalizeForm] = '.';

        /** Copy value from fractionPartNormalizeForm
         * to doubleInputNormalizeForm
         */
        index = indexOfDotDoubleInputNormalizeForm +1;
        for(int i = 0; i <= sizeOfFractionPartNormalizeForm; i++, index++) {
            doubleInputNormalizeForm[index]
                    = fractionPartNormalizeForm[i];
        }

    /** Assign value to sizeOfDoubleInputNormalizeForm */
    sizeOfDoubleInputNormalizeForm = sizeOfIntegerPartNormalizeForm + 1
                                    + sizeOfFractionPartNormalizeForm;

    /** Assign value to indexFirstBit1DoubleInputNormalizeForm */
    indexFirstBit1DoubleInputNormalizeForm = 1;
    for (int i = 0; i <= sizeOfDoubleInputNormalizeForm; i++) {
        if (doubleInputNormalizeForm[i] == '1') {
            indexFirstBit1DoubleInputNormalizeForm = i;
            break;
        }
    }

    /** Assign value to powerExponentBase2 */
    integerPartDoubleInput =  abs((int) floor(doubleInput));
    if (integerPartDoubleInput != 0) {
        powerExponentBase2 = indexOfDotDoubleInputNormalizeForm
                             - indexFirstBit1DoubleInputNormalizeForm -1;
    }

    if (integerPartDoubleInput == 0) {
        powerExponentBase2 = indexOfDotDoubleInputNormalizeForm
                             - indexFirstBit1DoubleInputNormalizeForm;
    }

    /** Assign value to resultDoubleToBinary32StringType */

        /** Assign value to resultDoubleToBinary32StringType[0] */
        if (doubleInput >= 0) {
            resultDoubleToBinary32StringType[0] = '0';
        }

        if (doubleInput < 0) {
            resultDoubleToBinary32StringType[0] = '1';
        }

        /** Assign value to exponentDoubleInput */
        exponentDoubleInput = powerExponentBase2 + exponentBiasBinary32;

        /** Assign value to resultDoubleToBinary32StringType[8 -> 1] */
        index = sizeOfExponentPartBinary32;

        while (exponentDoubleInput != 0) {

            if ( (exponentDoubleInput & 1) == 1) {
                resultDoubleToBinary32StringType[index] = '1';
            }

            if ( (exponentDoubleInput & 1) == 0) {
                resultDoubleToBinary32StringType[index] = '0';
            }

            index--;
            exponentDoubleInput = exponentDoubleInput >> 1;
        }

        /** Assign value to indexBeginFractionPartResultDoubleToBinary32StringType */
        if (powerExponentBase2 >= 0) {
           indexBeginFractionPartResultDoubleToBinary32StringType
                   = sizeOfExponentPartBinary32 + 1;
        }

        if (powerExponentBase2 < 0) {
            indexBeginFractionPartResultDoubleToBinary32StringType
                    = sizeOfExponentPartBinary32 + powerExponentBase2 +1;
        }

    /** Assign value to resultDoubleToBinary32StringType[8 -> 31] */

    if (powerExponentBase2 >= 0) {
        i = indexFirstBit1DoubleInputNormalizeForm + 1;

    }

    if (powerExponentBase2 < 0) {
        i = indexOfDotDoubleInputNormalizeForm + 1;
    }

    index = indexBeginFractionPartResultDoubleToBinary32StringType;

    for (i ; i < sizeOfDoubleInputNormalizeForm; i++) {

        if (i == indexOfDotDoubleInputNormalizeForm) {
            i++;
        }

        resultDoubleToBinary32StringType[index]
                = doubleInputNormalizeForm[i];
        index++;
    }

    /** Return resultDoubleToBinary32StringType */
    free(integerPartNormalizeForm);
    free(fractionPartNormalizeForm);
    free(doubleInputNormalizeForm);
    return  strdup(resultDoubleToBinary32StringType);
}