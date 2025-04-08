#include "Menu.hpp"
#include "SingleLinkedList.hpp"
#include "DoubleLinkedList.hpp"
#include "DynamicArray.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    DynamicArray<int> arrayList;
    SingleLinkedList<int> singleList;
    DoubleLinkedList<int> doubleList;

    int mainChoice;
    do {
        Menu::displayMainMenu();
        cin >> mainChoice;
        system( "cls" );

        switch (mainChoice) {
            case 1:
                Menu::displayStructureMenu(arrayList, "Tablicy Dynamicznej");
                break;
            case 2:
                Menu::displayStructureMenu(singleList, "Listy jednokierunkowej");
                break;
            case 3:
                Menu::displayStructureMenu(doubleList, "Listy dwukierunkowej");
                break;
            case 0:
                cout << "Koniec programu.\n";
                break;
            default:
                cout << "Nieprawidlowa opcja!\n";
        }
    } while (mainChoice != 0);

    return 0;
}