#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <memory>
#include <string>
#include <bitset>
#include <sstream>
#include <unordered_map>
#include "file_reader.h"
#include "encoder.h"
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Insufficient arguments. Please provide the name of the input file and options." << std::endl;
        std::cout << "Options are of the form:" << std::endl;
        std::cout << "1. ./Zippy -encode <filename/path>" << std::endl;
        std::cout << "2. ./Zippy -decode <binary filename" << std::endl;
        return 1;
    }
    std::string option = argv[1];
    if (option != "-encode" && option != "-decode") {
        std::cout << "Incorrect options provided." << std::endl;
        return 1;
    }
    std::string file_name = argv[2];

    if (option == "-encode") {
        file_reader reader(file_name); 
        std::string content = reader.read();
        encoder encode(content);
        encode.build_queue();
        std::shared_ptr<node> root = encode.make_tree();
        std::unordered_map<std::string, char> store = encode.get_codes(root);
        std::unordered_map<char, std::string> store_inverse;
        for (auto i : store) {
            store_inverse[i.second] = i.first; 
        }

        std::string encoding_map_string = encode.create_encoding_string(store);

        std::string binary_store_string;
        for (const auto &c: encoding_map_string) {
            binary_store_string += std::bitset<8>(c).to_string();
        }

        encode.create_intermediate_file(store_inverse, binary_store_string);
        
        std::string compression_command = "python3 compress.py " + std::to_string(encoding_map_string.length());
        system(compression_command.c_str());
    } else {
        std::string decompression_command = "python3 decompress.py " + file_name;
        system(decompression_command.c_str());
    }
}
