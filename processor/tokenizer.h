#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <unordered_map>
#include <string>
#include <utility>
#include <vector>

std::pair<std::vector<std::string>, std::unordered_map<std::string, size_t>> tokenize(std::vector<std::string>& strings);

#endif