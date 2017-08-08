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

#ifndef JAVA_LANG_ENUM_HPP_
#define JAVA_LANG_ENUM_HPP_

#include "../String/String.hpp"

namespace Java {
		namespace Lang {
				template <typename E>
				class Enum : public Object
//        , public virtual Comparable<E>
//        , public virtual Serializable
				{
				private:
						String name;
						int ordinal;
				
				public:
						Enum() {
						}
						
						~Enum() {
						}
						
						Enum(String name, int ordinal) {
							this->name = name;
							this->ordinal = ordinal;
						}
				
				public:
						/**
						 * Don't support this method
						 */
						Enum clone() {
							Enum result;
							result.name = this->name;
							result.ordinal = this->ordinal;
							return result;
						}
						
						/**
						 * Make a comparation from this enum to another
						 * @param o
						 * @return int
						 */
						int compareTo(const Enum<E> &e) {
							return this->ordinal - e.ordinal;
						}
						
						/**
						 * Returns the name of this enum constant, exactly as declared in its enum declaration.
						 * @return String
						 */
						String getName() {
							return this->name;
						}
						
						/**
						 * Returns the ordinal of this enumeration constant
						 * (its position in its enum declaration, where the initial constant is assigned an ordinal of zero).
						 * @return int
						 */
						int getOrdinal() {
							return this->ordinal;
						}
						
						/**
						 * Returns the name of this enum constant, as contained in the declaration.
						 * @return String
						 */
						string toString() const {
							return this->name.toString();
						}
				
				public:
						friend std::ostream &operator<<(std::ostream &os, const Enum &target) {
							os << target.toString();
							return os;
						}
				};
		}
}

#endif //JAVA_LANG_ENUM_HPP_