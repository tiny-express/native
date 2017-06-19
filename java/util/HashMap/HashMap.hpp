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

#ifndef NATIVE_JAVA_UTIL_HASH_MAP_HPP
#define NATIVE_JAVA_UTIL_HASH_MAP_HPP

#include "../../lang/Object/Object.hpp"

namespace Java {
	namespace Util {
		template <typename K, typename V>
		class HashMap
//					: public HashMap
//					, public virtual Map
//					, public virtual Cloneable
//					, public virtual Serializable
		{
		private:
			std::map<K, V> hashMap;

		public:
			HashMap(){}
			~HashMap(){}

		public:
			/**
			 * Removes all of the mappings from this map.
			 * @param key
			 * @return V
			 */
			V *get(K key) {
				auto const it = this->hashMap.find(key);

				if (it == this->hashMap.end()) {
					return NULL;
				}

				return &(this->hashMap[key]);
			}

			/**
			 * Returns a shallow copy of this HashMap instance: the keys and values themselves are not cloned.
			 * @param key
			 * @param value
			 */
			void put(K key, V value) {
				this->hashMap.insert(std::make_pair(key, value));
			}

			/**
			 *C opies all of the mappings from the specified map to this map.
			 * @param key
			 * @return boolean
			 */
//			boolean putAll(HashMap<K, V> map); //FIXME: implement foreach this first

			/**
			 * Returns true if this map contains a mapping for the specified key
			 * @param key
			 * @return boolean
			 */
			boolean containsKey(K key) {
				if (NULL == get(key)) {
					return false;
				}

				return true;
			}

			/**
			 * Returns true if this map maps one or more keys to the specified value.
			 * @param value
			 * @return
			 */
			boolean containsValue(const V value) {
				for (auto const &ent1 : this->hashMap) {
					if (ent1.second == value) {
						return true;
					}
				}
				return false;
			}

			/**
			 * Removes all of the mappings from this map.
			 */
			void clear() {
				this->hashMap.clear();
			}

			/**
			 * Removes the mapping for the specified key from this map if present.
			 * @param key
			 * @return boolean
			 */
			boolean remove(K key) {
				if (NULL == get(key)) {
					return false;
				}

				this->hashMap.erase(key);
				return true;
			}

			/**
			 * Removes the mapping for the specified key & value from this map if present.
			 * @param key
			 * @param value
			 * @return
			 */
			boolean remove(K key, const V value) {
				if (NULL == get(key) || !containsValue(value)) {
					return false;
				}

				this->hashMap.erase(key);
				return true;
			}

			/**
			 * Removes all of the mappings from this map.
			 */
			void removeAll() {
				this->hashMap.clear();
			}

			/**
			 * Returns true if this map contains no key-value mappings.
			 * @return boolean
			 */
			boolean isEmpty() {
				return ( this->hashMap.size() == 0 );
			}

			/**
			 * Returns the number of key-value mappings in this map.
			 * @return int
			 */
			int size() {
				return this->hashMap.size();
			}
		};
		
	}
}

#endif//NATIVE_JAVA_UTIL_HASH_MAP_HPP
