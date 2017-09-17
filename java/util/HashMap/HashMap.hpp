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

#ifndef JAVA_UTIL_HASHMAP_HASHMAP_HPP_
#define JAVA_UTIL_HASHMAP_HASHMAP_HPP_

#include <initializer_list>
#include <iostream>
#include "../../lang/String/String.hpp"
#include "../AbstractMap/AbstractMap.hpp"
#include "../Map/Map.hpp"
#include "../Set/Set.hpp"
#include "../../lang/NullPointerException/NullPointerException.hpp"

namespace Java {
	namespace Util {
		template <class Key, class Value>
		class HashMap :
			public AbstractMap,
			public virtual Map<Key, Value>,
			public virtual Cloneable,
			public virtual Serializable {
		private:
			std::map<Key, Value> original;
			String backup;
			typedef typename std::map<Key, Value>::iterator IteratorType;
			typedef typename std::map<Key, Value>::const_iterator ConstIteratorType;
		public:
			/**
			 * Constructs an empty HashMap
			 */
			HashMap() {
			}

			/**
			 * Constructs a new HashMap with the same mappings as the specified Map.
			 *
			 * @param target  	the map whose mappings
			 * 					are to be placed in this map
			 */
			HashMap(const HashMap<Key, Value> &target) {
				this->putAll(target);
			}

			/**
			 * Destructor HashMap
			 */
			~HashMap() {
			}
		public:
			IteratorType begin() {
				return this->original.begin();
			};

			ConstIteratorType begin() const {
				return this->original.begin();
			};

			IteratorType end() {
				return this->original.end();
			};

			ConstIteratorType end() const {
				return this->original.end();
			};
		public:
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
			 * @return HashMap<Key, Value>
			 */
			HashMap<Key, Value> clone() const {
				HashMap<Key, Value> result;
				for (auto const &element : this->original) {
					result.put(element.first, element.second);
				}
				return result;
			}

            // TODO(thoangminh): Need class BiFunction to implement this method
			/**
			 * Attempts to compute a mapping for the specified key and
			 * its current mapped value (or null if there is no current mapping).
			 *
			 * @param 	key 		key with which the specified value is to be associated
			 * @param 	BiFunction 	remappingFunction - the function to compute a value
			 * @return 	Value 			the new value associated with the specified key,
			 * 						or null if none
			 */
			//Value compute(Key key, BiFunction<? super Key,? super Value,? extends Value> remappingFunction);

            // TODO(thoangminh): Need class BiFunction to implement this method
			/**
			 * If the specified key is not already associated
			 * with a value (or is mapped to null),
			 * attempts to compute its value using
			 * the given mapping function and enters it into this map unless null.
			 *
			 * @param 	key 		key with which the specified value is to be associated
			 * @param 	Function 	mappingFunction - the function to compute a value
			 * @return 	Value 		the current (existing or computed) value
			 * 						associated with the specified key,
			 * 						or null if the computed value is null
			 */
			//Value computeIfAbsent(Key key, Function<? super Key,? extends Value> mappingFunction);

            // TODO(thoangminh): Need class BiFunction to implement this method
			/**
			 * If the value for the specified key is present and non-null,
			 * attempts to compute a new mapping given the key and its current mapped value.
			 *
			 * @param 	Key key  	key with which the specified value is to be associated
			 * @param 	BiFunction 	remappingFunction - the function to compute a value
			 * @return 	Value  		the new value associated with the specified key,
			 * 						or null if none
			 */
			//Value computeIfPresent(Key key, BiFunction<? super Key,? super Value,? extends Value> remappingFunction);

			/**
			 * Returns true if this map contains a mapping for the specified key.
			 *
			 * @param 	Key key 		The key whose presence in this map is to be tested
			 * @return 	true  		if this map contains a mapping for the specified key.
			 * 			false 		otherwise
			 */
			boolean containsKey(const Key &key) const {
				return this->original.find(key) != this->original.end();
			}

			/**
			 * Returns true if this map maps one or more keys to the specified value.
			 *
			 * @param 	Value value 	value whose presence in this map is to be tested
			 * @return 	true  		if this map maps one or more keys to the specified value
			 *  		false 		otherwise
			 */
			boolean containsValue(const Value &value) const {
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
			 * @return Set<Map.Entry<Key,Value>> - a set view of the mappings contained in this map
			 */
			Set<class Map<Key, Value>::Entry> entrySet() {
				Set<class Map<Key, Value>::Entry> entrySet;

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
			//void forEach(BiConsumer<? super Key,? super Value> action);

			/**
			 * Returns the value to which the specified key is mapped,
			 * or null if this map contains no mapping for the key
			 *
			 * @param 	Key key 		the key whose associated value is to be returned
			 * @return 	Value value 	the value to which the specified key is mapped,
			 * 						or null if no mapping with key
			 */
			Value get(const Key &key) const {
				Value result;
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
			 * @param 	key 			the key whose associated value is to be returned
			 * @param 	defaultValue 	the default mapping of the key
			 * @return 	Value 			the value to which the specified key is mapped,
			 * 							or defaultValue if this map contains no mapping
			 * 							for the key
			 */
			Value getOrDefault(const Key &key, const Value &defaultValue) const {
				Value result;
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
			 * @return 	true : 	true if this map contains no key-value mappings
			 *  		false: 	otherwise
			 */
			boolean isEmpty() const {
				return this->original.size() == 0;
			}

            // TODO(thoangminh): Support this method later
			/**
			 * Returns a Set view of the keys contained in this map
			 * @return Set<Key> - a set view of the keys contained in this map
			 */
			//Set<Key> keySet();

			/**
			 * Don't support this method
			 *
			 * If the specified key is not already associated with a value or is associated with null,
			 * associates it with the given non-null value.
			 *
			 * @param 	Key key 		key with which the resulting value is to be associated
			 * @param 	value 		the non-null value to be merged with the
			 * 						existing value associated with the key or,
			 * 						if no existing value or a null value
			 * 						is associated with the key, to be associated with the key
			 * @param 	BiFunction 	remappingFunction - the function to recompute
			 * 						a value if present
			 * @return 	Value 			the new value associated with the specified key,
			 * 						or null if no value is associated with the key
			 */
			//Value merge(Key key, Value value, BiFunction<? super Value,? super Value,? extends Value> remappingFunction);

			/**
			 * Returns a shallow copy of this HashMap instance:
			 * the keys and values themselves are not cloned.
			 *
			 * @param key
			 * @param value
			 */
			void put(const Key &key, const Value &value) {
				this->original.insert(std::make_pair(key, value));
			}

			/**
			 * Copies all of the mappings from the specified map to this map.
			 *
			 * @param const hashMap<Key, Value> &map
			 */
			void putAll(const HashMap<Key, Value> &map) {
				for (auto const &element: map) {
					Key key = element.first;
					Value value = element.second;
					this->original.insert(std::make_pair(key, value));
				}
			}

			/**
			 * If the specified key is not already associated with a value (or is mapped to null)
			 * associates it with the given value and returns null, else returns the current value.
			 *
			 * @param 	key 	key with which the specified value is to be associated
			 * @param 	value 	value to be associated with the specified key
			 * @return 	Value	the previous value associated with the specified key,
			 * 					or null if there was no mapping for the key.
			 * 					(A null return can also indicate
			 * 					that the map previously associated null with the key,
			 * 					if the implementation supports null values.)
			 */
			Value putIfAbsent(Key key, Value value) {
				Value result;
				auto const iteratorFind = this->original.find(key);

				if (iteratorFind == this->original.end()) {
					this->original[ key ] = value;
					return result;
				} else {
					result = iteratorFind->second;
				}

				return result;
			}

			/**
			 * Removes the mapping for the specified key from this map if present.
			 *
			 * @param 	Key key 	key whose mapping is to be removed from the map
			 * @return 	Value 		the previous value associated with key,
			 * 					or null if there was no mapping for key.
			 * 					(A null return can also indicate that the map
			 * 					previously associated null with key.)
			 */
			Value remove(const Key &key) {
				Value result;
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
			 * @param 	Key key 		key with which the specified value is associated
			 * @param 	Value value 	value expected to be associated with the specified key
			 * @return 	boolean
			 * 			true : 		if the value was removed
			 * 			false: 		if otherwise
			 */
			boolean remove(const Key &key, const Value &value) {
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
			 * @param 	key 	key with which the specified value is associated
			 * @param 	value 	value to be associated with the specified key
			 * @return 	Value 		the previous value associated with the specified key,
			 * 					or null if there was no mapping for the key.
			 * 					(A null return can also indicate that the map
			 * 					previously associated null with the key,
			 * 					if the implementation supports null values.)
			 */
			Value replace(const Key &key, const Value &value) {
				Value result;
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
			 * @param 	key 		key with which the specified value is associated
			 * @param 	oldValue 	value expected to be associated with the specified key
			 * @param 	newValue 	value to be associated with the specified key
			 * @return 	boolean
			 * 			true : 		if the value was replaced
			 * 			false: 		if otherwise
			 */
			boolean replace(const Key &key, const Value &oldValue, const Value &newValue) {
				Value result;
				auto const it = this->original.find(key);

				if (it == this->original.end() || it->second != oldValue) {
					return false;
				}

				this->original[ key ] = newValue;

				return true;
			}

			/**
			 * Don't support this method
			 * Instead use: void replaceAll(const Value &value)
			 */
			//void replaceAll(BiFunction<? super Key,? super Value,? extends Value> function);

			/**
			 * Replace all key inside this instance with the specified value
			 *
			 * @param Value value - value that will be assigned for all key
			 */
			void replaceAll(const Value &value) {
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

            // TODO(thoangminh): Support this method later
			/**
			 * Returns a Collection view of the values contained in this map
			 * @return Collection<Value> - a view of the values contained in this map
			 */
			//Collection<Value> values();

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

				typename std::map<Key, Value>::iterator it;

				for (it = this->original.begin(); it != this->original.end(); ++it) {

					if (instanceof<String>(it->first)) {
						totalString = String("\"") + it->first.toString() + String("\"");
					} else {
						totalString = it->first.toString();
					}

					totalString += colonAndSpace;

					if (instanceof<String>(it->second)) {
						totalString += String("\"") + it->second.toString() + String("\"");
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
	}  // namespace Java
}  // namespace Util

#endif  // JAVA_UTIL_HASHMAP_HASHMAP_HPP_
