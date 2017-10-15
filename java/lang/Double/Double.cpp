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

using namespace Java::Lang;

Double::Double() {
    this->original = 0;
    this->originalString = stringFromDouble(this->original);
}

Double::Double(double original) {
    this->original = original;
    this->originalString = stringFromDouble(this->original);
}

Double::Double(const Double &doubleNumber) {
    this->original = doubleNumber.original;
    this->originalString = stringFromDouble(this->original);
}

Double::~Double() {
    if (this->originalString != nullptr) {
        free(this->originalString);
    }
}

Double Double::parseDouble(String target) {
    return Double(stringToDouble(target.toString()));
}

string Double::toString() const {
    return (string) this->originalString;
}

// TODO(thoangminh): waiting for FloatingDecimal.toJavaFormatString()
// String Double::toString(double d) {
//    return FloatingDecimal.toJavaFormatString(d);
//}

char Double::charValue() const {
    string convertResult = stringFromDouble(this->original);
    char charValueResult = stringToChar(convertResult);
    free(convertResult);
    return charValueResult;
}

short Double::shortValue() const {
    return static_cast<short> (this->original);
}

int Double::intValue() const {
    return static_cast<int> (this->original);
}

long Double::longValue() const {
    return static_cast<long> (this->original);
}

float Double::floatValue() const {
    return static_cast<float> (this->original);
}

double Double::doubleValue() const {
    return this->original;
}

byte Double::byteValue() const {
    return static_cast<byte> (this->original);
}

Double Double::operator+(const Double &target) {
    return Double(this->original + target.original);
}

Double Double::operator-(const Double &target) {
    return Double(this->original - target.original);
}

Double Double::operator*(const Double &target) {
    return Double(this->original * target.original);
}

Double Double::operator/(const Double &target) {
    return Double(this->original / target.original);
}

boolean Double::operator==(const Double &target) const {
    return (boolean) equals(target.original);
}

boolean Double::operator!=(const Double &target) const {
    return (boolean) !equals(target.original);
}

boolean Double::operator<(const Double &target) const {
    int compareResult = compare(this->doubleValue(), target.doubleValue());
    return compareResult == -1;
}

boolean Double::operator>(const Double &target) const {
    int compareResult = compare(this->doubleValue(), target.doubleValue());
    return compareResult == 1;
}

boolean Double::operator>=(const Double &target) const {
    int compareResult = compare(this->doubleValue(), target.doubleValue());
    return compareResult == 1 || compareResult == 0;
}

boolean Double::operator<=(const Double &target) const {
    int compareResult = compare(this->doubleValue(), target.doubleValue());
    return compareResult == -1 || compareResult == 0;
}

boolean Double::operator&&(const Double &target) const {
    return (boolean) (this->original && target.original);
}

boolean Double::operator||(const Double &target) const {
    return (boolean) (this->original || target.original);
}

Double &Double::operator=(const Double &target) {
    this->original = target.original;
    free(this->originalString);
    this->originalString = stringFromDouble(target.original);
    return *this;
}

Double Double::operator+=(const Double &target) const {
    return (Double) (this->original + target.original);
}

Double Double::operator-=(const Double &target) const {
    return (Double) (this->original - target.original);
}

Double Double::operator*=(const Double &target) const {
    return (Double) (this->original * target.original);
}

Double Double::operator/=(const Double &target) const {
    return (Double) (this->original / target.original);
}

int Double::compare(double double1, double double2) {
    long thisBits = Double::doubleToLongBits(double1);
    long anotherBits = Double::doubleToLongBits(double2);

    if (thisBits == anotherBits) {
        return 0;
    }

    if (thisBits < anotherBits) {
        return -1;
    }

    return 1;
}

int Double::compareTo(Double anotherDouble) {
    return Double::compare(this->original, anotherDouble.original);
}

long Double::doubleToLongBits(double valueDouble) {
    return doubleToRawLongBits(valueDouble);
}

