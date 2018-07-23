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

#include "URLDecoder.hpp"
#include "../../../../library/Java/Io/UnsupportedEncodingException/UnsupportedEncodingException.hpp"

using namespace Java::Net;

String URLDecoder::decode(const String &source) {
    return URLDecoder::decode(source, "UTF-8");
}


inline char charFromHex(char ch) {
    return (char)(isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10);
}

//inline char *urlDecode(char *target, int size) {
//    char *targetIndex = target;
//    auto result = (char *) calloc((size_t) size + 1, sizeof(char));
//    char *resultIndex = result;
//    while (*targetIndex) {
//        if (*targetIndex == '%') {
//            if (targetIndex[1] && targetIndex[2]) {
//                *resultIndex++ = charFromHex(targetIndex[1]) << 4 | charFromHex(targetIndex[2]);
//                targetIndex += 2;
//            }
//        } else if (*targetIndex == '+') {
//            *resultIndex++ = ' ';
//        } else {
//            *resultIndex++ = *targetIndex;
//        }
//        targetIndex++;
//    }
//    *resultIndex = '\0';
//    return result;
//}

inline String urlDecode(String target) {
    String result;
    int targetIndex = 0;
    while (targetIndex < target.getSize()) {
        if (target[targetIndex] == '%') {
            if (target[targetIndex + 1] && target[targetIndex + 2]) {
                result += charFromHex(target[targetIndex + 1]) << 4 | charFromHex(target[targetIndex + 2]);
                targetIndex += 2;
            }
        } else if (target[targetIndex] == '+') {
            result += ' ';
        } else {
            result += target[targetIndex];
        }
        targetIndex++;
    }
    return result;
}

String URLDecoder::decode(const String &source, const String &encoding) {
    // TODO(truongchauhien): String class need to be refactoring.
    auto &referenceToEncoding = const_cast<String &>(encoding);
    if (referenceToEncoding.toUpperCase() == "UTF-8") {
        String decodedString = urlDecode(source.toCharPointer());
        //String result(decodedString);
        //free(decodedString);
        return decodedString;
    }
    // TODO(truongchauhien): Need "java.nio.charset.Charset" class and "Array<byte> getBytes(const Charset &) method".
    throw UnsupportedEncodingException(encoding);
}