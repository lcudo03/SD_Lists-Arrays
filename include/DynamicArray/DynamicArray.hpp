#pragma once
#include <iostream>

template <class T>
class DynamicArray{
private:
    T* array;
    int size;
    int currentSize;
public:
    DynamicArray();
    ~DynamicArray();
};

template <typename T>
DynamicArray<T>::DynamicArray(/* args */) : size(1), currentSize(0){
    array = new T[size];
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] array
}
