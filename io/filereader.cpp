#include "filereader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>


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
// void writeFile(std::string filename, std::vector<std::string>& filetext) {
//     std::ofstream file(filename);
    
//     if (!file.is_open()) { 
//         std::cerr << "Unable to write to file: " << filename << std::endl;
//         return;
//     }

//     file.close();
// }