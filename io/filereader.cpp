#include "filereader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <sstream>

namespace {

    std::string encodeSpaces(const std::string& str) {
        std::string encoded;
        encoded.reserve(str.size());
        for (char c : str) {
            if (c == ' ') {
                encoded += "%20";
            } else {
                encoded += c;
            }
        }
        return encoded;
    }

    std::string decodeSpaces(const std::string& token) {
    std::string decoded;
    decoded.reserve(token.size()); 
    for (size_t i = 0; i < token.size(); ++i) {
        if (i + 2 < token.size() && token[i] == '%' && token[i + 1] == '2' && token[i + 2] == '0') {
            decoded += ' ';
            i += 2;  // Skip over "20"
        } else {
            decoded += token[i];
        }
    }
    return decoded;
}

}

// Reads a chunk of a file
std::vector<std::string> readChunk(const std::string& filename, size_t chunkSize) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    if (!file.is_open()) { 
        std::cerr << "Unable to read file: " << filename << std::endl;
        return lines;
    }

    for (size_t i = 0; i < chunkSize && std::getline(file, line); i++) {
        lines.push_back(line + "\n");
    }

    file.close();
    
    return std::move(lines);
}

// Get's the filesize in bytes
size_t getFileSize(const std::string& filename) {
    return std::filesystem::file_size(filename);
}


// Takes a list of strings and writes them to a file, without creating extra newlines
// Current Spaces are encoded with %20 and spaces are inserted as a delimiter.
void writeTokens(const std::string& filename, std::vector<std::string>& filetext) {
    std::ofstream file(filename);
    std::ostringstream buffer;

    if (!file.is_open()) { 
        std::cerr << "Unable to write to file: " << filename << std::endl;
        return;
    }

    for (std::string& str : filetext) {
        buffer << encodeSpaces(str) << ' ';
    }

    // Remove the last space
    std::string output = buffer.str();
    if (!output.empty()) {
        output.pop_back(); 
    }

    file << output;
    file.close();
}

// Read space-separated tokens from a file
std::vector<std::string> readTokens(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> tokens;

    if (!file) {
        std::cerr << "Error opening token file: " << filename << std::endl;
        return tokens;
    }
    
    // std::string line;
    // while (std::getline(file, line)) { // Read line by line (or use chunks if necessary)
    //     std::istringstream iss(line);
    //     std::string token;

    //     while (iss >> token) {
    //         // Decode "%20" back to spaces
    //         tokens.push_back(decodeSpaces(token));
    //     }
    // }
    // return std::move(tokens);
}