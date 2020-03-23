/**
 * Copyright 2017-2020 Tiny Express Project. All rights reserved.
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

#ifndef NATIVE_JAVA_UTIL_HASH_MAP_HASH_MAP_HPP
#define NATIVE_JAVA_UTIL_HASH_MAP_HASH_MAP_HPP

#include "../../Lang/String/String.hpp"
#include "../AbstractMap/AbstractMap.hpp"
#include "../Map/Map.hpp"
#include "../Set/Set.hpp"

namespace Java {
    namespace Util {

		template<class K, class V>
		class HashMap :
				public AbstractMap,
				public virtual Map<K, V>,
				public virtual Cloneable,
				public virtual Serializable {

		private:
			std::unordered_map<K, V> original;
			String backup;
			typedef typename std::unordered_map<K, V>::iterator IteratorType;
			typedef typename std::unordered_map<K, V>::const_iterator ConstIteratorType;

		public:
			/**
			 * Constructs an empty HashMap
			 */
			HashMap() = default;

			/**
			 * Constructs a new HashMap with the same
			 * mappings as the specified Map.
			 *
			 * @param target  	the map whose mappings
			 * 					are to be placed in this map
			 */
			HashMap(const HashMap<K, V> &target) {
				this->putAll(target);
			}

			/**
			 * Destructor HashMap
			 */
			~HashMap() = default;

		public:
			/**
			 * @return begin iterator of this object
			 */
			IteratorType begin() {
				return this->original.begin();
			}

			/**
			 * @return const begin iterator of this object
			 */
			ConstIteratorType begin() const {
				return this->original.begin();
			}

			/**
			 * @return end iterator of this object
			 */
			IteratorType end() {
				return this->original.end();
			}

			/**
			 * @return const end iterator of this object
			 */
			ConstIteratorType end() const {
				return this->original.end();
			}

		public:
			/**
			 * Compares the anotherHashMap
			 * with this map for equality.
			 *
			 * @param   anotherHashMap
			 * @return  true if equal
			 *          false if not equal
			 */
			boolean equals(const HashMap<K, V> &anotherHashMap) {
				if (this->size() != anotherHashMap.size()) {
					return false;
				}

				for (var const &thisElement : this->original) {
					V anotherValue = anotherHashMap.get(thisElement.first);
					if (thisElement.second != anotherValue) {
						return false;
					}
				}

				return true;
			}

			/**
			 * Reset to initial default state.
			 * Called by clone and readObject.
			 */
			void reinitialize() {
				std::unordered_map<K, V> newMap;
				this->original = newMap;
			}

			/**
			 * Removes all of the mappings from this map.
			 * The map will be empty after this call returns.
			 */
			void clear() {
				this->original.clear();
			}

			/***
			 * Returns a shallow copy of this HashMap instance:
			 * the keys and values themselves are not cloned.
			 *
			 * @return HashMap<K, V>
			 */
			/***
			 * Returns a shallow copy of this HashMap instance:
			 * the keys and values themselves are not cloned.
			 *
			 * @return HashMap<K, V>
			 */
			HashMap<K, V> clone() const {
				HashMap<K, V> result;
				for (auto const &element : this->original) {
					result.put(element.first, element.second);
				}
				return result;
			}

			/**
			 * Attempts to compute a mapping for the specified key and
			 * its current mapped value (or null if there is no current mapping).
			 *
			 * @param 	key 		key with which the specified value is to be associated
			 *
			 * @param 	BiFunction 	remappingFunction - the function to compute a value
			 *
			 * @return 	V 		the new value associated with the specified key,
			 * 						or null if none
			 */
//			V compute (K key,
//                          BiFunction<void (K, V, V&)>
//                          remappingFunction) {
//                V oldValue = this->get(key);
//                V nullValue;
//                V newValue;
//
//                if (oldValue != nullValue) {
//                    remappingFunction(key, oldValue, newValue);
//
//					if (newValue != nullValue) {
//						this->replace(key, newValue);
//
//						return newValue;
//					}
//
//					this->remove(key);
//                }
//
//                return nullValue;
//            }

			/**
			 * If the specified key is not already associated
			 * with a value (or is mapped to null),
			 * attempts to compute its value using
			 * the given mapping function and enters
			 * iteratorToString into this map unless null.
			 *
			 * @param 	key 		key with which the specified value
			 * 						is to be associated
			 *
			 * @param 	Function 	mappingFunction - the function to compute a value
			 *
			 * @return 	V 		the current (existing or computed) value
			 * 						associated with the specified key,
			 * 						or null if the computed value is null
			 */
