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
#include "String.hpp"
#include <string>

using namespace Java::Lang;

void JavaLangStringConstructor(benchmark::State& state) {
    while (state.KeepRunning()) {
        String source = "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
                " Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
                " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
                " sit amet consequat magna tristique ut.";
    }
}

void StdStringConstructor(benchmark::State& state) {
    while (state.KeepRunning()) {
        std::string source = "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
                " Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
                " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
                " sit amet consequat magna tristique ut.";
    }
}

BENCHMARK(JavaLangStringConstructor)->Range(RANGE, RANGE);
BENCHMARK(StdStringConstructor)->Range(RANGE, RANGE);

void JavaLangStringLength(benchmark::State& state) {
    String source = "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
            " Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
            " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
            " sit amet consequat magna tristique ut.";
    while (state.KeepRunning()) {
        source.length();
    }
}

void StdStringSize(benchmark::State& state) {
    std::string source = "Lorem ipsum dolor sit amet, consectetur adipiscing "
            "elit. Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
            " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
            " sit amet consequat magna tristique ut.";
    while (state.KeepRunning()) {
        source.length();
    }
}

BENCHMARK(JavaLangStringLength)->Range(RANGE, RANGE);
BENCHMARK(StdStringSize)->Range(RANGE, RANGE);

void JavaLangStringOperatorPlus(benchmark::State& state) {
    String source = "Lorem ipsum dolor sit amet, consectetur adipiscing "
            "elit. Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
            " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
            " sit amet consequat magna tristique ut.";
    while (state.KeepRunning()) {
        source += "Lorem ipsum dolor sit amet, consectetur adipiscing "
                "elit. Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
                " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
                " sit amet consequat magna tristique ut.";
    }
}

void StdStringOperatorPlus(benchmark::State& state) {
    std::string source = "Lorem ipsum dolor sit amet, consectetur adipiscing "
            "elit. Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
            " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
            " sit amet consequat magna tristique ut.";
    while (state.KeepRunning()) {
        source += "Lorem ipsum dolor sit amet, consectetur adipiscing "
                "elit. Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
                " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
                " sit amet consequat magna tristique ut.";
    }
}

BENCHMARK(JavaLangStringOperatorPlus)->Range(RANGE, RANGE);
BENCHMARK(StdStringOperatorPlus)->Range(RANGE, RANGE);

void JavaLangStringContains(benchmark::State& state) {
    String source = "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
            " Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
            " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
            " sit amet consequat magna tristique ut.";
    String subString = "Praesent sagittis magna orci,";

    while (state.KeepRunning()) {
        source.contains(subString);
    }
}

void StdStringFind(benchmark::State& state) {
    std::string source = "Lorem ipsum dolor sit amet, consectetur adipiscing "
            "elit. Vivamus rhoncus lorem non euismod eleifend. Duis elementum"
            " venenatis nibh vitae dignissim. Praesent sagittis magna orci,"
            " sit amet consequat magna tristique ut.";
    std::string subString = "Praesent sagittis magna orci,";

    while (state.KeepRunning()) {
        source.find(subString);
    }
}

BENCHMARK(JavaLangStringContains)->Range(RANGE, RANGE);
BENCHMARK(StdStringFind)->Range(RANGE, RANGE);
