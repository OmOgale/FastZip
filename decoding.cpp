#include <fstream>
#include <decoding.h>
using namespace std;

HuffmanDecoder::HuffmanDecoder(HuffmanNode* root) : root(root) {};

void HuffmanDecoder::decodeNode(ifstream& inputFile, ofstream& outputFile, HuffmanNode* current) {
    char bit;
    while (inputFile.get(bit)) {
        if (bit == '0') {
            current = current->left;
        } else if (bit == '1') {
            current = current->right;
        }

        if (current->data != '\0') {
            outputFile.put(current->data);
            current = root;
        }
    }
}

void HuffmanDecoder::decodeTextFile(ifstream& inputFile, ofstream& outputFile) {
    HuffmanNode* current = root;
    decodeNode(inputFile, outputFile, current);
}
