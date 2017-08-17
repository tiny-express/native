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

#include "../Base64/Base64.hpp"
#include "../Arrays/Arrays.hpp"
#include "../../lang/IllegalArgumentException/IllegalArgumentException.hpp"

using namespace Java::Util;

const Array<char> Base64::Encoder::toBase64 = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

const Array<char> Base64::Encoder::toBase64Url = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '_'
};

const Array<byte> Base64::Encoder::crlf = { '\r', '\n' };

Base64::Encoder Base64::Encoder::RFC4648
	= Base64::Encoder(false, Array<byte>(), -1, true);

Base64::Encoder Base64::Encoder::RFC4648_URLSAFE
	= Base64::Encoder(true, Array<byte>(), -1, true);

Base64::Encoder Base64::Encoder::RFC2045
	= Base64::Encoder(false, crlf, mimeLineMax, true);

Base64::Encoder::Encoder(boolean isUrl, const Array<byte> &newLine,
	int lineMax, boolean doPadding) {
	this->isUrl = isUrl;
	this->newLine = newLine;
	this->lineMax = lineMax;
	this->doPadding = doPadding;
}

Base64::Encoder::Encoder(const Encoder &source) {
	this->isUrl = source.isUrl;
	this->newLine = source.newLine;
	this->lineMax = source.lineMax;
	this->doPadding = source.doPadding;
}

Base64::Encoder::~Encoder() {
}

Array<byte> Base64::Encoder::encode(const Array<byte> &source) const {
	int length = this->outLength(source.length);
	Array<byte> destination(length);
	int destinationLength = this->encoding(source, 0, source.length, destination);
	if (length != destinationLength) {
		return Arrays::copyOf(destination, destinationLength);
	}
	return destination;
}

int Base64::Encoder::encode(const Array<byte> &source,
	Array<byte> &destination) const {
	int length = this->outLength(source.length);
	if (destination.length < length) {
		throw IllegalArgumentException(
			"Output byte array is too small for encoding all input bytes");
	}
	return this->encoding(source, 0, source.length, destination);
}

String Base64::Encoder::encodeToString(const Array<byte> &source) const {
	Array<byte> encoded = this->encode(source);
	return String(encoded);
}

Base64::Encoder Base64::Encoder::withoutPadding() const {
	if (!doPadding) {
		return *this;
	}
	return Encoder(this->isUrl, this->newLine, this->lineMax, false);
}

int Base64::Encoder::outLength(int sourceLength) const {
	int length = 0;
	
	if (this->doPadding) {
		length = 4 * (( sourceLength + 2 ) / 3 );
	} else {
		int numberOfBytesLeftOver = sourceLength % 3;
		if (numberOfBytesLeftOver == 0) {
			length = 4 * ( sourceLength / 3 );
		} else {
			length = 4 * ( sourceLength / 3 ) + numberOfBytesLeftOver + 1;
		}
	}
	
	if (this->lineMax > 0) {
		length += ( length - 1 ) / this->lineMax * this->newLine.length;
	}
	
	return length;
}

