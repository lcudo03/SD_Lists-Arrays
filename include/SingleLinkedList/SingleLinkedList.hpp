#pragma once
#include <iostream>
#include <stdexcept>

template <class T>
class SingleLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    SingleLinkedList();
    ~SingleLinkedList();

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
SingleLinkedList<T>::SingleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
template <typename T>
void SingleLinkedList<T>::insertAtStart(T value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template <typename T>
void SingleLinkedList<T>::insertAtEnd(T value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void SingleLinkedList<T>::insertAtRandom(T value, int index) {
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
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

template <typename T>
void SingleLinkedList<T>::removeFromStart() {
    if (head == nullptr) {
        throw std::out_of_range("Lista jest pusta!");
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void SingleLinkedList<T>::removeFromEnd() {
    if (tail == nullptr) {
        throw std::out_of_range("Lista jest pusta!");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        size--;
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    size--;
}

template <typename T>
void SingleLinkedList<T>::removeAtRandom(int index) {
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
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
}
template <typename T>
bool SingleLinkedList<T>::search(T value) {
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
void SingleLinkedList<T>::print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
