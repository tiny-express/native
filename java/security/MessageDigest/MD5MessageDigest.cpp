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

#include "MD5MessageDigest.hpp"

using namespace Java::Security;

MD5MessageDigest::MD5MessageDigest() {
    engineReset();
}

MD5MessageDigest::~MD5MessageDigest() {

}

int MD5MessageDigest::engineDigest(byte *buffer, int len) {
    if (len < engineGetDigestLength()) {
        return 0;
    }

    if (!this->isFinished) {
        md5_finish(&this->state, this->hash);
    }

    memcpy(buffer, this->hash, sizeof(this->hash));
    return engineGetDigestLength();
}

int MD5MessageDigest::engineGetDigestLength() {
    return (int)sizeof(this->hash);
}

void MD5MessageDigest::engineReset() {
    memset(this->hash, 0, sizeof(this->hash));
    md5_init(&this->state);
    this->isFinished = false;
}

void MD5MessageDigest::engineUpdate(const byte *input, int len) {
    md5_append(&this->state, (const md5_byte_t*)input, len);
}
