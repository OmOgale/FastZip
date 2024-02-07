#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include "file_reader.h"
#include "encoder.h"
#include "decoder.h"
#include <vector>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "Please provide the name of the input file" << std::endl;
        return 1;
    } 
    std::string file_name = argv[1];
    file_reader reader(file_name); 
    std::string content = reader.read();
    encoder encode(content);
    encode.build_queue();
    std::shared_ptr<node> root = encode.make_tree();
    std::unordered_map<std::string, char> store = encode.get_codes(root);
    decoder decode(store);
    std::unordered_map<char, std::string> store_inverse;
    for (auto i : store) {
        store_inverse[i.second] = i.first; 
    }
    std::string result;
    std::ofstream fout("intermediate.txt");
    for (auto c : content) {
        result += store_inverse[c];
    }
    fout << result;
    
    const char* compression_command = "python3 compress.py";
    system(compression_command);

    decode.create_decoded_file();
}
