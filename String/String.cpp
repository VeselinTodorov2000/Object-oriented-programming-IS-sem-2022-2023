//
// Created by VeselinFMI on 4/24/2023.
//

#include "String.h"
#include <cstring>

void String::copy(const String &other) {
    this->size = strlen(other.data);
    this->data = new char[this->size + 1];
    strcpy(this->data, other.data);
}

void String::destroy() {
    delete[] data;
}

String::String() {
    this->data = nullptr;
    this->size = 0;
}

String::String(const String &other) {
    copy(other);
}

String::String(const String &other, unsigned int pos, unsigned int n) {
    this->size = n;
    this->data = new char[n + 1];
    for(int i = pos, j = 0; i < pos + n; i++, j++) {
        this->data[j] = other.data[i];
    }
}

String::String(const char *other) {
    this->size = strlen(other);
    this->data = new char[this->size + 1];
    strcpy(this->data, other);
}

String::~String() {
    destroy();
}

String &String::operator=(const String &other) {
    if(this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

String &String::operator=(const char *&other) {
    if (this->data != other) {
        destroy();
        this->size = strlen(other);
        this->data = new char[this->size + 1];
        strcpy(this->data, other);
    }
    return *this;
}

String &String::operator=(const char other) {
    destroy();
    this->size = 1;
    this->data = new char[2];
    this->data[0] = other;
}

const unsigned String::getSize() const {
    return this->size;
}

String &String::append(const char *s) {
    return (*this += s);
}

String &String::operator+=(const char *s) {
    char* buffer = new char[size + strlen(s) + 1];
    strcpy(buffer, this->data);
    strcat(buffer, s);
    size += strlen(s);
    destroy();
    this->data = buffer;
    return *this;
}

String &String::insert(unsigned int pos, const char *s) {
    if(size < pos) {
        this->push_back(s);
    }
    char* buffer = new char[size + strlen(s) + 1];
    strcpy_s(buffer, size-pos, this->data);
    size += strlen(s);
    strcat(buffer, s);
    for(int i = strlen(buffer), j = pos; i < size; i++, j++) {
        buffer[i] = this->data[j];
    }
    destroy();
    this->data = buffer;
    return *this;
}

String &String::erase(unsigned int pos, unsigned int len) {
    if(len + pos > size) {
        throw "Exceeded size";
    }
    char* buffer = new char[size - len + 1];
    strcpy_s(buffer, size-pos, this->data);
    for(int i = strlen(buffer), j = pos; i < size; i++, j++) {
        buffer[i] = this->data[j];
    }
    destroy();
    this->data = buffer;
    return *this;
}

String &String::push_back(const char *s) {
    char* buffer = new char[size + strlen(s) + 1];
    strcpy_s(buffer, size, this->data);
    size += strlen(s);
    destroy();
    this->data = buffer;
    return *this;
}

String &String::pop_back() {
    char* buffer = new char[size];
    strcpy_s(buffer, size-1, this->data);
    size--;
    destroy();
    this->data = buffer;
    return *this;
}















