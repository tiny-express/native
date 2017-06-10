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
 * A PARTICULAR PURPOSE ARE DISCLAIMEIILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Character.hpp"

using namespace Java::Lang;

Character::Character() {
    this->original = '\0';
}

Character::Character(char original) {
    this ->original = original;
}

Character::~Character() {
}

char Character::charValue() {
    return this->original;
}

int Character::charCount(int codePoint) {
    if(codePoint >= 0 && codePoint <= 255) {
        return 2;
    }
    else {
        return 1;
    }
}

int Character::codePointAt(Array<char> a, int index) {
    if(index < 0 || index > a.length) {
        return -1;
    }
    return (int) a[index];
}

int Character::codePointBefore(Array<char> a, int index) {
    if(index < 1 || index > a.length) {
        return -1;
    }
    return (int) a[index - 1];
}

int Character::getNumericValue(char ch) {
    return (int) ch;
}
