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

#include "../../../benchmark/benchmark.hpp"
#include "../HashMap/HashMap.hpp"
#include <unordered_map>

using namespace Java::Lang;

void JavaUtilHashMapConstructor(benchmark::State& state) {
    while (state.KeepRunning()) {
        HashMap<String, String> hashMap;
    }
}

void StdUnorderedMapConstructor(benchmark::State& state) {
    while (state.KeepRunning()) {
        std::unordered_map<String, String> hashMap;
    }
}

BENCHMARK(JavaUtilHashMapConstructor)->Range(RANGE, RANGE);
BENCHMARK(StdUnorderedMapConstructor)->Range(RANGE, RANGE);

void JavaUtilHashMapPut(benchmark::State& state) {
    HashMap<String, String> hashMap;
    while (state.KeepRunning()) {
        hashMap.put("test", "test");
    }
}

void StdUnorderedMapPut(benchmark::State& state) {
    std::unordered_map<String, String> map;
    while (state.KeepRunning()) {
        map.insert(std::make_pair("test", "test"));
    }
}

BENCHMARK(JavaUtilHashMapPut)->Range(RANGE, RANGE);
BENCHMARK(StdUnorderedMapPut)->Range(RANGE, RANGE);