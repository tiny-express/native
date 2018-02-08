package Java.Util.HashMap;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.function.BiFunction;

import org.junit.Test;

public class HashMapTest {

	@SuppressWarnings("null")
	@Test
	public void TestHashMapConstructor() {
		boolean thrownException = false;
		String expected;
		String actual;
		
		// Test default constructor
		HashMap<String, Integer> emptyHashMap = null;
		
		try {
			emptyHashMap.isEmpty();
		} catch(NullPointerException exception) {
			thrownException = true;
		}
		assertTrue(thrownException);
		thrownException = true;
	
		// Test copy constructor
		HashMap<String, String> container = new HashMap<String, String> ();
		container.put("sample", "here");
		container.put("key", "value");
		
		HashMap<String, String> hashMap = container;
		
		
		// Test valid size()
		assertEquals(2, hashMap.size());
		assertFalse(hashMap.isEmpty());
		
		// Test valid data between hashMap and container
		expected = container.get("sample");
		actual = hashMap.get("sample");

	    assertFalse(expected.isEmpty());
	    assertFalse(actual.isEmpty());
		assertEquals(expected.toString(), actual.toString());
		
		expected = container.get("key");
		actual= hashMap.get("key");

	    assertFalse(expected.isEmpty());
	    assertFalse(actual.isEmpty());
		assertEquals(expected.toString(), actual.toString());
	}

	@Test
	public void TestHashMapClear() {
		// Given valid hashMap to test clear()
		HashMap<Long, Integer> hashMap = new HashMap<Long, Integer> ();
		hashMap.put((long) 100, 25);
		hashMap.put((long) 500, 123);
		assertEquals(2, hashMap.size());
		
		hashMap.clear();
		assertEquals(0, hashMap.size());
	}

	@Test
	public void TestHashMapClone() {
		String actualKey;
		String expected;
		String actual;
		
		// Create a HashMap to test to test clone()
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("some key", "123");
		hashMap.put("another thing and key", "-44444");
		HashMap<String, String> anotherMap = (HashMap<String, String>) hashMap.clone();
		
		// Test actualKey = "some key" is exist in anotherMap
		actualKey = "some key";
		expected = "123";
		actual = anotherMap.get(actualKey);
		assertEquals(expected.toString(), actual.toString());
		
		// Test actualKey = "another thing and key" is exist in anotherMap
		actualKey = "another thing and key";
		expected = "-44444";
		actual = anotherMap.get(actualKey);
		assertEquals(expected.toString(), actual.toString());
		
		// Test invalid key
		actualKey = "wrong key";
		actual = anotherMap.get(actualKey);
		assertNull(actual);
	}

	@Test
	public void TestHashMaContainsKey() {
		boolean actual;
		
		// Create a HashMap to test
		HashMap<Integer, String> hashMap = new HashMap<Integer, String> ();
		hashMap.put(3, "three");
		hashMap.put(17, "seven teen");
		hashMap.put(-52, "negative fifty two");
		
		// Valid key
		actual = hashMap.containsKey(-52);
		assertTrue(actual);
		
		// Invalid key
		actual = hashMap.containsKey(100);
		assertFalse(actual);
	}

	@Test
	public void TestHashMapContainsValue() {
		boolean actual;
		
		// Create a HashMap to test
		HashMap<String, Double> hashMap = new HashMap<String, Double> ();
		hashMap.put("15.3", 15.3);
		hashMap.put("30.111", 30.111);
		
		// Valid key
		actual = hashMap.containsValue(15.3);
		assertTrue(actual);
		
		// Invalid key
		actual = hashMap.containsValue(30.22);
		assertFalse(actual);
	}
	
//	@Test
//	public void TestHashMapEntrySet() {
//		HashMap<String, String> hashMap = new HashMap<String, String> ();
//		for (int index=1; index<=100; index++) {
//			hashMap.put("Key "+ String.valueOf(index), "Value " + String.valueOf(index));
//		}
//		int counter = 0;
//		Set<class Map<String, String>.Entry> entrySet = hashMap.entrySet();
//		// TODO - loint@foodtiny.com will improve entrySet
//		// then we can put it inside foreach without any performance issue
//		for (Map<String, String>.Entry entry : entrySet) {
//			counter += 1;
//			if (counter == 1) {
//				assertEquals("Key 99", entry.getKey().toString());
//				assertEquals("Value 99", entry.getValue().toString());
//			}
//			if (counter == 2) {
//				assertEquals("Key 98", entry.getKey().toString());
//				assertEquals("Value 98", entry.getValue().toString());
//			}
//		}
//		// Make sure foreach is working
//		assertEquals(100, counter);
//	}

	@Test
	public void TestHashMapGet() {
		String expected;
		String actual;
		
		// Create a HashMap to test
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("key", "value");
		
		// Valid key
		expected = "value";
		actual = hashMap.get("key");
		assertEquals(expected.toString(), actual.toString());		
		
		// Invalid key
		actual = hashMap.get("wrong_key");
		assertNull(actual);
	}

