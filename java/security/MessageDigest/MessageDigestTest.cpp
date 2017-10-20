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

#include <chrono>
#include "MessageDigest.hpp"
#include "../NoSuchAlgorithmException/NoSuchAlgorithmException.hpp"
#include "../../lang/IllegalArgumentException/IllegalArgumentException.hpp"
#include "../../../kernel/Test.hpp"

using namespace Java::Lang;
using namespace Java::Security;
using namespace std::chrono;

long GetTickCount() {
    return duration_cast<milliseconds>(
            steady_clock::now().time_since_epoch()).count();
}

TEST(JavaSecurity, Constructor) {
    {
        String expect = "MDx not found";
        String result;
        try {
            MessageDigest md = MessageDigest::getInstance("MDx");
        } catch (NoSuchAlgorithmException e) {
            result = e.getMessage().toString();
        }

        assertEquals(expect.toString(), result.toString());
    }
}

TEST(JavaSecurity, MD5) {
    byte expect[] = {0x77, 0xad, 0xd1, 0xd5, 0xf4, 0x12, 0x23, 0xd5, 0x58,
                     0x2f, 0xca, 0x73, 0x6a, 0x5c, 0xb3, 0x35};
    String input = "the quick brown fox jumps over the lazy dog";
    byte* result = nullptr;
    MessageDigest md5 = MessageDigest::getInstance("MD5");
    int digestLength = 0;


    digestLength = md5.getDigestLength();
    result = new byte[digestLength]();

    md5.update((byte*)input.toString(), input.getSize());
    md5.digest(result, digestLength);

    assertArray(expect, result);

    md5.reset();
    md5.update((byte*)input.toString(), input.getSize());
    md5.digest(result, digestLength);

    assertArray(expect, result);

    delete[] result;
}

TEST(JavaSecurity, MD5MultiUpdate) {
    byte expect[] = {0x2b, 0xa6, 0xe1, 0x5e, 0xff, 0x29, 0xaa, 0x9, 0xd5, 0x44,
                     0xf5, 0x3f, 0x6c, 0x7d, 0xe5, 0x7d};
    String input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
            "Morbi condimentum porta erat ut faucibus. Nunc dictum suscipit"
            " nisl nec suscipit. Phasellus mattis mauris velit, ac tincidunt"
            " magna ultricies non.";
    byte* result = nullptr;
    MessageDigest md5 = MessageDigest::getInstance("MD5");
    int digestLength = 0;

    digestLength = md5.getDigestLength();
    result = new byte[digestLength]();

    srand((unsigned int)GetTickCount());
    int offset = 0;
    while (offset < input.getSize()) {
        int range = input.getSize() - offset;
        int size = rand() % range;
        if (size < 10)
            size = range;

        md5.update((byte*)input.toString() + offset, size);
        offset += size;
    }
    md5.digest(result, digestLength);

    assertArray(expect, result);

    delete[] result;
}

TEST(JavaSecurity, SHA1) {
    byte expect[] = { 0x16, 0x31, 0x27, 0x51, 0xef, 0x93, 0x07, 0xc3, 0xfd,
                      0x1a, 0xfb, 0xcb, 0x99, 0x3c, 0xdc, 0x80, 0x46, 0x4b,
                      0xa0, 0xf1 };
    String input = "the quick brown fox jumps over the lazy dog";
    byte* result = nullptr;
    MessageDigest sha1 = MessageDigest::getInstance("SHA1");
    int digestLength = 0;

    digestLength = sha1.getDigestLength();
    result = new byte[digestLength];

    sha1.update((byte*)input.toString(), input.getSize());
    sha1.digest(result, digestLength);

    assertArray(expect, result);
    delete[] result;
}

TEST(JavaSecurity, SHA1MultiUpdate) {
    byte expect[] = { 0xcd, 0x4b, 0x63, 0xd7, 0xde, 0x27, 0xcd, 0x21, 0x47,
                      0xc0, 0xf3, 0xde, 0x71, 0x88, 0xec, 0xc6, 0x1d, 0x6d,
                      0x91, 0x99 };
    String input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
            "Morbi condimentum porta erat ut faucibus. Nunc dictum suscipit"
            " nisl nec suscipit. Phasellus mattis mauris velit, ac tincidunt"
            " magna ultricies non.";
    byte* result = nullptr;
    MessageDigest sha1 = MessageDigest::getInstance("SHA1");
    int digestLength = 0;

    digestLength = sha1.getDigestLength();
    result = new byte[digestLength]();

    srand((unsigned int)GetTickCount());
    int offset = 0;
    while (offset < input.getSize()) {
        int range = input.getSize() - offset;
        int size = rand() % range;
        if (size < 10)
            size = range;
        sha1.update((byte*)input.toString() + offset, size);
        offset += size;
    }
    sha1.digest(result, digestLength);

    assertArray(expect, result);

    delete[] result;
}

TEST(JavaSecurity, GetAlgorithms) {
    {
        MessageDigest md5 = MessageDigest::getInstance("MD5");
        String expect = "MD5";
        String result;

        result = md5.getAlgorithm();
        assertEquals(expect.toString(), result.toString());
    }

    {
        MessageDigest sha1 = MessageDigest::getInstance("SHA1");
        String expect = "SHA1";
        String result;

        result = sha1.getAlgorithm();
        assertEquals(expect.toString(), result.toString());
    }
}

TEST(JavaSecurity, Exception) {
    {
        MessageDigest md5 = MessageDigest::getInstance("MD5");
        String expect = "No input buffer given";
        String result;

        try {
            md5.update(nullptr, 0);
        } catch (IllegalArgumentException e) {
            result = e.getMessage().toString();
        }

        assertEquals(expect.toString(), result.toString());
    }

    {
        MessageDigest sha1 = MessageDigest::getInstance("SHA1");
        String expect = "No output buffer given";
        String result;

        try {
            sha1.digest(nullptr, 1);
        } catch (IllegalArgumentException e) {
            result = e.getMessage().toString();
        }

        assertEquals(expect.toString(), result.toString());
    }

    {
        MessageDigest sha1 = MessageDigest::getInstance("SHA1");
        String expect = "Output buffer too small";
        String result;

        try {
            byte buf[1] = { 0 };
            sha1.digest(buf, sizeof(buf));
        } catch (IllegalArgumentException e) {
            result = e.getMessage().toString();
        }

        assertEquals(expect.toString(), result.toString());
    }
}