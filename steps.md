[ ] Read a text file 
    [X] Read a single chunk

[X] Choose tokenization [method](https://chatgpt.com/c/66fc0932-4478-8005-9adc-1f6f0a7a17a1)
    [X] bi/tri gram mix
    [X] force spaces to be their own token

[X] Create Huffman Tree
    [X] Join token hashmaps
    [X] Create priority Queue
    [X] build Huffman tree

[ ] Use huffman tree to write binary instructions
    [X] Get instruction hashmap
    [ ] Iterate over tokens

[ ] Store Huffman Tree in effecient format
[ ] Store binary instructions in effecient format 

[ ] Read Format back into huffman tree
[ ] Read file and binary instructions back into text format

Other Improvements
[ ] Error Handling and Edge Cases
[X] Chunk-based File IO
[ ] Multi-Core Processing/Threading?
[X] Temporarily Store tokens in file

## Steps

**Compressing**

1. Read File in chunks
2. Tokenize Chunks
3. Combine Token Counts for each Chunk
4. Build Huffman Tree
5. Create Instruction Hashmap
6. Store Tree in File
7. Convert String Tokens to Binary
8. Store tree and binary

**Decompressing**

1. Read in tree and binary instructions
2. Decode binary into string tokens
3. Write text to file using streamwriter