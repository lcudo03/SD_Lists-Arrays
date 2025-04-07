#pragma once
#include "DoubleLinkedList.hpp"
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <string>

class DynamicArrayBenchmark {
    std::vector<int> generateTestData(int size) {
        std::vector<int> data(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 100000);
        
        for (int i = 0; i < size; i++) {
            data[i] = dist(gen);
        }
        return data;
    }

    template<typename Func>
    double measureOperation(Func&& operation, int iterations = 1000) {
        double total_time = 0;
        
        // Pomiar
        for (int i = 0; i < iterations; i++) {
            auto start = std::chrono::high_resolution_clock::now();
            operation();
            auto end = std::chrono::high_resolution_clock::now();
            total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        }
        
        return total_time / iterations;
    }

public:
    void runTests() {
        const std::vector<int> sizes = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
        std::ofstream results("dynamic_array_results.csv");
        results << "Size,Operation,Time(ns)\n";
        
        for (int size : sizes) {
            std::cout << "Testing size: " << size << "\n";
            auto testData = generateTestData(size + 1); // +1 dla dodatkowego elementu
            
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
};