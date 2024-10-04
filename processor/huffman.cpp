#include "huffman.h"

#include <string>
#include <queue>

namespace {

    struct CompareNode {
        bool operator()(const Node* a, const Node* b) const {
            return a->count > b->count;  // ">" makes it a min-heap
        }
    };

    std::priority_queue<Node*, std::vector<Node*>, CompareNode> loadPriorityQueue(const std::unordered_map<std::string, size_t>& tokenCounts) {
        std::priority_queue<Node*, std::vector<Node*>, CompareNode> minHeap;

        for (const auto& [token, count] : tokenCounts) {
            auto* node = new Node(token, count);
            minHeap.push(node);
        }

        return minHeap;
    }


}


// Builds a huffman tree and returns head
Node* buildHuffmanTree(std::unordered_map<std::string, size_t>& tokenCounts) {
    auto minHeap = loadPriorityQueue(tokenCounts);
    std::unordered_map<std::string, size_t>().swap(tokenCounts); // Free tokenCounts from memory

    while (minHeap.size() > 1) {
        auto left = minHeap.top(); 
        minHeap.pop();
        auto right = minHeap.top();
        minHeap.pop();
        
        auto* parent = new Node(left->count + right->count, left, right);
        minHeap.push(parent);
    }
    
    return std::move(minHeap.top());
}

void deleteHuffmanTree(Node* node) {
    if (node == nullptr) return;
    deleteHuffmanTree(node->left);
    deleteHuffmanTree(node->right);
    delete node;
}
