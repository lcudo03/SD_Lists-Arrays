#pragma once

#include "DynamicArray.hpp"
#include "SingleLinkedList.hpp"
#include "DoubleLinkedList.hpp"

#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <string>

class Benchmark {
    std::vector<int> generateTestData(int size);

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
    void runTests();
};