#include "filereader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Reads a chunk of a file
std::vector<std::string> readChunk(const std::string& filename, size_t chunkSize) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    if (!file.is_open()) { 
        std::cerr << "Unable to open file: " << filename << std::endl;
        return lines;
    }

    for (size_t i = 0; i < chunkSize && std::getline(file, line); i++) {
        lines.push_back(line);
    }
    
    return lines;
}

