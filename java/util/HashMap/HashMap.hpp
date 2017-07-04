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

#import "../AbstractMap/AbstractMap.hpp"
#import "../Map/Map.hpp"

namespace Java {
	namespace Util {
		template <typename K, typename V>
		class HashMap : public AbstractMap
                    , public virtual Map<K, V>
					, public virtual Cloneable
					, public virtual Serializable
		{
		private:
			std::map<K, V> hashMap;

		public:
			HashMap(){}
			~HashMap(){}

		public:
			/**
			 * Removes all of the mappings from this map.
			 */
			void clear() {
				this->hashMap.clear();
			}

			/***
			 * Returns a shallow copy of this HashMap instance: the keys and values themselves are not cloned.
			 *
			 * @return HashMap<K, V>
			 */
			HashMap<K, V> clone() {
				HashMap<K, V> result;
				for (auto const &element: this->hashMap) {
					result.put(element->first, element.first);
				}

				return result;
			};

			/**
			 * Returns true if this map contains a mapping for the specified key
			 *
			 * @param K key
			 * @return boolean
			 */
			boolean containsKey(K key) {
				if (NULL == get(key)) {
					return false;
				}

				return true;
			}

			/**
			 * Removes all of the mappings from this map.
			 *
			 * @param K key
			 * @return V value
			 */
			V *get(K key) {
				auto const it = this->hashMap.find(key);

				if (it == this->hashMap.end()) {
					return NULL;
				}

				return &(this->hashMap[key]);
			}

			/**
			 * Returns true if this map maps one or more keys to the specified value.
			 *
			 * @param V value
			 * @return boolean
			 */
			boolean containsValue(V value) {
				for (auto const &ent1 : this->hashMap) {
					if (ent1.second == value) {
						return true;
					}
				}
				return false;
			}

			/**
			 * Returns true if this map contains no key-value mappings.
			 *
			 * @return boolean
			 */
			boolean isEmpty() {
				return ( this->hashMap.size() == 0 );
			}

			/**
			 * Returns a shallow copy of this HashMap instance: the keys and values themselves are not cloned.
			 *
			 * @param const K &key
			 * @param const V &value
			 */
			void put(const K &key, const V &value) {
				this->hashMap.insert(std::make_pair(key, value));
			}

			/**
			 * Copies all of the mappings from the specified map to this map.
			 *
			 * @param const hashMap<K, V> &map
			 * @return boolean
			 */
			boolean putAll(const HashMap<K, V> &map) {
                typename std::map<K, V>::iterator it;
                for (it = map.hashMap.begin(); it < map.hashMap.end(); ++it) {
                    K key = it->first;
                    V value = it->value;

                    this->put(key, value);
                }
            }

			/**
			 * Removes the mapping for the specified key from this map if present.
			 *
			 * @param K key
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
			 *
			 * @param K key
			 * @param V value
			 * @return boolean
			 */
			boolean remove(K key, V value) {
				if (NULL == get(key) || !containsValue(value)) {
					return false;
				}

				this->hashMap.erase(key);
				return true;
			}

			/**
			 * Returns the number of key-value mappings in this map.
			 *
			 * @return int
			 */
			int size() {
				return this->hashMap.size();
			}

            /**
             * Return a presentation of all key/value in this object
             *
             * @return string
             */
            string toString() {
				if (this->size() == 0) {
					return strdup("{}");
				}

				string builder = strdup("{");
				int sizeCounter = this->size();
				typename std::map<K, V>::iterator it;

				for (it = this->hashMap.begin();  it != this->hashMap.end() ; ++it) {
					sizeCounter--;

					if (instanceof<Object>(it->second)) {
						string key = (string)it->first;
						string value = ((Object *)this->get(key))->toString();

                        string addCharacter = "";
                        if (sizeCounter > 0) {
                            addCharacter = ", ";
                        }

						string holder = builder;
						asprintf(&builder, "%s%s=%s%s\0", builder, key, value, addCharacter);
                        free(holder);
					}
				}

                string holder = builder;
                asprintf(&builder, "%s%c\0", builder, '}');
                free(holder);

				return builder;
            }
		};
		
	}
}

#endif//NATIVE_JAVA_UTIL_HASH_MAP_HPP