	@Test
	public void TestHashMapIsEmpty() {
		// Create a HashMap to test
		HashMap<String, Float> hashMap = new HashMap<String, Float> ();
		
		// Empty case
		boolean actual = hashMap.isEmpty();
		assertTrue(actual);
		
		// Not empty case
		hashMap.put("some key", (float) 123.33);
		assertFalse(hashMap.isEmpty());
	}

	@Test
	public void TestHashMapPut() {
		String expected;
		String actual;
		
		// Create a HashMap to test
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("abc", "123");
		hashMap.put("some key here", "456");
		
		// Make sure hashMap is not null
		assertEquals(2, hashMap.size());
		
		// Make sure the data is safe
		// Valid key
		expected = "123";
		actual = hashMap.get("abc");
		assertEquals(expected.toString(), actual.toString());
		
		// Valid key
		expected = "456";
		actual = hashMap.get("some key here");
		assertEquals(expected.toString(), actual.toString());		
	}

	@Test
	public void TestHashMapPutAll() {
		// Create a HashMap to test
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("some string", "123");
		hashMap.put("another key", "777");
		hashMap.put("#!@#another", "-123");
		
		// putAll data of hashMap to targetMap
		HashMap<String, String> targetMap = new HashMap<String, String> ();
		targetMap.putAll(hashMap);
		
		// Make sure both are the same size
		assertEquals(hashMap.size(), targetMap.size());
		
		// Make sure both have the same data
		String actualKey = "#!@#another";
		String expected = hashMap.get(actualKey);
		String actual = targetMap.get(actualKey);
		assertEquals(actual.toString(), expected.toString());
		
		actualKey = "some string";
		expected = hashMap.get(actualKey);
		actual = targetMap.get(actualKey);
		assertEquals(actual.toString(), expected.toString());
		
		actualKey = "another key";
		expected = hashMap.get(actualKey);
		actual = targetMap.get(actualKey);
		assertEquals(actual.toString(), expected.toString());
		
		// Invalid case
		actualKey = "some wrong key here";
		expected = hashMap.get(actualKey);
		actual = targetMap.get(actualKey);
		assertNull(expected);
		assertNull(actual);
	}

	@Test
	public void TestHashMapPutIfAbsent() {
		String actualKey;
		String expected;
		String actual; 
		
		// Create a HashMap to test
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("abc", "123");
		
		// Make sure the data is right before test
		actualKey = "abc";
		expected = "123";
		actual = hashMap.get(actualKey);
		assertEquals(expected.toString(), actual.toString());
		
		// Existent key
		expected = "123";
		actual = hashMap.putIfAbsent(actualKey, "other value");
		assertEquals(expected.toString(), actual.toString());
		
		// Valid data inside after putted
		expected = "123";
		actual = hashMap.get(actualKey);
		assertEquals(expected.toString(), actual.toString());
		
		// Non-existent key
		String wrongKey = "wrong key";
		expected = "something here";
		String isSucceedPutIfAbsent = hashMap.putIfAbsent(wrongKey, "something here");
		actual = hashMap.get(wrongKey);
		assertNull(isSucceedPutIfAbsent);
		assertEquals(expected.toString(), actual.toString());
	}

	@Test
	public void TestHashMapRemoveKey() {
		// Create a HashMap to test
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("some key", "!@#!@#");
		hashMap.put("another key", "1111");
		
		// Make sure the size is right
		assertEquals(2, hashMap.size());		
		
		// Make sure the data is right
		String expected = "1111";
		String actual = hashMap.get("another key");
		assertEquals(expected.toString(), actual.toString());
		
		// Data must be removed after removing
		String isSucceedRemove = hashMap.remove("another key");
		expected = "1111";
		assertEquals(expected.toString(), isSucceedRemove.toString());
		
		// Size must decrease after removing
		assertEquals(1, hashMap.size());
		
		// Make sure the old data must not exist any more
		actual = hashMap.get("another key");
		assertNull(actual);
	}

	@Test
	public void TestHashMapRemoveKeyValue() {
		// Create a HashMap to test
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("some key", "123");
		hashMap.put("another key", "456");
		
		// Make sure the size is right before removing
		assertEquals(2, hashMap.size());
		
		// Make sure the data is right before removing
		String expectedactual = "123";
		String actual = hashMap.get("some key");
		assertEquals(expectedactual.toString(), actual.toString());
		
		// Invalid case: right case, wrong value
		boolean isSucceedRemove = hashMap.remove("some key", "456");
		assertFalse(isSucceedRemove);
		
		// Test remove true by key mapped to specified value
		isSucceedRemove = hashMap.remove("some key", "123");
		assertTrue(isSucceedRemove);
	}

	@Test
	public void TestHashMapReplace() {
		// Create a HashMap to test to test
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("some key", "value");
		hashMap.put("key !@#", "1000");
		hashMap.put(".;;',", "ab232");
		
		// Make sure the data is right before replacing
		String actualKey = ".;;',";
		String expected = "ab232";
		String actual = hashMap.get(actualKey);
		assertEquals(expected.toString(), actual.toString());
		
		// Replace the oldValue
		String oldValue = "ab232";
		String newValue = "250008";
		String replaceactual = hashMap.replace(actualKey, newValue);
		assertEquals(oldValue.toString(), replaceactual.toString());
		
		// Make sure the old value is replaced by new value 
		expected = newValue;
		actual = hashMap.get(actualKey);
		assertEquals(expected.toString(), actual.toString());
	}

