#pragma once
#include <iostream>
#include <stdexcept>

template <class T>
class DoubleLinkedList
{
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;
public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void insertAtStart(T value);
    void insertAtEnd(T value);
    void insertAtRandom(T value, int index);

    void removeFromStart();
    void removeFromEnd();
    void removeAtRandom(int index);

    bool search(T value);

    void print();

    void clear();
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void DoubleLinkedList<T>::insertAtStart(T value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void DoubleLinkedList<T>::insertAtEnd(T value){
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}


template <typename T>
void DoubleLinkedList<T>::insertAtRandom(T value, int index){
    if (index < 0 || index > size) {
        throw std::out_of_range("Index poza rozmiarem struktury");
    }
    if (index == 0) {
        insertAtStart(value);
        return;
    }
    if (index == size) {
        insertAtEnd(value);
        return;
    }
    
    Node* newNode = new Node(value);
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}

template <typename T>
void DoubleLinkedList<T>::removeFromStart() {
    if (head == nullptr) {
        throw std::out_of_range("Lista jest pusta!");
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    size--;
}


template <typename T>
void DoubleLinkedList<T>::removeFromEnd() {
    if (tail == nullptr) {
        throw std::out_of_range("Lista jest pusta!");
    }
    Node* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    size--;
}


template <typename T>
void DoubleLinkedList<T>::removeAtRandom(int index){
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index poza rozmiarem struktury");
    }
    if (index == 0) {
        removeFromStart();
        return;
    }
    if (index == size - 1) {
        removeFromEnd();
        return;
    }
    
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}

template <typename T>
bool DoubleLinkedList<T>::search(T value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void DoubleLinkedList<T>::print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleLinkedList<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}