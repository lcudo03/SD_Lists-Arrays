#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Menu
{
public:

    template <typename T>
    static void displayStructureMenu(T& structure, const string& structureName);

    static void displayMainMenu();
};

template <typename T>
static void Menu::displayStructureMenu(T& structure, const string& structureName) {
    int choice;
    string filename;
    T tempStructure; // Tymczasowa struktura do wczytywania z pliku

    do {
        cout << "\n===== MENU DLA " << structureName << " =====\n";
        cout << "1. Zbuduj z pliku\n";
        cout << "2. Usun element\n";
        cout << "3. Dodaj element\n";
        cout << "4. Znajdz element\n";
        cout << "5. Utworz losowo\n";
        cout << "6. Wyswietl\n";
        cout << "0. Powrot\n";
        cout << "Wybierz opcje: ";
        cin >> choice;
        system( "cls" );

        switch (choice) {
            case 1: // Zbuduj z pliku
                cout << "Podaj nazwe pliku: ";
                cin >> filename;
                {
                    ifstream file(filename);
                    if (!file) {
                        cerr << "Blad otwarcia pliku!\n";
                        break;
                    }
                    structure.clear();
                      // Usuwa poprzednie dane
                    int value;
                    while (file >> value) {
                        structure.insertAtEnd(value);
                    }
                    cout << "Wczytano dane z pliku.\n";
                }
                break;

            case 2: // Usun element
                int positionToRemove;
                cout << "Podaj pozycje do usuniecia (0 - poczatek, -1 - koniec, inna - indeks): ";
                cin >> positionToRemove;
                try {
                    if (positionToRemove == 0) {
                        structure.removeFromStart();
                    } else if (positionToRemove == -1) {
                        structure.removeFromEnd();
                    } else {
                        structure.removeAtRandom(positionToRemove);
                    }
                    cout << "Usunieto element.\n";
                } catch (const out_of_range& e) {
                    cerr << "Blad: " << e.what() << endl;
                }
                break;

            case 3: // Dodaj element
                int value, positionToAdd;
                cout << "Podaj wartosc: ";
                cin >> value;
                cout << "Podaj pozycje (0 - poczatek, -1 - koniec, inna - indeks): ";
                cin >> positionToAdd;
                try {
                    if (positionToAdd == 0) {
                        structure.insertAtStart(value);
                    } else if (positionToAdd == -1) {
                        structure.insertAtEnd(value);
                    } else {
                        structure.insertAtRandom(value, positionToAdd);
                    }
                    cout << "Dodano element.\n";
                } catch (const out_of_range& e) {
                    cerr << "Blad: " << e.what() << endl;
                }
                break;

            case 4: // Znajdz element
                int searchValue;
                cout << "Podaj wartosc do wyszukania: ";
                cin >> searchValue;
                if (structure.search(searchValue)) {
                    cout << "Znaleziono element.\n";
                } else {
                    cout << "Nie znaleziono elementu.\n";
                }
                break;

            case 5: // Utworz losowo
                int size;
                cout << "Podaj rozmiar struktury: ";
                cin >> size;
                structure = T(); // Reset struktury
                srand(time(nullptr));
                for (int i = 0; i < size; ++i) {
                    structure.insertAtEnd(rand() % 100); // Losowe wartości 0-99
                }
                cout << "Wygenerowano losowa strukture.\n";
                break;

            case 6: // Wyswietl
                cout << "Zawartosc struktury:\n";
                structure.print();
                break;

            case 0: // Powrot
                break;

            default:
                cout << "Nieprawidlowa opcja!\n";
        }
    } while (choice != 0);
}
