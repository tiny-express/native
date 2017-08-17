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
    this->originalString = string_from_float(this->original);
}

Float::Float(float original) {
    this->original = original;
    this->originalString = string_from_float(this->original);
}

Float::Float(const Float &floatNumber) {
    this->original = floatNumber.original;
    this->originalString = string_from_float(this->original);
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
    return (boolean) (this->original == target.original);
}

// TODO(thoangminh): enable after finish method equals , compare
//boolean Float::operator==(const Float &target) const {
//    return (boolean) equals(target.original);
//}
//
//boolean Float::operator!=(const Float &target) const {
//    return (boolean) !equals(target.original);
//}
//
//boolean Float::operator<(const Float &target) const {
//    if (compare(this->doubleValue(), target.doubleValue()) == -1) {
//        return true;
//    }
//    return false;
//}
//
//boolean Float::operator>(const Float &target) const {
//    if (compare(this->doubleValue(), target.doubleValue()) == 1) {
//        return true;
//    }
//    return false;
//}
//
//boolean Float::operator>=(const Float &target) const {
//    if (compare(this->doubleValue(), target.doubleValue()) == 1
//        || compare(this->doubleValue(), target.doubleValue()) == 0) {
//
//        return true;
//    }
//    return false;
//}
//
//boolean Float::operator<=(const Float &target) const {
//
//    if (compare(this->doubleValue(), target.doubleValue()) == -1
//        || compare(this->doubleValue(), target.doubleValue()) == 0) {
//
//        return true;
//    }
//    return false;
//}

boolean Float::operator&&(const Float &target) const {
    return (boolean) (this->original && target.original);
}

boolean Float::operator||(const Float &target) const {
    return (boolean) (this->original || target.original);
}

