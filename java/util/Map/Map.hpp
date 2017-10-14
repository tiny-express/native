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

#ifndef NATIVE_JAVA_UTIL_MAP_HPP
#define NATIVE_JAVA_UTIL_MAP_HPP

#include "../../Lang.hpp"
#include "../../util/Set/Set.hpp"
#include "../../util/Comparator/Comparator.hpp"

namespace Java {
		namespace Util {
				
				template <class K, class V>
				class Map {
				
				protected:
						Map() {
						};
						~Map() {
						};
				
				public:
						/**
						 * A map entry (key-value pair). The Map.entrySet method returns a collection-view
						 * of the map, whose elements are of this class. The only way to obtain a reference to
						 * a map entry is from the iterator of this collection-view.
						 * These Map.Entry objects are valid only for the duration of the iteration;
						 * more formally, the behavior of a map entry is undefined
						 * if the backing map has been modified after the entry was returned by the iterator,
						 * except through the setValue operation on the map entry.
						 */
						class Entry {
						private:
								K key;
								V value;
						public:
								/**
								 * Entry constructor
								 *
								 * @param key
								 * @param value
								 */
								Entry(K key, V value) {
									this->key =  key;
									this->value = value;
								}
								
								~Entry() {
								}
								
								/**
								 * Returns a comparator that compares Map.Entry
								 * in natural order on key.
								 *
								 * @return Comparator<Map::Entry<T,F>>
								 */
								Comparator<Map<K, V>::Entry> comparingByKey() {
									Comparator<Map<K, V>::Entry> comparator;
									// TODO - loint@foodtiny.com
									return comparator;
								}
								
								/**
								 * Returns a comparator that compares Map.Entry by key
								 * using the given Comparator.
								 *
								 * @return Comparator<Entry<K,V>>
								 */
								static Comparator<Map<K, V>::Entry> comparingByKey(Comparator<Map<K, V>::Entry> cmp) {
									Comparator<Map<K, V>::Entry> comparator;
									// TODO - loint@foodtiny.com
									return comparator;
								};
								
								/**
								  * Returns a comparator that compares Map.Entry in natural order on value.
								 * @return Comparator<Map::Entry<K,V>>
								 */
								static Comparator<Map<K, V>::Entry> comparingByValue() {
									Comparator<Map<K, V>::Entry> comparator;
									// TODO - loint@foodtiny.com
									return comparator;
								};
								
								/**
								 * Returns a comparator that compares Map.Entry by value
								 * using the given Comparator.
								 *
								 * @return Comparator<Map.Entry<K,V>>
								 */
								Comparator<Map<K, V>::Entry> comparingByValue(Comparator<Map<K, V>::Entry> cmp) {
									Comparator<Map<K, V>::Entry> comparator;
									// TODO - loint@foodtiny.com
									return comparator;
								};
								
								/**
								 * Compares the specified object with this entry for equality.
								 *
								 * @param o
								 * @return boolean
								 */
								boolean equals(Object o) {
									// TODO - loint@foodtiny.com
									return true;
								}
								
								/**
								 * Returns the key corresponding to this entry.
								 *
								 * @return K
								 */
								K getKey() {
									return this->key;
								}
								
								/**
								 * Returns the value corresponding to this entry.
								 *
								 * @return F
								 */
								V getValue() {
									return this->value;
								}
								
								/**
								 * Returns the hash code value for this map entry.
								 *
								 * @return int
								 */
								long hashCode() {
									return 0;
								}
								
								/**
								 * Replaces the value corresponding to this entry
								 * with the specified value (optional operation).
								 *
								 * @param value
								 * @return V
								 */
								V setValue(V value) {
									this->value = value;
								}
								
								boolean operator<(const Map<K, V>::Entry &target) const {
									return true;
								}
						};
						
						/**
						 * Removes all of the mappings from this map (optional operation).
						 */
						void clear() {
						}
						
						/**
						 * Returns true if this map contains a mapping for the specified key.
						 *
						 * @param K key
						 * @return boolean
						 */
						boolean containsKey(const K &key) {
							return true;
						}
						
						/**
						 * Returns true if this map maps one or more keys to the specified value.
						 *
						 * @param V value
						 * @return boolean
						 */
						boolean containsValue(const V &value) {
							return true;
						}
						
						/**
						 * Returns the value to which the specified key is mapped,
						 * or null if this map contains no mapping for the key.
						 *
						 * @param key
						 * @return V
						 */
						V get(const K &key) {
							V v;
							return v;
						}
						
						/**
						 * Returns true if this map contains no key-value mappings.
						 *
						 * @return boolean
						 */
						boolean isEmpty() {
							return false;
						}
						
						/**
						 * Returns the number of key-value mappings in this map.
						 *
						 * @return int
						 */
						int size() {
							return 0;
						}
				};
		}
}

#endif // NATIVE_JAVA_UTIL_MAP_HPP