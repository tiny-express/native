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

#include "URLConnection.hpp"


using namespace Java::Net;

URLConnection::URLConnection() {
    String urlString = "";
    URL url(urlString);
    this->url = url;
}

URLConnection::URLConnection(URL url) {
    this->url = url;
}

URLConnection::~URLConnection() {
}

URL URLConnection::getURL() {
    return this->url;
}

void URLConnection::setDoInput(boolean doInput) {
    this->doInput = doInput;
}

boolean URLConnection::getDoInput() {
    return this->doInput;
}

void URLConnection::setDoOutput(boolean doOutput) {
    this->doOutput = doOutput;
}

boolean URLConnection::getDoOutput() {
    return this->doOutput;
}

void URLConnection::setUseCaches(boolean useCaches) {
    this->useCaches = useCaches;
}

boolean URLConnection::getUseCaches() {
    return this->useCaches;
}

void URLConnection::setIfModifiedSince(long ifModifiedSince) {
    this->ifModifiedSince = ifModifiedSince;
}

long URLConnection::getIfModifiedSince() {
    return this->ifModifiedSince;
}

void URLConnection::setReadTimeout(int timeout) {
    this->readTimeout = timeout;
}

int URLConnection::getReadTimeout() {
    return this->readTimeout;
}

void URLConnection::setAllowUserInteraction(boolean allowUserInteraction) {
    this->allowUserInteraction = allowUserInteraction;
}

boolean URLConnection::getAllowUserInteraction() {
    return this->allowUserInteraction;
}

void URLConnection::setConnectTimeout(int timeout) {
    this->connectTimeout = timeout;
}

int URLConnection::getConnectTimeout() {
    return this->connectTimeout;
}

string URLConnection::toString() const {
    return this->url.toString();
}