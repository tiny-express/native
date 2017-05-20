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

#ifndef NATIVE_GENERIC_H
#define NATIVE_GENERIC_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

/*
int Integer(char *target);
int Integer(std::string target);
int Integer(long target);
int Integer(float target);
int Integer(double target);

long Long(char *target);
long Long(std::string target);
long Long(int target);
long Long(float target);
long Long(double target);

float Float(char *target);
float Float(std::string target);
float Float(int target);
float Float(long target);
float Float(double target);

double Double(char *target);
double Double(std::string target);
double Double(int target);
double Double(long target);
double Double(float target);

bool Boolean(char *target);
bool Boolean(std::string target);
bool Boolean(int target);
bool Boolean(long target);

char *String(char target);
char *String(char const *target);
char *String(std::string target);
char *String(int target);
char *String(double target);
char *String(std::vector<int> target);
char *String(std::vector<double> target);
 */

double round(double target, int precision);
char chr(int target);
int ord(char target);

void print(const char *target);
void print(char *target);
void print(std::string target);
void print(short target);
void print(int target);
void print(long target);
void print(double target);
void print(std::vector<int> target);
void print(std::vector<double> target);

int *random(int limitation);
char *random(char *range, int limitation);

#define empty(X) len(X) == 0

int len(char *target);
int len(std::string target);
int len(char **target);
int len(short target);
int len(int target);
int len(long target);
int len(float target);
int len(double target);
int len(std::vector<char*> target);
int len(std::vector<std::string> target);
int len(std::map<char*, char*> target);
int len(std::map<std::string, std::string> target);

std::vector<char*> split(char *target, char *delimiter);
std::vector<char*> split(std::string target, char *delimiter);

char* file(char *file_name);
bool file(char *file_name, char *file_content);

char *md5(char *target);
char *md5(std::string target);
char *md5(short target);
char *md5(int target);
char *md5(long target);
char *md5(float target);
char *md5(double target);

char *sha1(char *target);
char *sha1(std::string target);
char *sha1(short target);
char *sha1(int target);
char *sha1(long target);
char *sha1(float target);
char *sha1(double target);

#endif//NATIVE_GENERIC_H