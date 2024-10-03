#include <iostream>
#include <string>
#include "../processor/tokenizer.h"


void testCountBigrams() {
    std::vector<std::string> testStrings = {
        "hello world\n", 
        "hello hello howdy aloha\n", 
        "world hello \n",
        "hello  \n", // Test with trailing spaces
        "  hello\n",  // Test with leading spaces
        "hello there program\n"
    };

    auto [tokens, tokenCounts] = tokenize(testStrings);

    // Print results
    std::cout << "Bigram Counts:\n";
    for (const auto& pair : tokenCounts) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    for (const auto& str : tokens) {
        std::cout << str;
    }
}

int main() {
    testCountBigrams();
    return 0;
}