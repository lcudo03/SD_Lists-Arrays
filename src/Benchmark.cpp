#include "Benchmark.hpp"


void Benchmark::runTests() {
    const std::vector<int> sizes = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000, 200000};

    std::string filename = "../../resultsDoubleLinkedList.csv";

    std::ofstream results(filename);

    for (int size : sizes) {
        std::cout << "Testing size: " << size << "\n";
        auto testData = generateTestData(size + 1); // +1 dla dodatkowego elementu
        
        //Odkomentowac badaną strukture
        //DynamicArray<int> array;
        //SingleLinkedList<int> array;
        DoubleLinkedList<int> array;

        // Wypełnij tablicę danymi testowymi
        for (int i = 0; i < size; i++) {
            array.insertAtEnd(testData[i]);
        }
        
        // Test insertAtEnd
        double insertEndTime = measureOperation([&]() {
            array.insertAtEnd(testData.back());
        });
        
        // Test insertAtStart
        double insertStartTime = measureOperation([&]() {
            array.insertAtStart(testData.back());
        });
        
        // Test insertAtRandom (środek tablicy)
        double insertRandomTime = measureOperation([&]() {
            array.insertAtRandom(testData.back(), size/2);
        });
        
        // Test search
        double searchTime = measureOperation([&]() {
            array.search(rand());
        });
        
        // Test removeFromEnd
        double removeEndTime = measureOperation([&]() {
            array.removeFromEnd();
        });
        
        // Test removeFromStart
        double removeStartTime = measureOperation([&]() {
            array.removeFromStart();
        });
        
        // Test removeAtRandom (środek tablicy)
        double removeRandomTime = measureOperation([&]() {
            array.removeAtRandom(size/2);
        });
        
        // Zapisz wyniki
        results << size << ",insertAtEnd," << insertEndTime << "\n";
        results << size << ",insertAtStart," << insertStartTime << "\n";
        results << size << ",insertAtRandom," << insertRandomTime << "\n";
        results << size << ",search," << searchTime << "\n";
        results << size << ",removeFromEnd," << removeEndTime << "\n";
        results << size << ",removeFromStart," << removeStartTime << "\n";
        results << size << ",removeAtRandom," << removeRandomTime << "\n";
    
    }
}


std::vector<int> Benchmark::generateTestData(int size) {
    std::vector<int> data(size); //tworzenie kontenera na nasze dane
    std::mt19937 gen(30); //generowanie liczb ze stałego ziarna
    std::uniform_int_distribution<int> dist(1, 100000);
    
    for (int i = 0; i < size; i++) {
        data[i] = dist(gen);
    }
    return data;
}
