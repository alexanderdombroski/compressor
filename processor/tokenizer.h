#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <unordered_map>
#include <string>

std::unordered_map<std::string, size_t> countBigrams(const std::vector<std::string>& strings);

#endif