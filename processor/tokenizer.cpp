#include <iostream>
#include <unordered_map>
#include <string>

// Count Bigram occurances in a vector list of strings (split by spaces)
std::unordered_map<std::string, size_t> countBigrams(const std::vector<std::string>& strings) {

    std::unordered_map<std::string, size_t> bigrams;

    for (const std::string& str : strings) {

        for (size_t i = 0; i < str.length() - 1; ++i) {
            if (str[i] == ' ' || str[i + 1] == ' ') {
                continue;
            } 
            
            std::string bigram = std::string(1, str[i]) + std::string(1, str[i + 1]);
            bigrams[bigram]++;

        }

    }

    return std::move(bigrams);
}

