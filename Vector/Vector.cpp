//
// Created by VeselinFMI on 4/22/2023.
//

#include "Vector.h"
#include <stdexcept>
#include <cassert>

Vector::Vector() {
    this->size = 0;
    this->max_size = 8;
    this->data = new int[this->max_size];
}

Vector::Vector(size_t max_size) {
    this->size = 0;
    this->max_size = max_size;
    this->data = new int[this->max_size];
}

Vector::Vector(const Vector &other) {
    copy(other);
}

Vector &Vector::operator=(const Vector &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Vector::~Vector() {
    destroy();
}

void Vector::copy(const Vector &other) {
    this->max_size = other.max_size;
    this->size = other.size;
    this->data = new int[this->max_size];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

void Vector::destroy() {
    delete[] data;
}

size_t Vector::getSize() const {
    return this->size;
}

size_t Vector::getMaxSize() const {
    return this->max_size;
}

void Vector::resize() {
    this->reserve(this->max_size * 2);
}

size_t Vector::getCapacity() const {
    return this->max_size * sizeof(int);
}

bool Vector::empty() const {
    return this->size == 0;
}

void Vector::reserve(int max_size) {
    this->max_size = max_size;
    int *buffer = new int[this->max_size];
    for (int i = 0; i < this->size; i++) {
        buffer[i] = this->data[i];
    }
    destroy();
    data = buffer;
}

void Vector::shrink_to_fit() {
    this->reserve(this->size);
}

int &Vector::operator[](int i) {
    return this->at(i);
}

int &Vector::at(int i) {
    if (i >= size) {
        throw std::out_of_range(i + " is bigger than the size");
    }
    return this->data[i];
}

int &Vector::front() {
    return at(0);
}

int &Vector::back() {
    return at(size - 1);
}

const int *Vector::getData() {
    return this->data;
}

void Vector::assign(size_t n, int value) {
    destroy();
    size = n;
    while (n > max_size) {
        resize();
    }
    for (int i = 0; i < n; i++) {
        this->data[i] = value;
    }
}

Vector &Vector::push_back(int value) {
    if (size == max_size) {
        resize();
    }
    this->data[size++] = value;
    return *this;
}

Vector &Vector::pop_back() {
    if (!this->empty()) {
        this->size--;
    }
    return *this;
}

Vector &Vector::insert(size_t n, int value) {
    if (size == max_size) {
        resize();
    }
    if (n >= size) {
        this->push_back(value);
    }
    for (int i = size - 1; i >= n; i--) {
        this->data[i + 1] = this->data[i];
    }
    this->data[n] = value;
    return *this;
}

Vector &Vector::erase(size_t n) {
    if (n >= size) {
        this->pop_back();
    }
    for (int i = n; i < size; i++) {
        this->data[i] = this->data[i + 1];
    }
    size--;
    return *this;
}

void Vector::swap(Vector &other) {
    if (max_size != other.max_size) {
        size_t toReserve = std::max(max_size, other.max_size);
        reserve(toReserve);
        other.reserve(toReserve);
    }
    for (int i = 0; i < std::max(this->size, other.size); i++) {
        int temp = data[i];
        data[i] = other[i];
        other[i] = temp;
    }
    int temp = this->size;
    this->size = other.size;
    other.size = temp;
}

void Vector::clear() {
    this->destroy();
    this->size = 0;
}

bool operator==(Vector &fst, Vector &snd) {
    if (fst.size != snd.size) {
        return false;
    }
    for (int i = 0; i < fst.size; i++) {
        if (fst[i] != snd[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(Vector &fst, Vector &snd) {
    return !(fst == snd);
}

bool operator<=(Vector &fst, Vector &snd) {
    if (fst.size != snd.size) {
        return false;
    }
    for (int i = 0; i < fst.size; i++) {
        if (fst[i] > snd[i]) {
            return false;
        }
    }
    return true;
}

bool operator<(Vector &fst, Vector &snd) {
    if (fst.size != snd.size) {
        return false;
    }
    for (int i = 0; i < fst.size; i++) {
        if (fst[i] >= snd[i]) {
            return false;
        }
    }
    return true;
}

bool operator>(Vector &fst, Vector &snd) {
    return !(fst <= snd);
}

bool operator>=(Vector &fst, Vector &snd) {
    return !(fst < snd);
}

Vector::Iterator Vector::begin() {
    return Vector::Iterator(*this, 0);
}

Vector::Iterator Vector::end() {
    return Vector::Iterator(*this, size);
}


Vector::Iterator::Iterator(Vector &vector, size_t position)
: vector(vector), position(position){

}

bool Vector::Iterator::operator!=(const Vector::Iterator &other) {
    if(&vector != &(other.vector)) {
        return false;
    }
    return position != other.position;
}

Vector::Iterator &Vector::Iterator::operator++() {
    position++;
    return *this;
}

int &Vector::Iterator::operator*() {
    return vector.data[position];
}