int Base64::Encoder::encoding(const Array<byte> &source, int offset, int end,
	Array<byte> &destination) const {
	Array<char> base64IndexTable;
	if (this->isUrl) {
		base64IndexTable = toBase64Url;
	} else {
		base64IndexTable = toBase64;
	}
	
	int sourcePosition = offset;
	// Because each 3 bytes (24 bits) per block will be processed at a time.
	// If there are only 1 or 2 bytes in a block (at the end), they will be processed later.
	int sourceLength = ( end - offset ) / 3 * 3;
	int sourceStopPosition = offset + sourceLength;
	int destinationPosition = 0;
	
	// Change lineMax (number of base64 digit per line) to equivalent length of source.
	// 4 Base64 digits present for 3 bytes of data.
	int base64LineMaxToEquivalentSourceLength = this->lineMax / 4 * 3;
	// Length of source will be encoded into ONE line of base64 "string" (depending on Base64 scheme).
	int chunksOfSourceLength = sourceLength;  // Doesn't have linemax condition.
	if (this->lineMax > 0 && sourceLength > base64LineMaxToEquivalentSourceLength) {
		chunksOfSourceLength = base64LineMaxToEquivalentSourceLength;
	}
	
	int chunksOfSourceWillBeEncodedPausePosition;
	int chunksOfSourceWillBeEncodedPosition;
	int chunksOfDestinationPosition;
	unsigned int group24Bits;
	while (sourcePosition < sourceStopPosition) {
		chunksOfSourceWillBeEncodedPausePosition =
			Math::min(sourcePosition + chunksOfSourceLength, sourceStopPosition);
		
		for (chunksOfSourceWillBeEncodedPosition = sourcePosition,
			     chunksOfDestinationPosition = destinationPosition;
		     chunksOfSourceWillBeEncodedPosition < chunksOfSourceWillBeEncodedPausePosition;) {
			// Grouping the bits of source into chunks 24 bits (3 bytes).
			group24Bits = static_cast<unsigned int>(
				( source[ chunksOfSourceWillBeEncodedPosition++ ] & 0xff ) << 16 |
				( source[ chunksOfSourceWillBeEncodedPosition++ ] & 0xff ) << 8 |
				( source[ chunksOfSourceWillBeEncodedPosition++ ] & 0xff ));
			
			destination[ chunksOfDestinationPosition++ ] =
				static_cast<byte>(base64IndexTable[ ( group24Bits >> 18 ) & 0x3f ]);
			destination[ chunksOfDestinationPosition++ ] =
				static_cast<byte>(base64IndexTable[ ( group24Bits >> 12 ) & 0x3f ]);
			destination[ chunksOfDestinationPosition++ ] =
				static_cast<byte>(base64IndexTable[ ( group24Bits >> 6 ) & 0x3f ]);
			destination[ chunksOfDestinationPosition++ ] =
				static_cast<byte>(base64IndexTable[ group24Bits & 0x3f ]);
			
			// 4:3 is the ratio of output bytes to input bytes.
			int encodedLength =
				( chunksOfSourceWillBeEncodedPausePosition - sourcePosition ) / 3 * 4;
			destinationPosition += encodedLength;
			sourcePosition = chunksOfSourceWillBeEncodedPausePosition;
			
			// Add bytes of newline to current base64 line (append new line).
			if (encodedLength == lineMax && sourcePosition < end) {
				for (byte byteOfNewLine : this->newLine) {
					destination[ destinationPosition++ ] = byteOfNewLine;
				}
			}
		}
	}
	
	// If there are 1 or 2 bytes left over.
	if (sourcePosition < end) {
		unsigned int firstByte =
			static_cast<unsigned int>(source[ sourcePosition++ ] & 0xff);
		destination[ destinationPosition++ ] =
			static_cast<byte>(base64IndexTable[ firstByte >> 2 ]);
		if (sourcePosition == end) {
			destination[ destinationPosition++ ] =
				static_cast<byte>(base64IndexTable[ ( firstByte << 4 ) & 0X3f ]);
			if (doPadding) {
				destination[ destinationPosition++ ] = '=';
				destination[ destinationPosition++ ] = '=';
			}
		} else {
			unsigned int secondByte =
				static_cast<unsigned int>(source[ sourcePosition++ ] & 0xff);
			destination[ destinationPosition++ ] =
				static_cast<byte>(base64IndexTable[ ( firstByte << 4 ) & 0x3f | ( secondByte >> 4 ) ]);
			destination[ destinationPosition++ ] =
				static_cast<byte>(base64IndexTable[ ( secondByte << 2 ) & 0x3f ]);
			if (doPadding) {
				destination[ destinationPosition++ ] = '=';
			}
		}
	}
	
	return destinationPosition;
}

const Array<int> Base64::Decoder::fromBase64 = [ ]() -> Array<int> {
		Array<int> result(256);
		Arrays::fill(&result, -1);
		int index;
		for (index = 0; index < Encoder::toBase64.length; index++) {
			result[ Encoder::toBase64[ index ]] = index;
		}
		result[ '=' ] = -2;
		return result;
}();

