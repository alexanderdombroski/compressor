// Test File written by ChatGPT on 9/3/24

#include <iostream>
#include <string>
#include "../processor/tokenizer.h"


void testCountBigrams() {
    std::vector<std::string> testStrings = {
        "hello world", 
        "hello hello", 
        "world hello",
        "hello  ", // Test with trailing spaces
        "  hello",  // Test with leading spaces
        "hello there"
    };

    auto bigramCounts = countBigrams(testStrings);

    // Print results
    std::cout << "Bigram Counts:\n";
    for (const auto& pair : bigramCounts) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
    testCountBigrams();
    return 0;
}