#pragma once
#include <iostream>
#include <stdexcept>

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
    void insertAtEnd(T value);
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
    delete[] array;
}

template <typename T>
void DynamicArray<T>::resize(){
    size *= 2;
    T *newArray = new T[size];
    for (int i = 0; i < currentSize; i++)
        newArray[i] = array[i];

    delete array;
    array = newArray;
}

template <typename T>
void DynamicArray<T>::insertAtStart(T value){
    if(currentSize == size) resize();
    for(int i = currentSize; i > 0; i--) 
        array[i] = array[i-1];

    array[0] = value;
    currentSize++;
}

template <typename T>
void DynamicArray<T>::insertAtEnd(T value){
    if(currentSize == size) resize();
    array[currentSize++] = value;
}

template <typename T>
void DynamicArray<T>::insertAtRandom(T value, int index){
    if(index < 0 || index > currentSize) 
        throw::std::out_of_range("Index poza rozmiarem struktury");
    if(currentSize == size) resize();

    for (int i = currentSize; i > index; i--) 
        array[i] = array[i - 1];

    array[index] = value;
    currentSize++;
}

template <typename T>
void DynamicArray<T>::removeFromStart(){
    if(currentSize == 0)
        throw::std::out_of_range("Tablica jest pusta!");

    for(int i = 0; i < currentSize-1; i++)
        array[i] = array[i+1];
    
    currentSize--;
}

template <typename T>
void DynamicArray<T>::removeFromEnd(){
    if(currentSize == 0)
        throw::std::out_of_range("Tablica jest pusta!");
    
    currentSize--;
}

template <typename T>
void DynamicArray<T>::removeAtRandom(int index){
    if(index < 0 || index > currentSize) 
        throw::std::out_of_range("Index poza rozmiarem struktury");
    
    for (int i = index; i < currentSize-1; i++)
        array[i] = array[i+1];
    
    currentSize--;
}

template <typename T>
bool DynamicArray<T>::search(T value){
    for (int i = 0; i < currentSize; i++){
        if(array[i] == value) return true;
    }
    return false;
}

template <typename T>
void DynamicArray<T>::print(){
    for (size_t i = 0; i < currentSize; i++)
        std::cout << array[i] << " ";
    
    std::cout << std::endl;
}