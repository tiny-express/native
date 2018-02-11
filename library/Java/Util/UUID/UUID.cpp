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

#include "UUID.hpp"

/**
 * Default constructor
 *
 * @return UUID
 */
UUID::UUID() {
	this->mostSigBits = 0;
	this->leastSigBits = 0;
}

/**
 * Returns val represented by the specified number of hex digits
 *
 * @param long value
 * @param int digit
 * @return String
 */
String UUID::digits(long value, int digit) {
	long longValue = 1L << ( digit * 4 );
	return Long::toHexString(longValue | ( value & ( longValue - 1 ))).getStringFromIndex(1);
}

/**
 * Private constructor which uses a byte array to construct the new UUID.
 *
 * @param Array<byte> data
 * @return UUID
 */
UUID::UUID(Array<byte> data) {
	long mostSigBits = 0;
	long leastSigBits = 0;
	
	int index;
	for (index = 0; index < 8; ++index) {
		mostSigBits = ( mostSigBits << 8 ) | ( data[ index ] & 0xff );
	}
	
	for (index = 8; index < 16; ++index) {
		leastSigBits = ( leastSigBits << 8 ) | ( data[ index ] & 0xff );
	}
	
	this->mostSigBits = mostSigBits;
	this->leastSigBits = leastSigBits;
	this->timestamp = time(0);
}

/**
 * Create new instance this object through most && least significant bits
 *
 * @param mostSigBits
 * @param leastSigBits
 * @return UUID
 */
UUID::UUID(long mostSigBits, long leastSigBits) {
	this->mostSigBits = mostSigBits;
	this->leastSigBits = leastSigBits;
	this->timestamp = time(0);
}

/**
 * Default destructor
 */
UUID::~UUID() {
}

/**
 * The clock sequence value associated with this UUID.
 *
 * @return int - The clock sequence of this UUID
 */
int UUID::clockSequence() {
	if (version() != 1) {
		//FIXME: exception ("Not a time-based UUID");
		return -1;
	}
	
	return (int) (( this->leastSigBits & 0x3FFF000000000000L ) >> 48 );
};

/**
 * Compares this UUID with the specified UUID.
 *
 * @param UUID target
 * @return int
 *  -1 : if this object less than target either mostSigBits or leastSigBits
 *  0 : if this object equal both of mostSigBits and leastSigBits
 *  1 : if this object more than target either mostSigBits or leastSigBits
 */
int UUID::compareTo(UUID target) {
	if (this->mostSigBits < target.mostSigBits) {
		return -1;
	}
	if (this->mostSigBits > target.mostSigBits) {
		return 1;
	}
	if (this->leastSigBits < target.leastSigBits) {
		return -1;
	}
	if (this->leastSigBits > target.leastSigBits) {
		return 1;
	}
	return 0;
}

/**
 * Compares this object to the specified object.
 *
 * @param UUID target
 * @return boolean
 * true : if the target are same mostSigBits and leastSigBits
 * false : otherwise
 */
boolean UUID::equals(UUID target) {
	return ( this->mostSigBits == target.mostSigBits &&
	         this->leastSigBits == target.leastSigBits );
}

/**
 * Returns the least significant 64 bits of this UUID's 128 bit value.
 *
 * @return long
 */
long UUID::getLeastSignificantBits() {
	return this->leastSigBits;
}

/**
 * Returns the most significant 64 bits of this UUID's 128 bit value.
 *
 * @return long
 */
long UUID::getMostSignificantBits() {
	return this->mostSigBits;
}

/**
 * Returns a hash code for this UUID.
 *
 * @return int
 */
int UUID::hashCode() {
	long xorValue = this->mostSigBits ^this->leastSigBits;
	return ((int) ( xorValue >> 32 )) ^ (int) xorValue;
}

/**
 * The node value associated with this UUID.
 *
 * @return long
 */
long UUID::node() {
	if (this->version() != 1) {
		//FIXME: throw an exception here - "Not a time-based UUID"
	}
	
	return this->leastSigBits & 0x0000FFFFFFFFFFFFL;
}

/**
 * The timestamp value associated with this UUID.
 *
 * @return long
 */
long UUID::getTimestamp() {
	return this->timestamp;
}

/**
 * Returns a String object represents value of UUID.
 *
 * @return String
 */
String UUID::toString() {
	// Please improve this function by using String.format
	String uuid;
	uuid = digits(mostSigBits >> 32, 8) + (string) "-";
	uuid += digits(mostSigBits >> 16, 4) + (string) "-";
	uuid += digits(mostSigBits, 4) + (string) "-";
	uuid += digits(leastSigBits >> 48, 4) + (string) "-";
	uuid += digits(leastSigBits, 12);
	return uuid;
}

/**
 * The variant number associated with this UUID.
 *
 * @return int
 */
int UUID::variant() {
	return (int) (( this->leastSigBits >> ( 64 - ( this->leastSigBits >> 62 ))) & ( this->leastSigBits >> 63 ));
}

/**
 * The version number associated with this UUID.
 *
 * @return int
 */
int UUID::version() {
	return (int) (( this->mostSigBits >> 12 ) & 0x0f );
}

/**
 * Static factory to retrieve a type 4 (pseudo randomly generated) UUID.
 *
 * @return UUID
 */
UUID UUID::randomUUID() {
	Array<byte> randomBytes = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	srand(time(0));
	int index;
	for (index = 0; index < 16; ++index) {
		randomBytes[ index ] = (byte) ( random() % 1000000 );
	}
	
	randomBytes[ 6 ] &= 0x0f;  /* clear version        */
	randomBytes[ 6 ] |= 0x40;  /* set to version 4     */
	randomBytes[ 8 ] &= 0x3f;  /* clear variant        */
	randomBytes[ 8 ] |= 0x80;  /* set to IETF variant  */
	return UUID(randomBytes);
}

/**
 * Creates a UUID from the string standard representation as described in the toString() method.
 *
 * @param name
 * @return UUID
 */
UUID UUID::fromString(String name) {
	Array<String> components = name.split("-");
	if (components.length != 5) {
		//FIXME: an exception
		return UUID();
	}
	
	int index;
	for (index = 0; index < 5; ++index) {
		components[ index ] = "0x" + components[ index ];
	}
	
	long mostSigBits = Long::decode(components[ 0 ]).longValue();
	mostSigBits <<= 16;
	mostSigBits |= Long::decode(components[ 1 ]).longValue();
	mostSigBits <<= 16;
	mostSigBits |= Long::decode(components[ 2 ]).longValue();
	
	long leastSigBits = Long::decode(components[ 3 ]).longValue();
	leastSigBits <<= 48;
	leastSigBits |= Long::decode(components[ 4 ]).longValue();
	
	UUID result = UUID(mostSigBits, leastSigBits);
	return result;
};
