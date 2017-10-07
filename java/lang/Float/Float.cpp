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

#include "Float.hpp"
#include "../Math/Math.hpp"

using namespace Java::Lang;

Float::Float() {
    this->original = 0;
    this->originalString = stringFromFloat(this->original);
}

Float::Float(float original) {
    this->original = original;
    this->originalString = stringFromFloat(this->original);
}

Float::Float(const Float &floatNumber) {
    this->original = floatNumber.original;
    this->originalString = stringFromFloat(this->original);
}

Float::Float(String inputString) {
    this->original = this->parseFloat(inputString).floatValue();
    this->originalString = stringFromFloat(this->original);
}

Float::~Float() {
    if (this->originalString != NULL) {
        free(this->originalString);
    }
}

Float Float::operator+(const Float &target) {
    return Float(this->original + target.original);
}

Float Float::operator-(const Float &target) {
    return Float(this->original - target.original);
}

Float Float::operator*(const Float &target) {
    return Float( this->original * target.original );
}

Float Float::operator/(const Float &target) {
    return Float( this->original / target.original );
}

boolean Float::operator==(const Float &target) const {
    return (boolean) equals(target.original);
}

boolean Float::operator!=(const Float &target) const {
    return (boolean) !equals(target.original);
}

boolean Float::operator<(const Float &target) const {
    return (boolean) (compare(this->floatValue(), target.floatValue()) == -1);
}

boolean Float::operator>(const Float &target) const {
    return (boolean) (compare(this->floatValue(), target.floatValue()) == 1);
}

boolean Float::operator>=(const Float &target) const {
    boolean isGreater = compare(this->floatValue(), target.floatValue()) == 1;
    boolean isEqual = compare(this->floatValue(), target.floatValue()) == 0;

    return  (boolean) (isEqual || isGreater);
}

boolean Float::operator<=(const Float &target) const {
    boolean isLess = compare(this->floatValue(), target.floatValue()) == -1;
    boolean isEqual = compare(this->floatValue(), target.floatValue()) == 0;

    return  (boolean) (isLess || isEqual);
}

boolean Float::operator&&(const Float &target) const {
    return (boolean) (this->original && target.original);
}

boolean Float::operator||(const Float &target) const {
    return (boolean) (this->original || target.original);
}

Float& Float::operator=(const Float &target) {
    this->original = target.original;
    free(this->originalString);
    this->originalString = stringFromFloat(this->original);
    return *this;
}

Float Float::operator+=(const Float &target) const {
    return (Float) (this->original + target.original);
}

Float Float::operator-=(const Float &target) const {
    return (Float) (this->original - target.original);
}

Float Float::operator*=(const Float &target) const {
    return (Float) (this->original * target.original);
}

Float Float::operator/=(const Float &target) const {
    return (Float) (this->original / target.original);
}

float Float::floatValue() const {
    return this->original;
}

short Float::shortValue() const {
    return (short) this->original;
}

int Float::intValue() const {
    return (int) this->original;
}

long Float::longValue() const {
    return (long) this->original;
}

double Float::doubleValue() const {
    return (double) this->original;
}

byte Float::byteValue() const {
    return (byte) this->original;
}

string Float::toString() const {
    return this->originalString;
}

Float Float::parseFloat(String inputString) {
    return (Float) stringToFloat(inputString.toString());
}

boolean Float::isFinite(float valueFloat) {
    return (Math::abs(valueFloat) <= Float::MAX_VALUE);
}

boolean Float::isInfinite(float valueFloat) {
    boolean isPOSITIVE_INFINITY = (valueFloat == Float::POSITIVE_INFINITY);
    boolean isNEGATIVE_INFINITY = (valueFloat == Float::NEGATIVE_INFINITY);
    return (isPOSITIVE_INFINITY || isNEGATIVE_INFINITY) ;
}

boolean Float::isInfinite() {
    return Float::isInfinite(this->original);
}

boolean Float::isNaN(float valueFloat) {
    return (valueFloat != valueFloat);
}

boolean Float::isNaN() {
    return Float::isNaN(this->original);
}

Float Float::valueOf(String stringInput) {
    return Float::parseFloat(stringInput);
}

Float Float::valueOf(float inputFloat) {
    return Float(inputFloat);
}

