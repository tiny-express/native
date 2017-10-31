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

#include "SHA1MessageDigest.hpp"

using namespace Java::Security;

SHA1MessageDigest::SHA1MessageDigest() {
    engineReset();
}

SHA1MessageDigest::~SHA1MessageDigest() {

}

long int SHA1MessageDigest::engineDigest(byte *buffer, long int len) {
    if (len < engineGetDigestLength()) {
        return 0;
    }

    if (!this->isFinished) {
        SHA1_Final(this->hash, &this->state);
    }

    memcpy(buffer, this->hash, sizeof(this->hash));
    return engineGetDigestLength();
}

long int SHA1MessageDigest::engineGetDigestLength() {
    return (long int)sizeof(this->hash);
}

void SHA1MessageDigest::engineReset() {
    memset(this->hash, 0, sizeof(this->hash));
    SHA1_Init(&this->state);
    this->isFinished = false;
}

void SHA1MessageDigest::engineUpdate(const byte *input, long int len) {
    SHA1_Update(&this->state, input, len);
}
