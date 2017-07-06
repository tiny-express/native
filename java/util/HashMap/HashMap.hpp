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

#include <initializer_list>
#include <iostream>
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
			std::map<K, V> original;
            typedef typename std::map<K, V>::iterator _iterator;
            typedef typename std::map<K, V>::const_iterator _const_iterator;

		public:
			/**
			 * Constructs an empty HashMap
			 */
			HashMap(){}

			/**
			 * Constructs a new HashMap with the same mappings as the specified Map.
			 *
			 * @param const HashMap<K, V> &target - the map whose mappings are to be placed in this map
			 * @throw if the specified map is null
			 */
			HashMap(const HashMap<K, V> &target) {
				this->putAll(target);
			}

			/**
			 * Destructor HashMap
			 */
			~HashMap(){}

		public:
			_iterator begin() {
				return this->original.begin();
			};
			_const_iterator begin() const {
				return this->original.begin();
			};
			_iterator end() {
				return this->original.end();
			};
			_const_iterator end() const {
				return this->original.end();
			};


		public:
			/**
			 * Removes all of the mappings from this map. The map will be empty after this call returns.
			 */
			void clear() {
				this->original.clear();
			}

			/***
			 * Returns a shallow copy of this HashMap instance: the keys and values themselves are not cloned.
			 *
			 * @return HashMap<K, V>
			 */
			HashMap<K, V> clone() const {
				HashMap<K, V> result;
				for (auto const &element: this->original) {
					result.put(element.first, element.second);
				}

				return result;
			};

			/**
			 * Returns true if this map contains a mapping for the specified key.
			 *
			 * @param K key - The key whose presence in this map is to be tested
			 * @return boolean
			 * 	true : if this map contains a mapping for the specified key.
			 * 	false: otherwise
			 */
			boolean containsKey(const K &key) const {
				V value = get(key);
				boolean isNull = ((Nullable *)&value)->isNull();

                if (isNull) {
                    return false;
                }

                return true;
			}

			/**
			 * Returns true if this map maps one or more keys to the specified value.
			 *
			 * @param V value - value whose presence in this map is to be tested
			 * @return boolean
			 *  true : if this map maps one or more keys to the specified value
			 *  false: otherwise
			 */
			boolean containsValue(const V &value) const {
				for (auto const &ent1 : this->original) {
					if (ent1.second == value) {
						return true;
					}
				}
				return false;
			}

			/**
			 * Returns the value to which the specified key is mapped,
			 * or null if this map contains no mapping for the key
			 *
			 * @param K key - the key whose associated value is to be returned
			 * @return V value - the value to which the specified key is mapped, or null if no mapping with key
			 */
			V get(const K &key) const {
				V result;
				auto const it = this->original.find(key);

				if (it == this->original.end()) {
                    ((Nullable *)&result)->setNullable(true);
					return result;
				}

				result = it->second;
                ((Nullable *)&result)->setNullable(false);

				return result;
			}

			/**
			 *  Returns the value to which the specified key is mapped,
			 *  or defaultValue if this map contains no mapping for the key.
			 *
			 * @param K key - the key whose associated value is to be returned
			 * @param V defaultValue - the default mapping of the key
			 * @return V the value to which the specified key is mapped,
			 * or defaultValue if this map contains no mapping for the key
			 */
			V getOrDefault(const K &key, const V &defaultValue) const {
                V result;
                auto const it = this->original.find(key);

                if (it == this->original.end()) {
                    result = defaultValue;
                } else {
                    result = it->second;
                }
                ((Nullable *)&result)->setNullable(false);

                return result;
			}

			/**
			 * Returns true if this map contains no key-value mappings.
			 *
			 * @return boolean
			 *  true : true if this map contains no key-value mappings
			 *  false: otherwise
			 */
			boolean isEmpty() const {
				return ( this->original.size() == 0 );
			}

			/**
			 * Returns a shallow copy of this HashMap instance: the keys and values themselves are not cloned.
			 *
			 * @param const K &key
			 * @param const V &value
			 */
			void put(const K &key, const V &value) {
				this->original.insert(std::make_pair(key, value));
			}

			/**
			 * Copies all of the mappings from the specified map to this map.
			 *
			 * @param const hashMap<K, V> &map
			 */
			void putAll(const HashMap<K, V> &map) {
				for (auto const &element: map) {
                    K key = element.first;
                    V value = element.second;
                    this->original.insert(std::make_pair(key, value));
				}
            }

			/**
			 * Removes the mapping for the specified key from this map if present.
			 *
			 * @param K key - key whose mapping is to be removed from the map
			 * @return V - the previous value associated with key, or null if there was no mapping for key.
			 * (A null return can also indicate that the map previously associated null with key.)
			 */
			V remove(const K &key) {
				V result;
				auto const it = this->original.find(key);

				if (it == this->original.end()) {
					((Nullable *)&result)->setNullable(true);
					return result;
				}

				result = it->second;
                ((Nullable *)&result)->setNullable(false);

				this->original.erase(key);
				return result;
			}

			/**
			 * Removes the entry for the specified key only if it is currently mapped to the specified value.
			 *
			 * @param K key - key with which the specified value is associated
			 * @param V value - value expected to be associated with the specified key
			 * @return boolean
			 * true : if the value was removed
			 * false: if otherwise
			 */
			boolean remove(const K &key, const V &value) {
				auto const it = this->original.find(key);

				if (it == this->original.end() || it->second != value) {
					return false;
				}

				this->original.erase(key);
				return true;
			}

            /**
             * Replaces the entry for the specified key only if it is currently mapped to some value.
             *
             * @param key - key with which the specified value is associated
             * @param value - value to be associated with the specified key
             * @return V - the previous value associated with the specified key,
             * or null if there was no mapping for the key.
             * (A null return can also indicate that the map previously associated null with the key,
             * if the implementation supports null values.)
             */
            V replace(const K &key, const V &value) {
				V result;
				auto const it = this->original.find(key);

				if (it == this->original.end()) {
					((Nullable *)&result)->setNullable(true);
					return result;
				}

				result = it->second;
				((Nullable *)&result)->setNullable(false);

				this->original[key] = value;

				return result;
            }

            /**
             * Replaces the entry for the specified key only if currently mapped to the specified value.
             *
             * @param key - key with which the specified value is associated
             * @param oldValue - value expected to be associated with the specified key
             * @param newValue - value to be associated with the specified key
             * @return boolean
             * true : if the value was replaced
             * false: if otherwise
             */
            boolean replace(const K &key, const V &oldValue, const V &newValue) {
                V result;
                auto const it = this->original.find(key);

                if (it == this->original.end() || it->second != oldValue) {
                    return false;
                }

                this->original[key] = newValue;
                return true;
            }

			/**
			 * Returns the number of key-value mappings in this map.
			 *
			 * @return int
			 */
			int size() const {
				return this->original.size();
			}

            /**
             * Return a presentation of all key/value in this object
             *
             * @return string
             */
            string toString() const {
				if (this->size() == 0) {
					return strdup("{}");
				}

				string builder = strdup("{");

				int sizeCounter = this->size();
				typename std::map<K, V>::const_iterator it;
				for (it = this->original.begin();  it != this->original.end() ; ++it) {
					sizeCounter--;

					if (instanceof<Object>(it->first) && instanceof<Object>(it->second)) {

						string key = ((Object *)&it->first)->toString();
						string value = ((Object *)&it->second)->toString();

						string addCharacter = (string)"";
						if (sizeCounter > 0) {
							addCharacter = (string)", ";
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