long Double::doubleToRawLongBits(double doubleInput) {
    String doubleInputToBinary64StringType;
    long resultDoubleToRawLongBits;
    int tempValue;
    int exponent;
    int i;

    doubleInputToBinary64StringType = doubleToBinary64StringType(doubleInput);

    exponent = 62;
    tempValue = 0;
    resultDoubleToRawLongBits = 0;

    for (i = 1; i <= 63; i++) {
        if (doubleInputToBinary64StringType.charAt(i) == '1') {
            tempValue = 1;
        }

        if (doubleInputToBinary64StringType.charAt(i) == '0') {
            tempValue = 0;
        }
        resultDoubleToRawLongBits = resultDoubleToRawLongBits + tempValue * (long) Math::pow(2, exponent);
        exponent--;
    }

    if (doubleInputToBinary64StringType.charAt(0) == '1') {
        resultDoubleToRawLongBits = (-1) * resultDoubleToRawLongBits;
    }

    return resultDoubleToRawLongBits;
}

// TODO(thoangminh): Wait for instanceof<>
boolean Double::equals(const Double &object) const {
    boolean isDouble = instanceof<Double>(object);
    auto castObjectToDouble = (Double *) &object;
    long doubleToLongBitsObject = doubleToLongBits(castObjectToDouble->original);
    long doubleToLongBitsThis = doubleToLongBits(this->original);
    boolean isEqual = (doubleToLongBitsObject == doubleToLongBitsThis);
    return isEqual;
    // return (isDouble && isEqual);
}

long Double::hashCode() {
    return Double::hashCode(this->original);
}

long Double::hashCode(double doubleInput) {
    long bits = doubleToLongBits(doubleInput);
    long rightShiftBits = bits >> 32;
    return (bits ^ rightShiftBits);
}

boolean Double::isFinite(double valueDouble) {
    return (Math::abs(valueDouble) <= MAX_VALUE);
}

