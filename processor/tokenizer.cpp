#include <iostream>
#include <unordered_map>
#include <string>

namespace {
    // Splits a list of strings by spaces and returns the flattened list (with spaces)
    std::vector<std::string> splitStrings(const std::vector<std::string>& strings) {
        std::vector<std::string> results;

        for (const std::string& str : strings) {
            split(str, results);
        }
    }

    // Split a single string by spaces, and keep spaces
    void split(const std::string input, std::vector<std::string>& result) {
        std::string current;

        for (size_t i = 0; i < input.length(); ++i) {
            char c = input[i];

            if (c == ' ') {
                if (!current.empty()) {
                    result.push_back(current);
                    current.clear();
                }
                result.push_back(" ");
            } else {
                current += c;
            }
        }

        // Last word
        if (!current.empty()) {
            result.push_back(current);
        }
    }


    // Count single char and Bigram occurances in a vector list of strings
    std::unordered_map<std::string, size_t> countBigrams(const std::vector<std::string>& strings) {

        std::unordered_map<std::string, size_t> bigrams;

        for (const std::string& str : strings) {
            if (str.length() == 1) {
                bigrams[str]++;
                continue;
            }

            for (size_t i = 0; i < str.length() - 1; ++i) {
                std::string bigram = std::string(1, str[i]) + std::string(1, str[i + 1]);
                bigrams[bigram]++;
            }
        }

        return std::move(bigrams);
    }

    // Count bigrams of an even word
    size_t sumBigramCounts(const std::string& evenStr, const std::unordered_map<std::string, size_t>& bigramCounts) {
        size_t total = 0;
        
        for (size_t i = 0; i < evenStr.length(); i += 2) {
            const std::string bigram = std::string{evenStr[i], evenStr[i + 1]};
            total += bigramCounts.count(bigram) > 0 ? bigramCounts.at(bigram) : 0;
        }

        return total;
    }

    // Push Bigrams and keep track of occurances (word must have even length)
    void pushBigrams(const std::string& str, std::vector<std::string>& tokens, std::unordered_map<std::string, size_t>& tokenCounts) {
        for (size_t i = 0; i < str.length(); i += 2) {
            const std::string bigram = std::string{str[i], str[i + 1]};
            tokens.push_back(bigram);
            tokenCounts[bigram]++;
        }
    }
}


// Converts strings to bigrams while minimizing the amount of tokens
std::vector<std::string> tokenize(const std::vector<std::string>& inputStrings) {
    const std::vector<std::string> strings = splitStrings(inputStrings); // ToDo Change to flatten with spaces  
    const std::unordered_map<std::string, size_t> bigramCounts = countBigrams(strings);
    std::vector<std::string> tokens;
    std::unordered_map<std::string, size_t> tokenCounts;

    for (const std::string& str : strings) {

        if (str.length() == 1) {
            tokens.push_back(str);
            tokenCounts[str]++;
            continue;
        }

        // Length is even
        if (str.length() % 2 == 0) {
            pushBigrams(str, tokens, tokenCounts);
            continue;
        }

        // Length is Odd
        const std::string left = str.substr(0, str.length() - 1);
        const std::string right = str.substr(1);
        size_t leftScore = sumBigramCounts(left, bigramCounts);
        size_t rightScore = sumBigramCounts(right, bigramCounts);
        
        if (leftScore > rightScore) {
            pushBigrams(left, tokens, tokenCounts);
            const std::string charStr = std::string(1, str[str.length() - 1]);
            tokens.push_back(charStr);
            tokenCounts[charStr]++;
        } else {
            const std::string charStr = std::string(1, str[0]);
            tokens.push_back(charStr);
            tokenCounts[charStr]++;
            pushBigrams(right, tokens, tokenCounts);
        }
        
    }
}