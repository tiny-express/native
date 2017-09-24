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

#include "MessageDigest.hpp"
#include "MD5MessageDigest.hpp"

using namespace Java::Security;

MessageDigest *MessageDigest::getInstance(String algorithm) {
    if (algorithm == "MD5") {
       MessageDigestSpi* spi = new MD5MessageDigest();
       return new MessageDigest(spi);
    }
    return nullptr;
}

MessageDigest::~MessageDigest() {
    if (spi) {
        delete spi;
    }
}

String MessageDigest::getAlgorithm() {
    return algorithm;
}

int MessageDigest::getDigestLength() {
    return engineGetDigestLength();
}

int MessageDigest::digest(byte *buf, int offset, int len) {
    return engineDigest(buf, offset, len);
}

Array<byte> MessageDigest::digest() {
    return Array<byte>();
}

void MessageDigest::reset() {
    engineReset();
}

void MessageDigest::update(const byte input[], int offset, int len) {
    engineUpdate(input, offset, len);
}

MessageDigest::MessageDigest(MessageDigestSpi *spi) {
    this->spi = spi;
}

int MessageDigest::engineDigest(byte buffer[], int offset, int len) {
    if (spi) {
        return spi->engineDigest(buffer, offset, len);
    }
    return 0;
}

int MessageDigest::engineGetDigestLength() {
    if (spi) {
        return spi->engineGetDigestLength();
    }
    return 0;
}

void MessageDigest::engineReset() {
    if (spi) {
        spi->engineReset();
    }
}

void MessageDigest::engineUpdate(const byte input[], int offset, int len) {
    if (spi) {
        spi->engineUpdate(input, offset, len);
    }
}
