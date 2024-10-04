#ifndef HUFFMAN_H  // Include guard
#define HUFFMAN_H

#include <string>

struct Node {
    std::string token;
    size_t count;
    Node* left;
    Node* right;

    // Leaf Node
    Node(const std::string& token, size_t count)
    : token(token), count(count), left(nullptr), right(nullptr) {}

    // Parent Node
    Node(size_t count, Node* left, Node* right)
        : token(""), count(count), left(left), right(right) {}

    bool isLeaf() const {
        return !token.empty(); 
    }
};

Node* buildHuffmanTree(std::unordered_map<std::string, size_t>& tokenCounts);

void deleteHuffmanTree(Node* node);

#endif // HUFFMAN_H