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
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ArNY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef JAVA_LANG_CHAR_SEQUENCE_HPP
#define JAVA_LANG_CHAR_SEQUENCE_HPP

#include "../Object/Object.hpp"

namespace Java {
		namespace Lang {
				class CharSequence {
				public:
						virtual string toString() const = 0;
						/**
						 * Returns the char value at the specified index.  An index ranges from zero
						 * to length() - 1.  The first char value of the sequence is at
						 * index zero, the next at index one, and so on, as for array
						 * indexing.
						 *
						 * If the char value specified by the index is a
						 * "{@docRoot}/java/lang/Character.html#unicode">surrogate, the surrogate
						 * value is returned.
						 *
						 * @param   index   the index of the char value to be returned
						 *
						 * @return  the specified char value
						 *
						 * @throws  IndexOutOfBoundsException
						 *          if the index argument is negative or not less than
						 *          length()
						 */
						virtual char charAt(int index) const = 0;
						
						/**
						 * Returns the length of this character sequence.  The length is the number
						 * of 16-bit <code>char</code>s in the sequence.
						 *
						 * @return  the number of <code>char</code>s in this sequence
						 */
						virtual int length() const = 0;
				};
		}
}

#endif  // JAVA_LANG_CHAR_SEQUENCE_HPP