#ifndef HUFFMAN_DECODER_H
#define HUFFMAN_DECODER_H

#include <iostream>
#include <fstream>
#include "encoder.h"
#include "file_reader.h"
#include "node.h"

using namespace std;

class decoder {
    private:
        unordered_map<string, char> store;
    
    public:
        decoder(){};
        decoder(unordered_map<string, char> store): store(store) {};
        void create_decoded_file();
};

#endif