Float Float::operator=(const Float &target) {
    this->original = target.original;
    free(this->originalString);
    this->originalString = string_from_float(this->original);
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

char Float::charValue() const {
    string convertResult = string_from_float(this->original);
    char charValueResult = string_to_char(convertResult);
    free(convertResult);
    return charValueResult;
}

string Float::stringValue() const {
    return (string) this->toString();
}

float Float::floatValue() const {
    return this->original;
}

short Float::shortValue() const {
    return static_cast<short> (this->original);
}

int Float::intValue() const {
    return static_cast<int> (this->original);
}

long Float::longValue() const {
    return static_cast<long> (this->original);
}

double Float::doubleValue() const {
    return static_cast<double> (this->original);
}

string Float::toString() const {
    return this->originalString;
}

Float Float::parseFloat(String inputString) {
    return static_cast<Float> (string_to_float(inputString.toString()));
}

boolean Float::isFinite(float valueFloat) {
    return (Math::abs(valueFloat) <= MAX_VALUE);
}

boolean Float::isInfinite(float valueFloat) {
    boolean isPOSITIVE_INFINITY = (valueFloat == POSITIVE_INFINITY);
    boolean isNEGATIVE_INFINITY = (valueFloat == NEGATIVE_INFINITY);
    return( isPOSITIVE_INFINITY || isNEGATIVE_INFINITY ) ;
}

boolean Float::isInfinite() {
    return isInfinite(this->original);
}

boolean Float::isNaN(float valueFloat) {
    return (valueFloat != valueFloat);
}

boolean Float::isNaN() {
    return isNaN(this->original);
}

Float Float::valueOf(String stringInput) {
    return Float::parseFloat(stringInput);
}

Float Float::valueOf(float inputFloat) {
    return Float(inputFloat);

}

string Float::floatToBinary32StringType(float floatInput)
{
    auto integerPartNormalizeForm = (string) malloc (280 * sizeof(char));
    auto fractionPartNormalizeForm = (string) malloc (25 * sizeof(char));
    auto floatInputNormalizeForm = (string) malloc (280 * sizeof(char));
    auto resultFloatToBinary32StringType = (string) malloc (33 * sizeof(char));

    int powerExponentBase2 = 0;
    int integerPartFloatInput;

    int sizeOfIntegerPartNormalizeForm;
    int sizeOfFractionPartNormalizeForm;
    int sizeOfFloatInputNormalizeForm;

    int sizeOfExponentPartBinary32 = 8;

    int i;
    int index;
    int indexOfDotFloatInputNormalizeForm;
    int indexFirstBit1FloatInputNormalizeForm;
    int indexBeginFractionPartResultFloatToBinary32StringType = 0;

    int exponentBiasBinary32 = 127;
    int exponentFloatInput;

    float fractionPartFloatInput;

    for (i = 0 ; i <= 31; i++) {
        floatInputNormalizeForm[i] = '0';
        resultFloatToBinary32StringType[i] = '0';
    }

    for (i = 0 ; i <= 23; i++) {
        integerPartNormalizeForm[i] = '0';
        fractionPartNormalizeForm[i] = '0';
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

    if( floatInput == 0 ) {
        goto outPut;
    }

    if( floatInput == POSITIVE_INFINITY ) {
        strcpy(resultFloatToBinary32StringType, "01111111100000000000000000000000");
        goto outPut;
    }

    if( floatInput == NEGATIVE_INFINITY ) {
        strcpy(resultFloatToBinary32StringType, "11111111100000000000000000000000");
        goto outPut;
    }

    if( isNaN(floatInput)){
        strcpy (resultFloatToBinary32StringType,     "01111111111111111111111111111111");

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
    while( integerPartFloatInput != 0 ) {

        if( (integerPartFloatInput & 1) == 1 ) {
            integerPartNormalizeForm[index] = '1';
        }

        if ( (integerPartFloatInput & 1) == 0) {
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
    for( i = 0; i < sizeOfIntegerPartNormalizeForm; i++ ) {
        floatInputNormalizeForm[i] = integerPartNormalizeForm[i];
    }

    indexOfDotFloatInputNormalizeForm = sizeOfIntegerPartNormalizeForm;

    floatInputNormalizeForm[indexOfDotFloatInputNormalizeForm] = '.';

    /** Copy value from fractionPartNormalizeForm
     * to floatInputNormalizeForm
     */
    index = indexOfDotFloatInputNormalizeForm +1;
    for( i = 0; i <= sizeOfFractionPartNormalizeForm; i++, index++ ) {
        floatInputNormalizeForm[index]
                = fractionPartNormalizeForm[i];
    }

    sizeOfFloatInputNormalizeForm = sizeOfIntegerPartNormalizeForm + 1
                                     + sizeOfFractionPartNormalizeForm;

    indexFirstBit1FloatInputNormalizeForm = 1;
    for ( i = 0; i <= sizeOfFloatInputNormalizeForm; i++ ) {
        if (floatInputNormalizeForm[i] == '1') {
            indexFirstBit1FloatInputNormalizeForm = i;
            break;
        }
    }

    integerPartFloatInput =  (int) floor(floatInput);
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
        if ( (exponentFloatInput & 1 ) == 1) {
            resultFloatToBinary32StringType[index] = '1';
        }

        if ( (exponentFloatInput & 1 ) == 0) {
            resultFloatToBinary32StringType[index] = '0';
        }

        index--;
        exponentFloatInput = exponentFloatInput >> 1;
    }

    indexBeginFractionPartResultFloatToBinary32StringType
            = sizeOfExponentPartBinary32 + 1;

    index = indexBeginFractionPartResultFloatToBinary32StringType;
    i = indexFirstBit1FloatInputNormalizeForm + 1;

    for (index ; index <= 31; index++) {
        if (i == sizeOfFloatInputNormalizeForm) {
            break;
        }

        if (i == indexOfDotFloatInputNormalizeForm) {
            i++;
        }

        resultFloatToBinary32StringType[index]
                = floatInputNormalizeForm[i];
        i++;
    }

    outPut:
    /** Return resultFloatToBinary32StringType */
    free(integerPartNormalizeForm);
    free(fractionPartNormalizeForm);
    free(floatInputNormalizeForm);
    return  resultFloatToBinary32StringType;
}

float Float::binary32StringTypeToFloat (string binary32StringTypeInput) {
    // Create variable
    int signOfResultbinary32StringTypeToFloat;
    float exponent;
    float exponentAdjusted;
    float mantisaBase10;
    float resultBinary32StringTypeToFloat;

    int tempValue = 0;
    int tempExponent;
    int i;

    boolean isNaN = true;

    // 1. Find signOfResultbinary32StringTypeToFloat
    signOfResultbinary32StringTypeToFloat = 1;

    if (binary32StringTypeInput[0] == '1') {
        signOfResultbinary32StringTypeToFloat = -1;
    }

    // 2. Convert the exponent from base 2 -> base 10
    exponent = 0;
    tempExponent = 7;
    for (i = 1; i <= 8; i++) {
        if (binary32StringTypeInput[i] == '1') {
            tempValue = 1;
        }

        if (binary32StringTypeInput[i] == '0') {
            tempValue = 0;
            isNaN = false;
        }

        exponent = exponent + tempValue * static_cast<float> (pow(2, tempExponent));
        tempExponent--;
    }
    // 3. Find exponentAdjusted
    exponentAdjusted = exponent - 127;

    // 4. Convert the mantissa from base 2 -> base 10
    mantisaBase10 = 0;
    tempExponent = -1;
    for (i = 9; i <= 31; i++) {
        if (binary32StringTypeInput[i] == '1') {
            tempValue = 1;
        }

        if (binary32StringTypeInput[i] == '0') {
            tempValue = 0;
            isNaN = false;
        }

        mantisaBase10 = mantisaBase10 + tempValue * static_cast<float> (pow(2, tempExponent));
        tempExponent--;
    }

    // 5. Find the Float precision floating point decimal value
    resultBinary32StringTypeToFloat
            = signOfResultbinary32StringTypeToFloat * (1 + mantisaBase10)
              * static_cast<float> (pow(2, exponentAdjusted));

    if(isNaN) {
        return NaN_NUMBER;
    }

    return resultBinary32StringTypeToFloat;
}

int Float::floatToRawIntBits(float floatInput) {
    string floatInputToBinary32StringType;
    int resultFloatToRawIntBits;
    int tempValue;
    int exponent;
    int i;

    floatInputToBinary32StringType = floatToBinary32StringType(floatInput);

    exponent = 30;
    tempValue = 0;
    resultFloatToRawIntBits = 0;

    for (i = 1; i <= 31; i++) {
        if (floatInputToBinary32StringType[i] == '1') {
            tempValue = 1;
        }

        if (floatInputToBinary32StringType[i] == '0') {
            tempValue = 0;
        }
        resultFloatToRawIntBits = resultFloatToRawIntBits + tempValue * (int) pow(2, exponent);
        exponent--;
    }

    if (floatInputToBinary32StringType[0] == '1') {
        resultFloatToRawIntBits =  (-1) * resultFloatToRawIntBits;
    }

    free(floatInputToBinary32StringType);
    return resultFloatToRawIntBits;
}

int Float::floatToIntBits(float inputFloat) {
    return floatToRawIntBits(inputFloat);
}

string Float::intBitsToBinary32StringType(int intBitsInput) {
    string resultLongBitsToBinary32StringType = (string) malloc(33 * sizeof(char));
    int index;
    int i;

    for (i = 0; i <= 31; i++) {
        resultLongBitsToBinary32StringType[i] = '0';
    }

    resultLongBitsToBinary32StringType[32] = '\0';

    if (intBitsInput < 0) {
        resultLongBitsToBinary32StringType[0] = '1';
        intBitsInput = -intBitsInput;
    }

    index = 31;
    while ( (intBitsInput != 0) || (index > 1)) {

        if ( (intBitsInput & 1) ==1 ) {
            resultLongBitsToBinary32StringType[index] = '1';
        }

        if ( (intBitsInput & 1) == 0 ) {
            resultLongBitsToBinary32StringType[index] = '0';
        }

        index--;
        intBitsInput = intBitsInput >> 1;
    }

    return resultLongBitsToBinary32StringType;
}

int Float::compare(float float1, float float2) {
    long thisBits = Float::floatToIntBits(float1);
    long anotherBits = Float::floatToIntBits(float2);

    if (thisBits == anotherBits) {
        return 0;
    }
    if (thisBits < anotherBits) {
        return -1;
    }

    return 1;
}

// TODO(thoangminh): Wait for instanceof<>
boolean Float::equals(const Float &object) const {
    boolean isFloat = instanceof<Float>(object);
    auto castObjectToFloat = (Float*)&object;
    long floatToIntBitsObject = floatToIntBits(castObjectToFloat->original);
    long floatToIntBitsThis = floatToIntBits(this->original);
    boolean isEqual = (floatToIntBitsObject == floatToIntBitsThis);
    return isEqual;
    //return (isFloat && isEqual);
}