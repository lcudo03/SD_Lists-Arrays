#include "DynamicArrayBenchmark.hpp"
#include <iostream>

int main() {
    try {
        DynamicArrayBenchmark benchmark;
        benchmark.runTests();
        std::cout << "Koniec teestow, wszystko wykonalo sie prawidlowo, wyniki znajduja sie: results.csv\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}