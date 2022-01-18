#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <istream>

const int DEFAULT_CAPACITY = 10;

class ArrayException
{
};

class Array
{
    int* ptr;

    int size, capacity;

    Array(const Array& arr);

    Array& operator=(const Array& arr);

    void increaseCapacity(int newCapacity);

    int getSize() const;
    friend std::ostream& operator<<(std::ostream& out, const Array& arr);

public:
    ~Array();

    explicit Array(int startCapacity = DEFAULT_CAPACITY);

    bool operator ==(const Array& arr);

    int& operator[](int index);

    void insert(int elem, int index);

    void insert(int elem);

    void insert(const Array& arr, int index);

    void remove(int index);

    void pop();

    int find(int elem);
};

#endif