	@Test
	public void TestHashMapReplaceSpecifiedValue() {
		// Create a HashMap to test to test
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("some key", "123");
		hashMap.put("key123", "!@#");
		
		// Make sure the size is right
		assertEquals(2, hashMap.size());
		
		// Make sure the data is right
		String actualKey = "key123";
		String expected = "!@#";
		String actual = hashMap.get(actualKey);
		assertEquals(expected.toString(), actual.toString());
		
		// Replace the old value
		String key = "key123";
		String oldValue = "!@#";
		String newValue = "456";
		boolean isSucceedReplace = hashMap.replace(key, oldValue, newValue);
		assertTrue(isSucceedReplace);
		
		// Make sure the old value is replace by new value
		actual = hashMap.get(key);
		assertEquals(newValue.toString(), actual.toString());
		
		// Replace with incorrect key/oldValue
		key = "some key";
		oldValue = "wrong value";
		newValue = "newValue";
		isSucceedReplace = hashMap.replace(key, oldValue, newValue);
		assertFalse(isSucceedReplace);
		
		// Make sure the value is not change if replacing is failed
		key = "some key";
		oldValue = "123";
		actual = hashMap.get(key);
		assertEquals(oldValue.toString(), actual.toString());
	}

	@Test
	public void TestHashMapReplaceAll() {
		// Create a HashMap to test
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("key1", "1000");
		hashMap.put("key2", "2000");
		
		// Make sure the data is right before test
		String expected = "1000";
		String actual = hashMap.get("key1");
		assertEquals(expected.toString(), actual.toString());
		
		expected = "2000";
		actual = hashMap.get("key2");
		assertEquals(expected.toString(), actual.toString());
		
		// Replace all values
		String newValue = "3000";
		BiFunction<String, String, String> biFunctionReplaceAll = (key, value)-> {
			return newValue;
		};
		hashMap.replaceAll(biFunctionReplaceAll);
		
		// Make sure all values was replaced
		actual = hashMap.get("key1");
		assertEquals(newValue.toString(), actual.toString());
		
		actual = hashMap.get("key2");
		assertEquals(newValue.toString(), actual.toString());
	}

	@Test
	public void TestHashMapSize() {
		// Create a HashMap to test
		HashMap<Double, String> hashMap = new HashMap<Double, String> ();
		hashMap.put(15.22222, "15.22222");
		hashMap.put(-50.2222, "50");		
		
		// Make sure the size is 2
		assertEquals(2, hashMap.size());
		
		// Add one more key/value and check size again
		hashMap.put((double) 123, "some thing here");
		assertEquals(3, hashMap.size());
	}

	@Test
	public void TestHashMapToString() {
		// Test HashMap<String, String>
		HashMap<String, String> hashMap = new HashMap<String, String> ();
		hashMap.put("key1", "value1");
		hashMap.put("key16", "value16");
		hashMap.put("key02", "value02");		
		String expected = "{key1=value1, key02=value02, key16=value16}";
		String actual = hashMap.toString();
		assertEquals(expected, actual);
		
		// Test HashMap<String, Integer>
		HashMap<String, Integer> anotherHashMap = new HashMap<String, Integer> ();
		anotherHashMap.put("some key", 12313);
		anotherHashMap.put("anotherKey", 76767);		
		expected = "{anotherKey=76767, some key=12313}";
		actual = anotherHashMap.toString();
		assertEquals(expected, actual);
		
		// Test an empty HashMap<String, Float>
		HashMap<String, Float> emptyHashMap = new HashMap<String, Float> ();
		expected = "{}";
		actual = emptyHashMap.toString();
		assertEquals(expected, actual);		
		
		// Test HashMap<String, ArrayList<Integer>>
		int[] arrayInteger1 = {1, 2, 3, 4, 5};
		ArrayList<Integer> arrayListInteger1 = new ArrayList<Integer> ();
		for(int integerNumber : arrayInteger1) {
			arrayListInteger1.add(integerNumber);
		}
		
		int[] arrayInteger2 = {100, 100, 100, 100, 1};
		ArrayList<Integer> arrayListInteger2 = new ArrayList<Integer> ();
		for(int integerNumber : arrayInteger2) {
			arrayListInteger2.add(integerNumber);
		}
		
		HashMap<String, ArrayList<Integer>> arrayListInHashMap = new HashMap<String, ArrayList<Integer>>();
		arrayListInHashMap.put("ArrayList1", arrayListInteger1);
		arrayListInHashMap.put("ArrayList2", arrayListInteger2);
		expected = "{ArrayList1=[1, 2, 3, 4, 5], ArrayList2=[100, 100, 100, 100, 1]}";
		actual = arrayListInHashMap.toString();
		assertEquals(expected, actual);
	}
}