//			V computeIfAbsent (K key,
//                                BiFunction<void (K , V, V&)>
//                                mappingFunction) {
//                V oldValue = this->get(key);
//                V nullValue;
//                V newValue;
//
//                if (oldValue != nullValue) {
//                    return oldValue;
//                }
//
//                if (oldValue == nullValue) {
//                    this->remove(key);
//
//                    mappingFunction(key, oldValue, newValue);
//
//                    this->put(key, newValue);
//                    return newValue;
//                }
//            }

			/**
			 * If the value for the specified key is present and non-null,
			 * attempts to compute a new mapping given the key and its current mapped value.
			 *
			 * @param 	key  		key with which the specified value is to be associated
			 *
			 * @param 	BiFunction 	remappingFunction - the function to compute a value
			 *
			 * @return 	V  		the new value associated with the specified key,
			 * 						or null if none
			 */
//            V computeIfPresent (K key,
//                                  BiFunction<void (K , V, V&)>
//                                  mappingFunction) {
//                V oldValue = this->get(key);
//                V nullValue;
//                V newValue;
//
//                if (oldValue == nullValue) {
//                    return nullValue;
//                }
//
//                if (oldValue != nullValue) {
//                    mappingFunction(key, oldValue, newValue);
//
//                    if (newValue != nullValue) {
//                        this->replace(key, newValue);
//
//                        return newValue;
//                    }
//
//                    if (newValue == nullValue) {
//                        this->remove(key);
//                        return nullValue;
//                    }
//                }
//            }

			/**
			 * Returns true if this map contains a mapping for the specified key.
			 *
			 * @param 	key 		The key whose presence in this map is to be tested
			 *
			 * @return 	true  		if this map contains a mapping for the specified key.
			 * 			false 		otherwise
			 */
			boolean containsKey(const K &key) const {
				return this->original.find(key) != this->original.end();
			}

			/**
			 * Returns true if this map maps one or more keys to the specified value.
			 *
			 * @param 	value 		value whose presence in this map is to be tested
			 *
			 * @return 	true  		if this map maps one or more keys to the specified value
			 *  		false 		otherwise
			 */
			boolean containsValue(const V &value) const {
				for (auto const &pair : this->original) {
					if (pair.second == value) {
						return true;
					}
				}
				return false;
			}

			/**
			 *  Set of hash map entries
			 *
			 * @return a set view of the mappings contained in this map
			 */
			Set<class Map<K, V>::Entry> entrySet() {
				Set<class Map<K, V>::Entry> entrySet;

				for (auto const &pair : this->original) {
					class Map<K, V>::Entry entry(pair.first, pair.second);
					entrySet.add(entry);
				}

				return entrySet;
			}

			/**
			 *  Represents an operation that accepts two input arguments and returns no result.
			 *  This is the two-arity specialization of Consumer.
			 *  Unlike most other functional interfaces, BiConsumer is expected to operate via side-effects.
			 *
			 * @param action
			 */
            void forEach(const std::function<boolean(K, V)> &action) const {
                for (auto &pair : this->original) {
                    if (!action(pair.first, pair.second)) {
                        break;
                    }
                }
			}

			/**
			 * Returns the value to which the specified key is mapped,
			 * or default if this map contains no mapping for the key
			 *
			 * @param 	key 			the key whose associated value is to be returned
			 *
			 * @return 	V value 	the value to which the specified key is mapped,
			 * 							or default if no mapping with key
			 */
			V get(const K &key) const {
				auto const iteratorToString = this->original.find(key);
				if (iteratorToString == this->original.end()) {
					// Default value if could not found
					// Prevent null pointer reference
					V value;
				    return value;
				}
				return iteratorToString->second;
			}

			/**
			 *  Returns the value to which the specified key is mapped,
			 *  or defaultValue if this map contains no mapping for the key.
			 *
			 * @param 	key 			the key whose associated value is to be returned
			 *
			 * @param 	defaultValue 	the default mapping of the key
			 *
			 * @return 	V 			the value to which the specified key is mapped,
			 * 							or defaultValue if this map contains no mapping
			 * 							for the key
			 */
			V getOrDefault(const K &key, const V &defaultValue) const {
				V result;
				auto const iteratorToString = this->original.find(key);

				if (iteratorToString == this->original.end()) {
					result = defaultValue;
				} else {
					result = iteratorToString->second;
				}

				return result;
			}

			/**
			 * Returns true if this map contains no key-value mappings.
			 *
			 * @return 	true  	true if this map contains no key-value mappings
			 *  		false 	otherwise
			 */
			boolean isEmpty() const {
				return this->original.size() == 0;
			}

			/**
			 * Returns a shallow copy of this HashMap instance:
			 * the keys and values themselves are not cloned.
			 *
			 * @param key
			 * @param value
			 */
			void put(const K &key, const V &value) {
				this->original.insert(std::pair<K, V>(key, value));
			}

			/**
			 * Copies all of the mappings from the specified map to this map.
			 *
			 * @param const hashMap<K, V> &map
			 */
			void putAll(const HashMap<K, V> &map) {
				for (auto const &element: map) {
				    this->put(element.first, element.second);
				}
			}

			/**
			 * If the specified key is not already associated with a value (or is mapped to null)
			 * associates iteratorToString with the given value and returns null, else returns the current value.
			 *
			 * @param 	key 	key with which the specified value is to be associated
			 *
			 * @param 	value 	value to be associated with the specified key
			 *
			 * @return 	V	the previous value associated with the specified key,
			 * 					or null if there was no mapping for the key.
			 * 					(A null return can also indicate
			 * 					that the map previously associated null with the key,
			 * 					if the implementation supports null values.)
			 */
			V putIfAbsent(const K &key, const V &value) {
				V result;
				auto const iteratorFind = this->original.find(key);

				if (iteratorFind == this->original.end()) {
					this->original[key] = value;
					return result;
				} else {
					result = iteratorFind->second;
				}

				return result;
			}

			/**
			 * Removes the mapping for the specified key from this map if present.
			 *
			 * @param 	key 	key whose mapping is to be removed from the map
			 *
			 * @return 	V 	the previous value associated with key,
			 * 					or null if there was no mapping for key.
			 * 					(A null return can also indicate that the map
			 * 					previously associated null with key.)
			 */
			V remove(const K &key) {
				V result;
				auto const iteratorToString = this->original.find(key);

				if (iteratorToString == this->original.end()) {
					return result;
				}

				result = iteratorToString->second;
				this->original.erase(key);

				return result;
			}

			/**
			 * Removes the entry for the specified key only if iteratorToString is currently mapped to the specified value.
			 *
			 * @param 	key 		key with which the specified value is associated
			 *
			 * @param 	value 		value expected to be associated with the specified key
			 *
			 * @return 	true  		if the value was removed
			 * 			false 		if otherwise
			 */
			boolean remove(const K &key, const V &value) {
				auto const iteratorToString = this->original.find(key);

				if (iteratorToString == this->original.end()
				    || iteratorToString->second != value) {
					return false;
				}

				this->original.erase(key);

				return true;
			}

			/**
			 * Replaces the entry for the specified key only if iteratorToString is currently mapped to some value.
			 *
			 * @param 	key 	key with which the specified value is associated
			 *
			 * @param 	value 	value to be associated with the specified key
			 *
			 * @return 	V 	the previous value associated with the specified key,
			 * 					or null if there was no mapping for the key.
			 * 					(A null return can also indicate that the map
			 * 					previously associated null with the key,
			 * 					if the implementation supports null values.)
			 */
			V replace(const K &key, const V &value) {
				V result;
				auto const iteratorToString = this->original.find(key);

				if (iteratorToString == this->original.end()) {
					return result;
				}

				result = iteratorToString->second;
				this->original[key] = value;

				return result;
			}

			/**
			 * Replaces the entry for the specified key only if currently mapped to the specified value.
			 *
			 * @param 	key 		key with which the specified value is associated
			 *
			 * @param 	oldValue 	value expected to be associated with the specified key
			 *
			 * @param 	newValue 	value to be associated with the specified key
			 *
			 * @return 	true  		if the value was replaced
			 * 			false 		if otherwise
			 */
			boolean replace(const K &key,
			                const V &oldValue,
			                const V &newValue) {
				V result;
				auto const iteratorToString = this->original.find(key);

				if (iteratorToString == this->original.end()
				    || iteratorToString->second != oldValue) {
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
			long size() const {
				return this->original.size();
			}

			/**
			 * Return a presentation of all key/value in this object
			 *
			 * @return string
			 */
			String toString() {
				if (this->size() == 0) {
					this->backup = "{}";
					return this->backup;
				}

				backup = "{";
				String commaAndSpace = ", ";
				String colonAndSpace = ": ";
				String endString = "}";
				String appendKString;
				String appendValueString;

				boolean keyIsString = false;
				boolean valueIsString = false;

				if (std::is_same<K, String>::value) {
					keyIsString = true;
				}

				if (std::is_same<V, String>::value) {
					valueIsString = true;
				}

				long hashMapSize = this->size();
				long hashMapCounter = 0;

				for (var it = this->original.begin(); it != this->original.end(); ++it) {
					hashMapCounter += 1;

					// Concat key string
					appendKString = it->first.toString();
					if (keyIsString) {
						appendKString = String("\"") + appendKString + String("\"");
					}

					appendValueString = it->second.toString();

					// If value is a string
					// then it could be a normal string or serialized array or serialized object
					// so we need to avoid append double quote can lead json format error
					if (valueIsString &&
					    ((appendValueString.length() == 0) ||
					     ((appendValueString[0] != '[') && (appendValueString[0] != '{'))
					    )) {
						appendValueString = String("\"") + appendValueString + String("\"");
					}

					// Do not append comma and space at the last element
					if (hashMapCounter != hashMapSize) {
						appendValueString += commaAndSpace;
					}

					this->backup += appendKString + colonAndSpace + appendValueString;
				}

				this->backup += endString;
				return this->backup;
			}
		};
	}  // namespace Util
}  // namespace Java

#endif // NATIVE_JAVA_UTIL_HASH_MAP_HASH_MAP_HPP