const Array<int> Base64::Decoder::fromBase64Url = [ ]() -> Array<int> {
		Array<int> result(256);
		Arrays::fill(&result, -1);
		int index;
		for (index = 0; index < Encoder::toBase64Url.length; index++) {
			result[ Encoder::toBase64Url[ index ]] = index;
		}
		result[ '=' ] = -2;
		return result;
}();

Base64::Decoder Base64::Decoder::RFC4648 =
	Base64::Decoder(false, false);

Base64::Decoder Base64::Decoder::RFC4648_URLSAFE =
	Base64::Decoder(true, false);

Base64::Decoder Base64::Decoder::RFC2045 =
	Base64::Decoder(false, true);

Base64::Decoder::Decoder(boolean isUrl, boolean isMime) {
	this->isUrl = isUrl;
	this->isMime = isMime;
}

Base64::Decoder::Decoder(const Decoder &source) {
	this->isUrl = source.isUrl;
	this->isMime = source.isMime;
}

Base64::Decoder::~Decoder() {
}

Array<byte> Base64::Decoder::decode(const Array<byte> &source) const {
	int length = this->outLength(source, 0, source.length);
	Array<byte> destination(length);
	int destinationLength = this->decoding(source, 0, source.length, destination);
	if (destinationLength != length) {
		return Arrays::copyOf(destination, destinationLength);
	}
	return destination;
}

int Base64::Decoder::decode(const Array<byte> &source,
	Array<byte> &destination) const {
	int length = this->outLength(source, 0, source.length);
	if (destination.length < length) {
		throw IllegalArgumentException(
			"Output byte array is too small for decoding all input bytes");
	}
	return this->decoding(source, 0, source.length, destination);
}

Array<byte> Base64::Decoder::decode(const String &source) const {
	return this->decode(source.getBytes());
}

int Base64::Decoder::outLength(const Array<byte> &source,
	int offset, int end) const {
	Array<int> fromBase64Table;
	if (this->isUrl) {
		fromBase64Table = fromBase64Url;
	} else {
		fromBase64Table = fromBase64;
	}
	
	int sourcePosition = offset;
	int sourceEndPosition = end;
	int paddingCount = 0;
	int length = sourceEndPosition - sourcePosition;
	if (length == 0) {
		return 0;
	}
	if (length < 2) {
		if (this->isMime && fromBase64Table[ 0 ] == -1) {
			return 0;
		}
		throw IllegalArgumentException(
			"Input byte[] should at least have 2 bytes for based64 bytes");
	}
	if (this->isMime) {
		int nonAlphabet = 0;
		int currentByteDecoded;
		while (sourcePosition < sourceEndPosition) {
			int currentByte = source[ sourcePosition++ ] & 0xff;
			if (currentByte == '=') {
				length -= sourceEndPosition - sourcePosition + 1;
				break;
			}
			currentByteDecoded = source[ currentByte ];
			if (currentByteDecoded == -1) {
				++nonAlphabet;
			}
		}
		length -= nonAlphabet;
	} else {
		if (source[ sourceEndPosition - 1 ] == '=') {
			++paddingCount;
			if (source[ sourceEndPosition - 2 ] == '=') {
				++paddingCount;
			}
		}
	}
	if (paddingCount == 0 && ( length & 0x3 ) != 0) {
		paddingCount = 4 - ( length & 0x3 );
	}
	return 3 * (( length + 3 ) / 4 ) - paddingCount;
}

