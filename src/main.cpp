#include <iostream>

#include "SingleLinkedList/SingleLinkedList.hpp"
#include "DoubleLinkedList/DoubleLinkedList.hpp"
#include "DynamicArray/DynamicArray.hpp"
template <typename T>
void test(T& set) {

    set.insertAtStart(1);
    set.insertAtEnd(3);
    set.insertAtRandom(2, 1);
    
    std::cout << "Stan struktury po dodaniu elementow ";
    set.print();
    
    std::cout << "Search for 2: " << (set.search(2) ? "Znaleziono element w strukturze" : "Nie znaleziono elementu w strukturze") << std::endl;
    std::cout << "Search for 5: " << (set.search(5) ? "Znaleziono element w strukturze" : "Nie znaleziono elementu w strukturze") << std::endl;
    
    set.removeFromStart();
    set.removeFromEnd();
    set.removeAtRandom(0);
    
    std::cout << "Stan struktury po usunieciu elementow ";
    set.print();
}

int main(){
    std::cout << "Testowanie zaimplementowanej struktury tablicy dynamicznej\n";
    DynamicArray<int> arr;
    test(arr);

    std::cout << "Testowanie zaimplementowanej struktury listy jednokierunkowej\n";
    SingleLinkedList<int> list1;
    test(list1);

    std::cout << "Testowanie zaimplementowanej struktury listy jednokierunkowej\n";
    DoubleLinkedList<int> list2;
    test(list2);
    return 0;
}