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

#include "../../../library.hpp"

class MainApplication {
public:
		static void main(Array<String> arguments) {
			HashMap<String, String> hashMap;
			long int counter = 0;
			for (String argument : arguments) {
				hashMap.put("argument " + String::valueOf(counter), argument);
				counter++;
			}
			// Collect key value pairs
			String pairs = String("We have ") + String::valueOf(hashMap.size()) + String(" pairs: \n");
			for (Map<String, String>::Entry entry : hashMap.entrySet()) {
				pairs += entry.getKey() + String(" is ") + entry.getValue() + String("\n");
			}
			System::out::println(pairs);
			// Serialize to json data
			ArrayList<HashMap<String, String>> arrayList;
			arrayList.add(hashMap);
			System::out::println(arrayList.toString());
		}
};

long int main(long int argc, char **argv) {
	return Application(MainApplication::main, argc, argv);
}