String Float::floatToBinary32StringType(float floatInput) {
    string integerPartNormalizeForm = (string) calloc (280, sizeof(char));
    string fractionPartNormalizeForm = (string) calloc (25, sizeof(char));
    string floatInputNormalizeForm = (string) calloc (280, sizeof(char));
    string resultFloatToBinary32StringType
            = (string) calloc (33, sizeof(char));

    int powerExponentBase2 = 0;
    int integerPartFloatInput;

    int sizeOfIntegerPartNormalizeForm;
    int sizeOfFractionPartNormalizeForm;
    int sizeOfFloatInputNormalizeForm;

    int sizeOfExponentPartBinary32 = 8;

    int indexOfFor;
    int index;
    int indexOfDotFloatInputNormalizeForm;
    int indexFirstBit1FloatInputNormalizeForm;
    int indexBeginFractionPartResultFloatToBinary32StringType = 0;

    int exponentBiasBinary32 = 127;
    int exponentFloatInput;

    float fractionPartFloatInput;

    for (indexOfFor = 0 ; indexOfFor <= 31; indexOfFor++) {
        floatInputNormalizeForm[indexOfFor] = '0';
        resultFloatToBinary32StringType[indexOfFor] = '0';
    }

    for (indexOfFor = 0 ; indexOfFor <= 23; indexOfFor++) {
        integerPartNormalizeForm[indexOfFor] = '0';
        fractionPartNormalizeForm[indexOfFor] = '0';
    }

    /** Set end point for string type */
    integerPartNormalizeForm[279] = '\0';
    fractionPartNormalizeForm[24] = '\0';
    floatInputNormalizeForm[279] = '\0';
    resultFloatToBinary32StringType[32] = '\0';

    if (floatInput >= 0) {
        resultFloatToBinary32StringType[0] = '0';
    }

    if (floatInput < 0) {
        resultFloatToBinary32StringType[0] = '1';
    }

    if (floatInput == 0) {
        goto outPut;
    }

    if (floatInput == Float::POSITIVE_INFINITY) {
        strcpy(resultFloatToBinary32StringType, "01111111100000000000000000000000");
        goto outPut;
    }

    if (floatInput == Float::NEGATIVE_INFINITY) {
        strcpy(resultFloatToBinary32StringType, "11111111100000000000000000000000");
        goto outPut;
    }

    if (isNaN(floatInput)) {
        strcpy(resultFloatToBinary32StringType, "01111111111111111111111111111111");

        goto outPut;
    }

    /** Get |floatInput| */
    floatInput = fabs(floatInput);

    /** Get size of integerPartNormalizeForm  */
    integerPartFloatInput = (int) floor(floatInput);
    sizeOfIntegerPartNormalizeForm = 0;

    if (integerPartFloatInput == 0) {
        sizeOfIntegerPartNormalizeForm = 1;
    }

    if (integerPartFloatInput != 0) {
        while (integerPartFloatInput != 0) {
            sizeOfIntegerPartNormalizeForm++;
            integerPartFloatInput = integerPartFloatInput >> 1;
        }
    }

    integerPartFloatInput = (int) floor(floatInput);
    index = sizeOfIntegerPartNormalizeForm -1;
    while (integerPartFloatInput != 0) {
        if ((integerPartFloatInput & 1) == 1) {
            integerPartNormalizeForm[index] = '1';
        }

        if ((integerPartFloatInput & 1) == 0) {
            integerPartNormalizeForm[index] = '0';
        }

        index--;
        integerPartFloatInput = integerPartFloatInput >> 1;
    }

    fractionPartFloatInput = floatInput - integerPartFloatInput;
    index = 0;

    while ((fractionPartFloatInput != 0) && (index < 24)) {
        fractionPartFloatInput = fractionPartFloatInput * 2;

        int integerPart = (int) floor(fractionPartFloatInput);

        if (integerPart == 1) {
            fractionPartNormalizeForm[index] = '1';
        }

        if (integerPart == 0) {
            fractionPartNormalizeForm[index] = '0';
        }

        index++;
        fractionPartFloatInput = fractionPartFloatInput - integerPart;
    }

    sizeOfFractionPartNormalizeForm = index;

    /** Copy value from integerPartNormalizeForm to floatInputNormalizeForm */
    for (indexOfFor = 0; indexOfFor < sizeOfIntegerPartNormalizeForm; indexOfFor++) {
        floatInputNormalizeForm[indexOfFor] = integerPartNormalizeForm[indexOfFor];
    }

    indexOfDotFloatInputNormalizeForm = sizeOfIntegerPartNormalizeForm;

    floatInputNormalizeForm[indexOfDotFloatInputNormalizeForm] = '.';

    /** Copy value from fractionPartNormalizeForm
     * to floatInputNormalizeForm
     */
    index = indexOfDotFloatInputNormalizeForm +1;
    for (indexOfFor = 0; indexOfFor <= sizeOfFractionPartNormalizeForm; indexOfFor++, index++) {
        floatInputNormalizeForm[index]
                = fractionPartNormalizeForm[indexOfFor];
    }

    sizeOfFloatInputNormalizeForm = sizeOfIntegerPartNormalizeForm + 1
                                    + sizeOfFractionPartNormalizeForm;

    indexFirstBit1FloatInputNormalizeForm = 1;
    for (indexOfFor = 0; indexOfFor <= sizeOfFloatInputNormalizeForm; indexOfFor++) {
        if (floatInputNormalizeForm[indexOfFor] == '1') {
            indexFirstBit1FloatInputNormalizeForm = indexOfFor;
            break;
        }
    }

    integerPartFloatInput = (int) floor(floatInput);
    if (integerPartFloatInput != 0) {
        powerExponentBase2 = indexOfDotFloatInputNormalizeForm
                             - indexFirstBit1FloatInputNormalizeForm -1;
    }

    if (integerPartFloatInput == 0) {
        powerExponentBase2 = indexOfDotFloatInputNormalizeForm
                             - indexFirstBit1FloatInputNormalizeForm;
    }

    exponentFloatInput = powerExponentBase2 + exponentBiasBinary32;

    index = sizeOfExponentPartBinary32;

    while (exponentFloatInput != 0) {
        if ((exponentFloatInput & 1) == 1) {
            resultFloatToBinary32StringType[index] = '1';
        }

        if ((exponentFloatInput & 1) == 0) {
            resultFloatToBinary32StringType[index] = '0';
        }

        index--;
        exponentFloatInput = exponentFloatInput >> 1;
    }

    indexBeginFractionPartResultFloatToBinary32StringType
            = sizeOfExponentPartBinary32 + 1;

    index = indexBeginFractionPartResultFloatToBinary32StringType;
    indexOfFor = indexFirstBit1FloatInputNormalizeForm + 1;

    for (index ; index <= 31; index++) {
        if (indexOfFor == sizeOfFloatInputNormalizeForm) {
            break;
        }

        if (indexOfFor == indexOfDotFloatInputNormalizeForm) {
            indexOfFor++;
        }

        resultFloatToBinary32StringType[index]
                = floatInputNormalizeForm[indexOfFor];
        indexOfFor++;
    }

    outPut:
    /** Return resultFloatToBinary32StringType */
    free(integerPartNormalizeForm);
    free(fractionPartNormalizeForm);
    free(floatInputNormalizeForm);
    String result = resultFloatToBinary32StringType;
    free(resultFloatToBinary32StringType);

    return  result;
}

