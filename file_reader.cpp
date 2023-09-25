#include "file_reader.h"
#include <string>

std::string file_reader::read() {
    std::string curr_line;
    std::string result = "";
    while (std::getline(this->file, curr_line)) {
        result += curr_line; 
        result.push_back('\n');
    }
    return result;
}
