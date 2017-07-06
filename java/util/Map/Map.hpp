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

#include "../../Lang.hpp"

namespace Java {
	namespace Util {
		template <class K, class V>
		class Map {

		protected:
			Map() {};
			virtual ~Map() {};

		public:
			/**
			 * Removes all of the mappings from this map (optional operation).
			 */
			virtual void clear() = 0;

			/**
			 * Returns true if this map contains a mapping for the specified key.
			 *
			 * @param K key
			 * @return boolean
			 */
			virtual boolean containsKey(K key) = 0;

			/**
			 * Returns true if this map maps one or more keys to the specified value.
			 *
			 * @param V value
			 * @return boolean
			 */
			virtual boolean containsValue(V value) = 0;

			/**
			 * Returns the value to which the specified key is mapped,
			 * or null if this map contains no mapping for the key.
			 *
			 * @param key
			 * @return V
			 */
			virtual V *get(K key) = 0;

			/**
			 * Returns true if this map contains no key-value mappings.
			 *
			 * @return boolean
			 */
			virtual boolean isEmpty() = 0;

			/**
			 * Returns the number of key-value mappings in this map.
			 *
			 * @return int
			 */
			virtual int size() = 0;

		};
	}
}