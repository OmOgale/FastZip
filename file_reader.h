#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>

class file_reader {
private:
    std::ifstream file;
    std::string file_name;

public:
    file_reader(){};
    file_reader(std::string file_name): file_name(file_name), file(file_name) {};
    std::string read(); 
};

#endif
