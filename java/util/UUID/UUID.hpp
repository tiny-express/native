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

#ifndef JAVA_UTIL_UUID_HPP_
#define JAVA_UTIL_UUID_HPP_

#include "../../Lang.hpp"

using namespace Java::Lang;

namespace Java {
		namespace Util {
				class UUID : public Object
//                , public virtual Serializable
//                , public virtual Comparable<UUID>
				{
				
				private:
						long mostSigBits;
						long leastSigBits;
						long timestamp;
				
				private:
						/**
						 * Private constructor which uses a byte array to construct the new UUID.
						 *
						 * @param Array<byte> data
						 * @return UUID
						 */
						UUID(Array<byte> data);
						
						/**
						 * Returns val represented by the specified number of hex digits
						 *
						 * @param long value
						 * @param int digit
						 * @return String
						 */
						static String digits(long value, int digit);
				
				public:
						/**
						 * Default constructor
						 *
						 * @return UUID
						 */
						UUID();
						
						/**
						 * Create new instance this object through most && least significant bits
						 *
						 * @param mostSigBits
						 * @param leastSigBits
						 * @return UUID
						 */
						UUID(long mostSigBits, long leastSigBits);
						
						/**
						 * Default destructor
						 */
						~UUID();
				
				public:
						
						/**
						 * The clock sequence value associated with this UUID.
						 *
						 * @return int - The clock sequence of this UUID
						 */
						int clockSequence();
						/**
						 * Compares this UUID with the specified UUID.
						 *
						 * @param UUID target
						 * @return int
						 *  -1 : if this object less than target either mostSigBits or leastSigBits
						 *  0 : if this object equal both of mostSigBits and leastSigBits
						 *  1 : if this object more than target either mostSigBits or leastSigBits
						 */
						int compareTo(UUID target);
						
						/**
						 * Compares this object to the specified object.
						 *
						 * @param UUID target
						 * @return boolean
						 * true : if the target are same mostSigBits and leastSigBits
						 * false : otherwise
						 */
						boolean equals(UUID target);
						
						/**
						 * Returns the least significant 64 bits of this UUID's 128 bit value.
						 *
						 * @return long
						 */
						long getLeastSignificantBits();
						
						/**
						 * Returns the most significant 64 bits of this UUID's 128 bit value.
						 *
						 * @return long
						 */
						long getMostSignificantBits();
						
						/**
						 * Returns a hash code for this UUID.
						 *
						 * @return int
						 */
						int hashCode();
						
						/**
						 * The node value associated with this UUID.
						 *
						 * @return long
						 */
						long node();
						
						/**
						 * The timestamp value associated with this UUID.
						 *
						 * @return long
						 */
						long getTimestamp();
						
						/**
						 * Returns a String object representing this UUID.
						 *
						 * @return String
						 */
						String toString();
						
						/**
						 * The variant number associated with this UUID.
						 *
						 * @return int
						 */
						int variant();
						
						/**
						 * The version number associated with this UUID.
						 *
						 * @return int
						 */
						int version();
						
						/**
						 * Static factory to retrieve a type 4 (pseudo randomly generated) UUID.
						 *
						 * @return UUID
						 */
						static UUID randomUUID();
						
						/**
						 * Creates a UUID from the string standard representation as described in the toString() method.
						 *
						 * @param String name
						 * @return UUID
						 */
						static UUID fromString(String name);
				};
		}
}


#endif //JAVA_UTIL_UUID_HPP_