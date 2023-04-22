//
// Created by VeselinFMI on 4/22/2023.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H


#include <cstddef>

class Vector {
private:
    int *data;
    size_t size;
    size_t max_size;

    void copy(const Vector &other);

    void destroy();

public:
    //constructors
    Vector();

    Vector(size_t max_size);

    Vector(const Vector &other);

    Vector &operator=(const Vector &other);

    ~Vector();

    //capacity
    size_t getSize() const;

    size_t getMaxSize() const;

    void resize();

    size_t getCapacity() const;

    bool empty() const;

    void reserve(int max_size);

    void shrink_to_fit();

    //access
    int &operator[](int i);

    int &at(int i);

    int &front();

    int &back();

    const int *getData();

    //modifiers
    void assign(size_t n, int value);

    Vector &push_back(int value);

    Vector &pop_back();

    Vector &insert(size_t n, int value);

    Vector &erase(size_t n);

    void swap(Vector &other);

    void clear();

    //friends
    friend bool operator==(Vector &fst, Vector &snd);

    friend bool operator!=(Vector &fst, Vector &snd);

    friend bool operator<=(Vector &fst, Vector &snd);

    friend bool operator>=(Vector &fst, Vector &snd);

    friend bool operator>(Vector &fst, Vector &snd);

    friend bool operator<(Vector &fst, Vector &snd);

    //iterator
    class Iterator {
    private:
        Vector &vector;
        size_t position;

    public:
        Iterator(Vector& vector, size_t position);
        bool operator!=(const Iterator& other);
        Iterator& operator++();
        int& operator*();
    };

    Iterator begin();
    Iterator end();
};


#endif //VECTOR_VECTOR_H
