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

#ifndef JAVA_UTIL_HASH_MAP_HPP_
#define JAVA_UTIL_HASH_MAP_HPP_

#include <initializer_list>
#include <iostream>
#include "../../lang/String/String.hpp"
#include "../AbstractMap/AbstractMap.hpp"
#include "../Map/Map.hpp"
#include "../Set/Set.hpp"

namespace Java {
		namespace Util {
				template <class K, class V>
				class HashMap :
					public AbstractMap,
					public virtual Map<K, V>,
					public virtual Cloneable,
					public virtual Serializable {
				private:
						std::map<K, V> original;
						String backup;
						typedef typename std::map<K, V>::iterator _iterator;
						typedef typename std::map<K, V>::const_iterator _const_iterator;

				private:
					/**
					 * Replace escape sequence by raw string of that sequence to using in Json
					 *
					 * @param stringToReplace
					 * @return a String with add escape sequence replaced
					 */
					//TODO (anhnt) need String support unicode for unicode character
					String replaceEscapeSequence(const String stringToReplace) {
						int index = 0;
						String replacementString;
						String result;
						while (index < stringToReplace.length()) {
							int charAtIndex = stringToReplace.charAt(index);
							switch (charAtIndex) {
								case '\"':
									replacementString = R"(\")";
									break;
								case '\b':
									replacementString = R"(\b)";
									break;
								case '\f':
									replacementString = R"(\f)";
									break;
								case '\n':
									replacementString = R"(\n)";
									break;
								case '\r':
									replacementString = R"(\r)";
									break;
								case '\t':
									replacementString = R"(\t)";
									break;
								case '\\':
									replacementString = R"(\\)";
									break;
								default:
										string charAtIndexString = string_from_char(charAtIndex);
										replacementString = charAtIndexString;
										free(charAtIndexString);
							}

							result += replacementString;
							index++;
						}

						return result;
					}
				
				public:
						/**
						 * Constructs an empty HashMap
						 */
						HashMap() {
						}
						
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
						~HashMap() {
						}
				
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
							for (auto const &element : this->original) {
								result.put(element.first, element.second);
							}
							return result;
						}
						
						/**
						 * //TODO
						 *
						 * Attempts to compute a mapping for the specified key and
						 * its current mapped value (or null if there is no current mapping).
						 *
						 * @param K key - key with which the specified value is to be associated
						 * @param BiFunction remappingFunction - the function to compute a value
						 * @return V - the new value associated with the specified key, or null if none
						 */
						//V compute(K key, BiFunction<? super K,? super V,? extends V> remappingFunction);
						
						/**
						 * //TODO
						 *
						 * If the specified key is not already associated with a value (or is mapped to null),
						 * attempts to compute its value using the given mapping function and enters it into this map unless null.
						 *
						 * @param key - key with which the specified value is to be associated
						 * @param Function mappingFunction - the function to compute a value
						 * @return V - the current (existing or computed) value associated with the specified key,
						 * or null if the computed value is null
						 */
						//V computeIfAbsent(K key, Function<? super K,? extends V> mappingFunction);
						
						/**
						 * //TODO
						 *
						 * If the value for the specified key is present and non-null,
						 * attempts to compute a new mapping given the key and its current mapped value.
						 *
						 * @param K key - key with which the specified value is to be associated
						 * @param BiFunction remappingFunction - the function to compute a value
						 * @return V - the new value associated with the specified key, or null if none
						 */
						//V computeIfPresent(K key, BiFunction<? super K,? super V,? extends V> remappingFunction);
						
						/**
						 * Returns true if this map contains a mapping for the specified key.
						 *
						 * @param K key - The key whose presence in this map is to be tested
						 * @return boolean
						 * 	true : if this map contains a mapping for the specified key.
						 * 	false: otherwise
						 */
						boolean containsKey(const K &key) const {
							return this->original.find(key) != this->original.end();
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
						 * Returns a Set view of the mappings contained in this map.
						 * @return Set<Map.Entry<K,V>> - a set view of the mappings contained in this map
						 */
						Set<class Map<K, V>::Entry> entrySet() {
							Set<class Map<K, V>::Entry> entrySet;
							for(auto const &pair : this->original) {
								Map<String, String>::Entry entry(pair.first, pair.second);
								entrySet.add(entry);
							}
							return entrySet;
						}
						
						/**
						 * Don't support this method
						 * Instead use: for (auto const &element: hashMap) {}
						 */
						//void forEach(BiConsumer<? super K,? super V> action);
						
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
								return result;
							}
							
