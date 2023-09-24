#ifndef HUFFMAN_DECODER_H
#define HUFFMAN_DECODER_H

#include <iostream>
#include <fstream>
using namespace std;

struct HuffmanNode {
    char data;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char d) : data(d), left(nullptr), right(nullptr) {}
};

class HuffmanDecoder {
public:
    HuffmanDecoder(HuffmanNode* root);
    void decodeTextFile(ifstream& inputFile, ofstream& outputFile);

private:
    HuffmanNode* root;

    void decodeNode(ifstream& inputFile, ofstream& outputFile, HuffmanNode* current);
};

#endif