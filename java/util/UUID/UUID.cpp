/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
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

#include "UUID.hpp"

UUID::UUID(Array<byte> data) {
    long msb = 0;
    long lsb = 0;

    for (int i = 0; i < 8; ++i) {
        msb = (msb << 8) | (data[i] & 0xff);
    }

    for (int j = 8; j < 16; ++j) {
        lsb = (lsb << 8) | (data[j] & 0xff);
    }

    this->mostSigBits = msb;
    this->leastSigBits = lsb;
    this->timestamp = time(0);
}

UUID::UUID(long mostSigBits, long leastSigBits) {
    this->mostSigBits = mostSigBits;
    this->leastSigBits = leastSigBits;
    this->timestamp = time(0);
}

UUID::~UUID() {
}

int	UUID::compareTo(UUID target) {
    return  (this->mostSigBits < target.mostSigBits ? -1 :
              (this->mostSigBits > target.mostSigBits ? 1 :
               (this->leastSigBits < target.leastSigBits ? -1 :
                (this->leastSigBits > target.leastSigBits ? 1 : 0)
               )
              )
            );
}

boolean	UUID::equals(UUID target) {
    return (this->mostSigBits == target.mostSigBits &&
            this->leastSigBits == target.leastSigBits);
}

long UUID::getLeastSignificantBits() {
    return this->leastSigBits;
}

long UUID::getMostSignificantBits() {
    return this->mostSigBits;
}

long UUID::getTimestamp() {
    return this->timestamp;
}

int UUID::hashCode() {
    long hilo = this->mostSigBits ^ this->leastSigBits;
    return ((int)(hilo >> 32)) ^ (int) hilo;
}

long UUID::node() {
    if (this->version() != 1) {
        //FIXME: throw an exception here - "Not a time-based UUID"
    }

    return this->leastSigBits & 0x0000FFFFFFFFFFFFL;
}

int UUID::variant() {
    return (int) ((this->leastSigBits >> (64 - (this->leastSigBits >> 62)))
                  & (this->leastSigBits >> 63));
}

int UUID::version() {
    return (int)((this->mostSigBits >> 12) & 0x0f);
}

String UUID::toString() {
    return this->getTrap(); //FIXME: implement correct this function
}

UUID UUID::fromString(String trap) {
    UUID uuid;
    uuid.setTrap(trap);
    return uuid;
};

// TODO: remove trap after fix toString/fromString
String UUID::getTrap() {
    return this->trap;
};

void UUID::setTrap(const String &trap) {
    this->trap = trap;
}

UUID::UUID() {}