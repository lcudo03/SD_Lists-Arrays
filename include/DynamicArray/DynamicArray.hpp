#pragma once
#include <iostream>

template <class T>
class DynamicArray{
private:
    T* array;
    int size;
    int currentSize;

    void resize();
public:
    DynamicArray();
    ~DynamicArray();

    void insertAtStart(T value);
    void insertAtEnd(T value)
    void insertAtRandom(T value, int index);
    void removeFromStart();
    void removeFromEnd();
    void removeAtRandom(int index);
    bool search(T value);
    void print();
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

template <typename T>
void DynamicArray<T>::resize(){
    size *= 2;
    T *newArray = new T[size];
    for (int i = 0; i < currentSize; i++)
    {
        newArray[i] = array[i];
    }
    delete array;
    array = newArray;
}

template <typename T>
void DynamicArray<T>::insertAtStart(T value){
    if(currentSize == size) resize();
    for(int i = currentSize; i > 0; i--) array[i] = array[i-1];
    array[0] = value;
    currentSize++;
}

template <typename T>
void DynamicArray<T>::insertAtEnd(T value){
    if(currentSize == capacity) resize();
    array[currentSize++] = value;
}

template <typename T>
void DynamicArray<T>::insertAtRandom(T value)