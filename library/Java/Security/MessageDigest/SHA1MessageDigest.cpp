//
// Created by home on 9/29/17.
//

#include "SHA1MessageDigest.hpp"

using namespace Java::Security;

SHA1MessageDigest::SHA1MessageDigest() {
    engineReset();
}

SHA1MessageDigest::~SHA1MessageDigest() {

}

int SHA1MessageDigest::engineDigest(byte *buffer, int len) {
    if (len < engineGetDigestLength()) {
        return 0;
    }

    if (!this->isFinished) {
        SHA1_Final(this->hash, &this->state);
    }

    memcpy(buffer, this->hash, sizeof(this->hash));
    return engineGetDigestLength();
}

int SHA1MessageDigest::engineGetDigestLength() {
    return (int)sizeof(this->hash);
}

void SHA1MessageDigest::engineReset() {
    memset(this->hash, 0, sizeof(this->hash));
    SHA1_Init(&this->state);
    this->isFinished = false;
}

void SHA1MessageDigest::engineUpdate(const byte *input, int len) {
    SHA1_Update(&this->state, input, len);
}
