/**
 * Copyright (c) 2017 Food Tiny Project. All rights reserved.
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

extern "C" {
#include "../../../kernel/test.h"
}

#include "../Base64/Base64.hpp"
#include "../Arrays/Arrays.hpp"
#include "../../lang/IllegalArgumentException/IllegalArgumentException.hpp"

using namespace Java::Util;

TEST (JavaUtil, Base64BasicEncoder) {
	// Add padding character by default.
	Array<byte> input3Bytes = { 'M', 'a', 'n' };
	Array<byte> input2Bytes = { 'M', 'a' };
	Array<byte> input1Byte = { 'M' };
	
	Base64::Encoder basicEncoder = Base64::getEncoder();  // RFC4648
	
	Array<byte> expectedResultFromInput3Bytes = { 'T', 'W', 'F', 'u' };
	Array<byte> expectedResultFromInput2Bytes = { 'T', 'W', 'E', '=' };
	Array<byte> expectedResultFromInput1Byte = { 'T', 'Q', '=', '=' };
	
	Array<byte> resultFromInput3Bytes = basicEncoder.encode(input3Bytes);
	Array<byte> resultFromInput2Bytes = basicEncoder.encode(input2Bytes);
	Array<byte> resultFromInput1Byte = basicEncoder.encode(input1Byte);
	
	ASSERT_TRUE(Arrays::equals(expectedResultFromInput3Bytes,
	                           resultFromInput3Bytes));
	ASSERT_TRUE(Arrays::equals(expectedResultFromInput2Bytes,
	                           resultFromInput2Bytes));
	ASSERT_TRUE(Arrays::equals(expectedResultFromInput1Byte,
	                           resultFromInput1Byte));
	
	// Without padding character ('=') in result.
	Base64::Encoder basicEncoderWithoutPadding = basicEncoder.withoutPadding();
	Array<byte> expectedResultWithoutPaddingFromInput1Byte = { 'T', 'Q' };
	Array<byte> resultWithoutPaddingFromInput1Byte =
		basicEncoderWithoutPadding.encode(input1Byte);
	ASSERT_TRUE(Arrays::equals(expectedResultWithoutPaddingFromInput1Byte,
	                           resultWithoutPaddingFromInput1Byte));
	
	// Result as a String, not an Array<byte>.
	String stringInput = "Welcome to Vietnam!";
	Array<char> stringInputToArrayOfChar = stringInput.toCharArray();
	Array<byte> stringInputToArrayOfByte;
	for (char element : stringInputToArrayOfChar) {
		stringInputToArrayOfByte.push(static_cast<byte>(element));
	}
	String stringResult = basicEncoder.encodeToString(stringInputToArrayOfByte);
	String expectedStringResult = "V2VsY29tZSB0byBWaWV0bmFtIQ==";
	ASSERT_STR(expectedStringResult.toString(), stringResult.toString());
	
	// Passing output Array<byte> by reference.
	Array<byte> outputByteArrayIsNotEnoughSize(10);  // Not enough size.
	try {
		basicEncoder.encode(stringInputToArrayOfByte, outputByteArrayIsNotEnoughSize);
	} catch (IllegalArgumentException ex) {
		ASSERT_STR("Output byte array is too small for encoding all input bytes",
		           ex.getMessage().toString());
	}
	Array<byte> outputByteArray(100);
	int index;
	for (index = 0; index < outputByteArray.length; index++) {
		// Filling with '*' character.
		outputByteArray[ index ] = '*';
	}
	int realLength = basicEncoder.encode(stringInputToArrayOfByte, outputByteArray);
	Array<byte> expectedResultOfOutputByteArray =
		{ 'V', '2', 'V', 's', 'Y', '2', '9', 't', 'Z', 'S',
		  'B', '0', 'b', 'y', 'B', 'W', 'a', 'W', 'V', '0',
		  'b', 'm', 'F', 't', 'I', 'Q', '=', '=', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' };
	ASSERT_EQUAL(realLength, expectedStringResult.length());
	ASSERT_TRUE(Arrays::equals(expectedResultOfOutputByteArray, outputByteArray));
}

TEST (JavaUtil, Base64UrlSafeEncoder) {
	Array<byte> urlInput = { 'h', 't', 't', 'p', ':', '/', '/',
	                         'w', 'w', 'w', '.',
	                         'f', 'o', 'o', 'd', 't', 'i', 'n', 'y', '.',
	                         'v', 'n', '/',
	                         '~' };
	Base64::Encoder urlEncoder = Base64::getUrlEncoder();  // RFC4648_URLSAFE
	Array<byte> expectedResultFromUrlInput =
		{ 'a', 'H', 'R', '0', 'c', 'D', 'o', 'v', 'L',
		  '3', 'd', '3', 'd', 'y', '5', 'm', 'b', '2',
		  '9', 'k', 'd', 'G', 'l', 'u', 'e', 'S', '5',
		  '2', 'b', 'i', '9', '-' };
	Array<byte> resultFromUrlInput = urlEncoder.encode(urlInput);
	ASSERT_TRUE(Arrays::equals(expectedResultFromUrlInput, resultFromUrlInput));
}

TEST (JavaUitl, Base64MimeEncoder) {
	Array<byte> mimeInput =
		{ 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	Base64::Encoder mimeEncoder = Base64::getMimeEncoder();  // RFC2045
	Array<byte> expectedResultFromMimeInput =
		{ 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', '\r', '\n',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'E', '=' };
	Array<byte> resultFromMimeInput = mimeEncoder.encode(mimeInput);
	
	int maximumNumberOfCharacterOnALine = 76;  // Doesn't sum length of line separator.
	Array<byte> lineSeparator = { '@', '#' };
	Base64::Encoder mimeDecoderWithCustomNewLineSeparator =
		Base64::getMimeEncoder(maximumNumberOfCharacterOnALine, lineSeparator);
	Array<byte> expectedResultFromMimeInputWithCustomNewLineSeparator =
		{ 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', '@', '#',  // '@' at 77, '#' at 88.
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'E', '=' };
	Array<byte> resultFromMimeInputWithCustomNewLineSeparator =
		mimeDecoderWithCustomNewLineSeparator.encode(mimeInput);
	
	ASSERT_TRUE(Arrays::equals(expectedResultFromMimeInput, resultFromMimeInput));
	ASSERT_TRUE(Arrays::equals(expectedResultFromMimeInputWithCustomNewLineSeparator,
	                           resultFromMimeInputWithCustomNewLineSeparator));
}

TEST (JavaUtil, Base64BasicDecoder) {
	// Basic decoder with padding character in input.
	Array<byte> input4BytesWith0BytePadding = { 'T', 'W', 'F', 'u' };
	Array<byte> input4BytesWith1BytePadding = { 'T', 'W', 'E', '=' };
	Array<byte> input4BytesWith2BytesPadding = { 'T', 'Q', '=', '=' };
	
	Base64::Decoder basicDecoder = Base64::getDecoder();  // RFC4648
	
	Array<byte> expectedResultFromInput4BytesWith0BytePadding = { 'M', 'a', 'n' };
	Array<byte> expectedResultFromInput4BytesWith1BytePadding = { 'M', 'a' };
	Array<byte> expectedResultFromInput4BytesWith2BytesPadding = { 'M' };
	
	Array<byte> resultFromInput4BytesWith0BytePadding =
		basicDecoder.decode(input4BytesWith0BytePadding);
	Array<byte> resultFromInput4BytesWith1BytePadding =
		basicDecoder.decode(input4BytesWith1BytePadding);
	Array<byte> resultFromInput4BytesWith2BytesPadding =
		basicDecoder.decode(input4BytesWith2BytesPadding);
	
	ASSERT_TRUE(Arrays::equals(expectedResultFromInput4BytesWith0BytePadding,
	                           resultFromInput4BytesWith0BytePadding));
	ASSERT_TRUE(Arrays::equals(expectedResultFromInput4BytesWith1BytePadding,
	                           resultFromInput4BytesWith1BytePadding));
	ASSERT_TRUE(Arrays::equals(resultFromInput4BytesWith2BytesPadding,
	                           resultFromInput4BytesWith2BytesPadding));
	
	// Basic decoder without padding character '=' in input.
	Array<byte> inputWithoutPadding = { 'T', 'W', 'E' };  // ... with padding {'T', 'W', 'E', '='}
	Array<byte> resultFromInputWithoutPadding =
		basicDecoder.decode(inputWithoutPadding);
	Array<byte> expectedResultFromInputWithoutPadding = { 'M', 'a' };
	ASSERT_TRUE(Arrays::equals(expectedResultFromInputWithoutPadding,
	                           resultFromInputWithoutPadding));
	
	// Passing output Array<byte> by reference.
	Array<byte> inputArray =
		{ 'V', '2', 'V', 's', 'Y', '2', '9', 't', 'Z', 'S',
		  'B', '0', 'b', 'y', 'B', 'W', 'a', 'W', 'V', '0',
		  'b', 'm', 'F', 't', 'I', 'Q', '=', '=' };
	Array<byte> outputArrayNotEnoughSize(10);
	try {
		basicDecoder.decode(inputArray, outputArrayNotEnoughSize);
	} catch (IllegalArgumentException ex) {
		ASSERT_STR("Output byte array is too small for decoding all input bytes",
		           ex.getMessage().toString());
	}
	Array<byte> outputArray(100);
	int index;
	for (index = 0; index < outputArray.length; index++) {
		// Filling with '*'.
		outputArray[ index ] = '*';
	}
	int realLength = basicDecoder.decode(inputArray, outputArray);
	String expectedOutputAsString = "Welcome to Vietnam!";
	Array<byte> expectedOutputArray =
		{ 'W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 't', 'o',
		  ' ', 'V', 'i', 'e', 't', 'n', 'a', 'm', '!', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' };  // "Welcome to Vietnam!"
	ASSERT_EQUAL(expectedOutputAsString.length(), realLength);
	ASSERT_TRUE(Arrays::equals(expectedOutputArray, outputArray));
	
	// Input as String.
	String inputAsString = "V2VsY29tZSB0byBWaWV0bmFtIQ==";
	Array<byte> resultOfInputAsString = basicDecoder.decode(inputAsString);
	Array<byte> expectedResultOfInputAsString =
		{ 'W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 't', 'o',
		  ' ', 'V', 'i', 'e', 't', 'n', 'a', 'm', '!' };  // "Welcome to Vietnam!"
	ASSERT_TRUE(Arrays::equals(expectedResultOfInputAsString,
	                           resultOfInputAsString));
}

TEST (JavaUtil, Base64UrlSafeDecoder) {
	Array<byte> urlInput = { 'a', 'H', 'R', '0', 'c', 'D', 'o', 'v', 'L',
	                         '3', 'd', '3', 'd', 'y', '5', 'm', 'b', '2',
	                         '9', 'k', 'd', 'G', 'l', 'u', 'e', 'S', '5',
	                         '2', 'b', 'i', '9', '-' };
	Base64::Decoder urlDecoder = Base64::getUrlDecoder();  // RFC4648_URLSAFE
	Array<byte> expectedResultFromUrlInput = { 'h', 't', 't', 'p', ':', '/', '/',
	                                           'w', 'w', 'w', '.',
	                                           'f', 'o', 'o', 'd', 't', 'i', 'n', 'y', '.',
	                                           'v', 'n', '/',
	                                           '~' };
	Array<byte> resultFromUrlInput = urlDecoder.decode(urlInput);
	ASSERT_TRUE(Arrays::equals(expectedResultFromUrlInput, resultFromUrlInput));
}

TEST (JavaUtil, Base64MimeDecoder) {
	// Input with "crlf" - "\r\n" as new line separator.
	Array<byte> mimeInput =
		{ 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', '\r', '\n',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'E', '=' };
	// Input with "@#" as new line separator.
	Array<byte> mimeInputWithCustomNewLineSeparator =
		{ 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', '@', '#',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h',
		  'Y', 'W', 'F', 'h', 'Y', 'W', 'F', 'h', 'Y', 'W',
		  'E', '=' };
	
	Base64::Decoder mimeDecoder = Base64::getMimeDecoder();  // RFC2045
	Array<byte> expectedResultFromMimeInput =
		{ 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
		  'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	Array<byte> resultFromMimeInput = mimeDecoder.decode(mimeInput);
	Array<byte> resultFromMimeInputWithCustomNewLineSeparator =
		mimeDecoder.decode(mimeInputWithCustomNewLineSeparator);
	ASSERT_TRUE(Arrays::equals(expectedResultFromMimeInput, resultFromMimeInput));
	ASSERT_TRUE(Arrays::equals(expectedResultFromMimeInput,
	                           resultFromMimeInputWithCustomNewLineSeparator));
}
