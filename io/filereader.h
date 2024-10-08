
#ifndef FILEREAD_H
#define FILEREAD_H

#include <vector>

std::vector<std::string> readChunk(const std::string& filename, size_t chunkSize);
size_t getFileSize(const std::string& filename);
void writeTokens(const std::string& filename, std::vector<std::string>& filetext);


#endif