float Float::binary32StringTypeToFloat(String binary32StringTypeInput) {
    // Create variable
    int signOfResultbinary32StringTypeToFloat;
    float exponent;
    float exponentAdjusted;
    float mantisaBase10;
    float resultBinary32StringTypeToFloat;

    int tempValue = 0;
    int tempExponent;
    int indexOfFor;

    boolean isNaN = true;

    // 1. Find signOfResultbinary32StringTypeToFloat
    signOfResultbinary32StringTypeToFloat = 1;

    if (binary32StringTypeInput.charAt(0) == '1') {
        signOfResultbinary32StringTypeToFloat = -1;
    }

    // 2. Convert the exponent from base 2 -> base 10
    exponent = 0;
    tempExponent = 7;
    for (indexOfFor = 1; indexOfFor <= 8; indexOfFor++) {
        if (binary32StringTypeInput.charAt(indexOfFor) == '1') {
            tempValue = 1;
        }

        if (binary32StringTypeInput.charAt(indexOfFor) == '0') {
            tempValue = 0;
            isNaN = false;
        }

        exponent = exponent + tempValue * (float) Math::pow(2, tempExponent);
        tempExponent--;
    }
    // 3. Find exponentAdjusted
    exponentAdjusted = exponent - 127;

    // 4. Convert the mantissa from base 2 -> base 10
    mantisaBase10 = 0;
    tempExponent = -1;
    for (indexOfFor = 9; indexOfFor <= 31; indexOfFor++) {
        if (binary32StringTypeInput.charAt(indexOfFor) == '1') {
            tempValue = 1;
        }

        if (binary32StringTypeInput.charAt(indexOfFor) == '0') {
            tempValue = 0;
            isNaN = false;
        }

        mantisaBase10 = mantisaBase10
                        + tempValue * (float) (Math::pow(2, tempExponent));
        tempExponent--;
    }

    // 5. Find the Float precision floating point decimal value
    resultBinary32StringTypeToFloat
            = signOfResultbinary32StringTypeToFloat * (1 + mantisaBase10)
              * (float) (Math::pow(2, exponentAdjusted));

    if (isNaN) {
        return Float::NaN;
    }

    return resultBinary32StringTypeToFloat;
}