boolean Double::isInfinite(double valueDouble) {
    boolean isPossitiveInfinity = (valueDouble == POSITIVE_INFINITY);
    boolean isNegativeInfinity = (valueDouble == NEGATIVE_INFINITY);
    return (isPossitiveInfinity || isNegativeInfinity);
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

double Double::longBitsToDouble(long longBitsInput) {
    if (Double::isNaN(longBitsInput)) {
        return NAN;
    }

    double resultLongBitsToDouble;
    String convertLongBitsToBinary64StringType;

    convertLongBitsToBinary64StringType = longBitsToBinary64StringType(longBitsInput);

    resultLongBitsToDouble = binary64StringTypeToDouble(convertLongBitsToBinary64StringType);

    return resultLongBitsToDouble;
}

double Double::min(double doubleA, double doubleB) {
    return Math::min(doubleA, doubleB);
}

// TODO(thoangminh): Wait for build
// String Double::toHexString(double doubleValue) {
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
//            boolean subnormal = (doubleValue < MIN_NORMAL);
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

String Double::doubleToBinary64StringType(double doubleInput) {
    auto integerPartNormalizeForm = (string) allocateMemory(2048 * sizeof(char));
    auto fractionPartNormalizeForm = (string) allocateMemory(54 * sizeof(char));
    auto doubleInputNormalizeForm = (string) allocateMemory(2102 * sizeof(char));
    auto resultDoubleToBinary64StringType = (string) allocateMemory(65 * sizeof(char));

    int powerExponentBase2 = 0;
    int integerPartDoubleInput;

    int sizeOfIntegerPartNormalizeForm;
    int sizeOfFractionPartNormalizeForm;
    int sizeOfDoubleInputNormalizeForm;

    int sizeOfExponentPartBinary64 = 11;

    int i;
    int index;
    int indexOfDotDoubleInputNormalizeForm;
    int indexFirstBit1DoubleInputNormalizeForm;
    int indexBeginFractionPartResultDoubleToBinary64StringType = 0;

    int exponentBiasBinary64 = 1023;
    int exponentDoubleInput;

    double fractionPartDoubleInput;

    for (i = 0; i <= 63; i++) {
        doubleInputNormalizeForm[i] = '0';
        resultDoubleToBinary64StringType[i] = '0';
    }

    for (i = 0; i <= 52; i++) {
        integerPartNormalizeForm[i] = '0';
        fractionPartNormalizeForm[i] = '0';
    }

    /** Set end point for string type */
    integerPartNormalizeForm[2047] = '\0';
    fractionPartNormalizeForm[53] = '\0';
    doubleInputNormalizeForm[2101] = '\0';
    resultDoubleToBinary64StringType[64] = '\0';

    if (doubleInput >= 0) {
        resultDoubleToBinary64StringType[0] = '0';
    }

    if (doubleInput < 0) {
        resultDoubleToBinary64StringType[0] = '1';
    }

    if (doubleInput == 0) {
        goto outPut;
    }

    if (doubleInput == POSITIVE_INFINITY) {
        strcpy(resultDoubleToBinary64StringType,
               "0111111111110000000000000000000000000000000000000000000000000000");

        goto outPut;
    }

    if (doubleInput == NEGATIVE_INFINITY) {
        strcpy(resultDoubleToBinary64StringType,
               "1111111111110000000000000000000000000000000000000000000000000000");

        goto outPut;
    }

    if (isNaN(doubleInput)) {
        strcpy(resultDoubleToBinary64StringType,
               "0111111111111111111111111111111111111111111111111111111111111111");

        goto outPut;
    }

    /** Get |doubleInput| */
    doubleInput = fabs(doubleInput);

    /** Get size of integerPartNormalizeForm  */
    integerPartDoubleInput = static_cast<int> (floor(doubleInput));
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

    integerPartDoubleInput = static_cast<int> (floor(doubleInput));
    index = sizeOfIntegerPartNormalizeForm - 1;

    while (integerPartDoubleInput != 0) {

        if ((integerPartDoubleInput & 1) == 1) {
            integerPartNormalizeForm[index] = '1';
        }

        if ((integerPartDoubleInput & 1) == 0) {
            integerPartNormalizeForm[index] = '0';
        }

        index--;
        integerPartDoubleInput = integerPartDoubleInput >> 1;
    }

    fractionPartDoubleInput = doubleInput - integerPartDoubleInput;
    index = 0;

    while ((fractionPartDoubleInput != 0) && (index < 53)) {
        fractionPartDoubleInput = fractionPartDoubleInput * 2;

        int integerPart = static_cast<int> (floor(fractionPartDoubleInput));

        if (integerPart == 1) {
            fractionPartNormalizeForm[index] = '1';
        }

        if (integerPart == 0) {
            fractionPartNormalizeForm[index] = '0';
        }

        index++;
        fractionPartDoubleInput = fractionPartDoubleInput - integerPart;
    }

    sizeOfFractionPartNormalizeForm = index;

    /** Copy value from integerPartNormalizeForm to doubleInputNormalizeForm */
    for (i = 0; i < sizeOfIntegerPartNormalizeForm; i++) {
        doubleInputNormalizeForm[i] = integerPartNormalizeForm[i];
    }

    indexOfDotDoubleInputNormalizeForm = sizeOfIntegerPartNormalizeForm;

    doubleInputNormalizeForm[indexOfDotDoubleInputNormalizeForm] = '.';

    /** Copy value from fractionPartNormalizeForm
     * to doubleInputNormalizeForm
     */
    index = indexOfDotDoubleInputNormalizeForm + 1;
    for (i = 0; i <= sizeOfFractionPartNormalizeForm; i++, index++) {
        doubleInputNormalizeForm[index]
                = fractionPartNormalizeForm[i];
    }

    sizeOfDoubleInputNormalizeForm = sizeOfIntegerPartNormalizeForm + 1
                                     + sizeOfFractionPartNormalizeForm;

    /** Assign value to indexFirstBit1DoubleInputNormalizeForm */
    indexFirstBit1DoubleInputNormalizeForm = 1;
    for (i = 0; i <= sizeOfDoubleInputNormalizeForm; i++) {
        if (doubleInputNormalizeForm[i] == '1') {
            indexFirstBit1DoubleInputNormalizeForm = i;
            break;
        }
    }

    integerPartDoubleInput = static_cast<int> (floor(doubleInput));
    if (integerPartDoubleInput != 0) {
        powerExponentBase2 = indexOfDotDoubleInputNormalizeForm
                             - indexFirstBit1DoubleInputNormalizeForm - 1;
    }

    if (integerPartDoubleInput == 0) {
        powerExponentBase2 = indexOfDotDoubleInputNormalizeForm
                             - indexFirstBit1DoubleInputNormalizeForm;
    }

    exponentDoubleInput = powerExponentBase2 + exponentBiasBinary64;

    index = sizeOfExponentPartBinary64;

    while (exponentDoubleInput != 0) {

        if ((exponentDoubleInput & 1) == 1) {
            resultDoubleToBinary64StringType[index] = '1';
        }

        if ((exponentDoubleInput & 1) == 0) {
            resultDoubleToBinary64StringType[index] = '0';
        }

        index--;
        exponentDoubleInput = exponentDoubleInput >> 1;
    }

    indexBeginFractionPartResultDoubleToBinary64StringType
            = sizeOfExponentPartBinary64 + 1;

    index = indexBeginFractionPartResultDoubleToBinary64StringType;
    i = indexFirstBit1DoubleInputNormalizeForm + 1;

    for (index; index <= 63; index++) {
        if (i == sizeOfDoubleInputNormalizeForm) {
            break;
        }

        if (i == indexOfDotDoubleInputNormalizeForm) {
            i++;
        }

        resultDoubleToBinary64StringType[index]
                = doubleInputNormalizeForm[i];
        i++;
    }

    outPut:
    /** Return resultDoubleToBinary64StringType */
    free(integerPartNormalizeForm);
    free(fractionPartNormalizeForm);
    free(doubleInputNormalizeForm);

    String result = resultDoubleToBinary64StringType;
    free(resultDoubleToBinary64StringType);

    return result;
}

double Double::binary64StringTypeToDouble(String binary64StringTypeInput) {
    // Create variable
    int signOfResultbinary64StringTypeToDouble;
    double exponent;
    double exponentAdjusted;
    double mantisaBase10;
    double resultBinary64StringTypeToDouble;

    int tempValue = 0;
    int tempExponent;
    int i;

    boolean isNaN = true;

    // 1. Find signOfResultbinary64StringTypeToDouble
    signOfResultbinary64StringTypeToDouble = 1;

    if (binary64StringTypeInput.charAt(0) == '1') {
        signOfResultbinary64StringTypeToDouble = -1;
    }

    // 2. Convert the exponent from base 2 -> base 10
    exponent = 0;
    tempExponent = 10;
    for (i = 1; i <= 11; i++) {
        if (binary64StringTypeInput.charAt(i) == '1') {
            tempValue = 1;
        }

        if (binary64StringTypeInput.charAt(i) == '0') {
            tempValue = 0;
            isNaN = false;
        }

        exponent = exponent + tempValue * Math::pow(2, tempExponent);
        tempExponent--;
    }
    // 3. Find exponentAdjusted
    exponentAdjusted = exponent - 1023;

    // 4. Convert the mantissa from base 2 -> base 10
    mantisaBase10 = 0;
    tempExponent = -1;
    for (i = 12; i <= 63; i++) {
        if (binary64StringTypeInput.charAt(i) == '1') {
            tempValue = 1;
        }

        if (binary64StringTypeInput.charAt(i) == '0') {
            tempValue = 0;
            isNaN = false;
        }

        mantisaBase10 = mantisaBase10 + tempValue * Math::pow(2, tempExponent);
        tempExponent--;
    }

    // 5. Find the Double precision floating point decimal value
    resultBinary64StringTypeToDouble
            = signOfResultbinary64StringTypeToDouble * (1 + mantisaBase10)
              * Math::pow(2, exponentAdjusted);

    return resultBinary64StringTypeToDouble;
}

String Double::longBitsToBinary64StringType(long longBitsInput) {
    auto resultLongBitsToBinary64StringType = (string) allocateMemory(65 * sizeof(char));
    int index;
    int i;

    for (i = 0; i <= 63; i++) {
        resultLongBitsToBinary64StringType[i] = '0';
    }

    resultLongBitsToBinary64StringType[64] = '\0';

    if (longBitsInput < 0) {
        resultLongBitsToBinary64StringType[0] = '1';
        longBitsInput = -longBitsInput;
    }

    index = 63;
    while ((longBitsInput != 0) || (index > 1)) {
        if ((longBitsInput & 1) == 1) {
            resultLongBitsToBinary64StringType[index] = '1';
        }

        if ((longBitsInput & 1) == 0) {
            resultLongBitsToBinary64StringType[index] = '0';
        }

        index--;
        longBitsInput = longBitsInput >> 1;
    }

    String result = resultLongBitsToBinary64StringType;
    free(resultLongBitsToBinary64StringType);

    return result;
}

Double Double::valueOf(String stringInput) {
    return Double::parseDouble(stringInput);
}

Double Double::valueOf(double doubleInput) {
    return Double(doubleInput);
}