							result = it->second;
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
							return this->original.size() == 0;
						}
						
						/**
						 * //TODO
						 *
						 * Returns a Set view of the keys contained in this map
						 * @return Set<K> - a set view of the keys contained in this map
						 */
						//Set<K> keySet();
						
						/**
						 * Don't support this method
						 *
						 * If the specified key is not already associated with a value or is associated with null,
						 * associates it with the given non-null value.
						 *
						 * @param K key - key with which the resulting value is to be associated
						 * @param value - the non-null value to be merged with the existing value associated with the key or,
						 * if no existing value or a null value is associated with the key, to be associated with the key
						 * @param BiFunction remappingFunction - the function to recompute a value if present
						 * @return V - the new value associated with the specified key, or null if no value is associated with the key
						 */
						//V merge(K key, V value, BiFunction<? super V,? super V,? extends V> remappingFunction);
						
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
						 * If the specified key is not already associated with a value (or is mapped to null)
						 * associates it with the given value and returns null, else returns the current value.
						 *
						 * @param key - key with which the specified value is to be associated
						 * @param value - value to be associated with the specified key
						 * @return the previous value associated with the specified key,
						 * or null if there was no mapping for the key. (A null return can also indicate
						 * that the map previously associated null with the key, if the implementation supports null values.)
						 */
						V putIfAbsent(K key, V value) {
							V result;
							auto const it = this->original.find(key);
							
							if (it == this->original.end()) {
								return result;
							} else {
								result = it->second;
							}
							
							this->original[ key ] = value;
							return result;
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
								return result;
							}
							
							result = it->second;
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
								return result;
							}
							result = it->second;
							this->original[ key ] = value;
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
							this->original[ key ] = newValue;
							return true;
						}
						
						/**
						 * Don't support this method
						 * Instead use: void replaceAll(const V &value)
						 */
						//void replaceAll(BiFunction<? super K,? super V,? extends V> function);
						
						/**
						 * Replace all key inside this instance with the spcified value
						 *
						 * @param V value - value that will be assigned for all key
						 */
						void replaceAll(const V &value) {
							for (auto &element: this->original) {
								element.second = value;
							}
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
						 * //TODO
						 *
						 * Returns a Collection view of the values contained in this map
						 * @return Collection<V> - a view of the values contained in this map
						 */
						//Collection<V> values();
						
						/**
						 * Return a presentation of all key/value in this object
						 *
						 * @return string
						 */
						string toString() {
							if (this->size() == 0) {
								this->backup = "{}";
								return this->backup.toString();
							}
							
							String startHashMap = "{";
							String commaAndSpace = ", ";
							String colonAndSpace = ": ";
							String endString = "}";
							String totalString;

							typename std::map<K, V>::iterator it;
							for (it = this->original.begin(); it != this->original.end(); ++it) {
								if (instanceof<String>(it->first)) {
                                    String first = it->first.toString();
                                    String key = this->replaceEscapeSequence(first);
									totalString = String("\"") + key + String("\"");
								} else {
									totalString = it->first.toString();
								}
								totalString += colonAndSpace;
								if (instanceof<String>(it->second)) {
                                    String second = it->second.toString();
                                    String value = this->replaceEscapeSequence(second);
									totalString += String("\"") + value + String("\"");
								} else {
									totalString += it->second.toString();
								}
								totalString += commaAndSpace;
								startHashMap += totalString;
							}
							
							startHashMap = startHashMap.subString(0, startHashMap.getSize() - 2);
							startHashMap += endString;
							this->backup = startHashMap;
							return this->backup.toString();
						}
				};
		}
}

#endif  // JAVA_UTIL_HASH_MAP_HPP_
