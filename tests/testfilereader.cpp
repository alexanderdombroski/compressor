

#include "../io/filereader.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::string filename = "data/moroni10.txt";
    size_t chunkSize = 20;

    std::vector<std::string> chunk = readChunk(filename, chunkSize);


    std::cout << "Read " << chunk.size() << " lines:\n";
    for (const auto& line : chunk) {
        std::cout << line << std::endl;
    }

    return 0;
}