int Float::floatToRawIntBits(float floatInput) {
    String floatInputToBinary32StringType;
    int resultFloatToRawIntBits;
    int tempValue;
    int exponent;
    int indexOfFor;

    floatInputToBinary32StringType = floatToBinary32StringType(floatInput);

    exponent = 30;
    tempValue = 0;
    resultFloatToRawIntBits = 0;

    for (indexOfFor = 1; indexOfFor <= 31; indexOfFor++) {
        if (floatInputToBinary32StringType.charAt(indexOfFor) == '1') {
            tempValue = 1;
        }

        if (floatInputToBinary32StringType.charAt(indexOfFor) == '0') {
            tempValue = 0;
        }
        resultFloatToRawIntBits = resultFloatToRawIntBits + tempValue
                                                            * (int) Math::pow(2, exponent);
        exponent--;
    }

    if (floatInputToBinary32StringType.charAt(0) == '1') {
        resultFloatToRawIntBits =  (-1) * resultFloatToRawIntBits;
    }

    return resultFloatToRawIntBits;
}

int Float::floatToIntBits(float inputFloat) {
    return floatToRawIntBits(inputFloat);
}

String Float::intBitsToBinary32StringType(int intBitsInput) {
    string resultIntBitsToBinary32StringType
            = (string) calloc(33, sizeof (char));
    int index;
    int indexOfFor;

    for (indexOfFor = 0; indexOfFor <= 31; indexOfFor++) {
        resultIntBitsToBinary32StringType[indexOfFor] = '0';
    }

    resultIntBitsToBinary32StringType[32] = '\0';

    if (intBitsInput < 0) {
        resultIntBitsToBinary32StringType[0] = '1';
        intBitsInput = -intBitsInput;
    }

    index = 31;
    while ((intBitsInput != 0) || (index > 1)) {

        if ( (intBitsInput & 1) ==1 ) {
            resultIntBitsToBinary32StringType[index] = '1';
        }

        if ( (intBitsInput & 1) == 0 ) {
            resultIntBitsToBinary32StringType[index] = '0';
        }

        index--;
        intBitsInput = intBitsInput >> 1;
    }

    String result = resultIntBitsToBinary32StringType;
    free(resultIntBitsToBinary32StringType);

    return result;
}

int Float::compare(float float1, float float2) {
    int thisBits = Float::floatToIntBits(float1);
    int anotherBits = Float::floatToIntBits(float2);

    if (thisBits == anotherBits) {
        return 0;
    }
    if (thisBits < anotherBits) {
        return -1;
    }

    return 1;
}

int Float::compareTo(const Float &anotherFloat) const {
    return Float::compare(this->original, anotherFloat.original);
}

// TODO(thoangminh): Wait for instanceof<>
boolean Float::equals(const Float &object) const {
    boolean isFloat = instanceof<Float>(object);
    Float* castObjectToFloat = (Float*)&object;
    int floatToIntBitsObject = floatToIntBits(castObjectToFloat->original);
    int floatToIntBitsThis = floatToIntBits(this->original);
    boolean isEqual = (floatToIntBitsObject == floatToIntBitsThis);
    return isEqual;
    // return (isFloat && isEqual);
}

int Float::hashCode(float floatInput) {
    return  floatToIntBits(floatInput);
}

int Float::hashCode() {
    return Float::hashCode(this->original);
}

float Float::min(float numberFloat, float anotherNumberFloat) {
    return Math::min(numberFloat, anotherNumberFloat);
}

float Float::intBitsToFloat(int intBitsInput) {
    float resultIntBitsToFloat;
    String convertIntBitsToBinary32StringType;

    convertIntBitsToBinary32StringType
            = intBitsToBinary32StringType(intBitsInput);

    resultIntBitsToFloat
            = binary32StringTypeToFloat(convertIntBitsToBinary32StringType);

    return  resultIntBitsToFloat;
}

String Float::toString(float inputFloat) {
    return String::valueOf(inputFloat);
}