int Base64::Decoder::decoding(const Array<byte> &source, int offset, int end,
	Array<byte> &destination) const {
	Array<int> fromBase64Table;
	if (this->isUrl) {
		fromBase64Table = fromBase64Url;
	} else {
		fromBase64Table = fromBase64;
	}
	
	int sourcePosition = offset;
	int sourceStopPosition = end;
	int destinationPosition = 0;
	int groupBits = 0;
	// 18 is number of bits (3 sextet) behind first sextet.
	int shiftTo = 18;
	
	int currentByte;
	int currentByteDecoded;
	while (sourcePosition < sourceStopPosition) {
		currentByte = source[ sourcePosition++ ] & 0xff;
		currentByteDecoded = fromBase64Table[ currentByte ];
		if (currentByteDecoded < 0) {  // Means non-Alphabet (CRLF or line separator) or padding '='.
			if (currentByteDecoded == -2) {  // Current byte is '=': padding byte
				if (( shiftTo == 6 )
				    && (( sourcePosition == sourceStopPosition ) ||
				        ( source[ sourcePosition++ ] != '=' ))
				    || ( shiftTo == 18 )) {
					// shiftTo == 18
					// => '=' at wrong position.
					// shiftTo == 6 && sourcePosition == sourceStopPosition
					// => Second '=' is missing.
					// shiftTo == 6 && source[sourcePosition++] != '='
					// => Byte after first '=' doesn't present for '='.
					throw IllegalArgumentException("Input byte array has wrong 4-byte ending unit");
				}
				break;
			}
			
			// If MIME, skip for RFC 2045.
			if (this->isMime) {
				continue;
			} else {
				throw IllegalArgumentException("Illegal base64 character");
			}
		}
		groupBits |= ( currentByteDecoded << shiftTo );
		shiftTo -= 6;
		if (shiftTo < 0) {
			destination[ destinationPosition++ ] = static_cast<byte>(groupBits >> 16);
			destination[ destinationPosition++ ] = static_cast<byte>(groupBits >> 8);
			destination[ destinationPosition++ ] = static_cast<byte>(groupBits);
			shiftTo = 18;
			groupBits = 0;
		}
	}  // end while
	
	// Reach to end of source array or hit padding '=' character.
	if (shiftTo == 6) {
		destination[ destinationPosition++ ] = static_cast<byte>(groupBits >> 16);
	} else if (shiftTo == 0) {
		destination[ destinationPosition++ ] = static_cast<byte>(groupBits >> 16);
		destination[ destinationPosition++ ] = static_cast<byte>(groupBits >> 8);
	} else if (shiftTo == 12) {
		throw IllegalArgumentException("Last unit does not have enough valid bits");
	}
	
	// Anything left is invalid, if is not MIME.
	// If MIME, ignore all none-base64 character.
	while (sourcePosition < sourceStopPosition) {
		if (this->isMime && fromBase64Table[ source[ sourcePosition++ ]] < 0) {
			continue;
		}
		throw IllegalArgumentException(
			"Input byte array has incorrect ending byte at " +
			sourcePosition);
	}
	
	return destinationPosition;
}

Base64::Encoder Base64::getEncoder() {
	return Encoder::RFC4648;
}

Base64::Decoder Base64::getDecoder() {
	return Decoder::RFC4648;
}

Base64::Encoder Base64::getMimeEncoder() {
	return Encoder::RFC2045;
}

Base64::Decoder Base64::getMimeDecoder() {
	return Decoder::RFC2045;
}

Base64::Encoder Base64::getMimeEncoder(int lineLength,
	const Array<byte> &lineSeparator) {
	Array<int> fromBase64Table = Decoder::fromBase64;
	for (byte currentByte : lineSeparator) {
		if (fromBase64Table[ currentByte & 0xff ] != -1) {
			// If currentByte present for alphabet character.
			// Because line separator must NOT contain alphabet character.
			throw IllegalArgumentException("Illegal base64 line separator character");
		}
	}
	if (lineLength < 0) {
		return Encoder::RFC4648;
	}
	// Rounded down to nearest multiple of 4.
	int roundedLineLength = lineLength >> 2 << 2;
	return Encoder(false, lineSeparator, roundedLineLength, true);
}

Base64::Encoder Base64::getUrlEncoder() {
	return Encoder::RFC4648_URLSAFE;
}

Base64::Decoder Base64::getUrlDecoder() {
	return Decoder::RFC4648_URLSAFE;
}
