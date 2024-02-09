#ifndef ENCODER_H
#define ENCODER_H

#include <fstream>
#include <memory>
#include <queue>
#include <vector>
#include "node.h"
#include <unordered_map>

class compare {
public:
    bool operator()(std::shared_ptr<node> a, std::shared_ptr<node> b) {
        return a->get_val() >= b->get_val();
    }
};
class encoder {
public:
    encoder(){};
    encoder(std::string content): content(content){};
    void build_queue();
    std::shared_ptr<node> make_tree();
    std::unordered_map<std::string, char> get_codes(std::shared_ptr<node> root);
    std::string create_encoding_string(std::unordered_map<std::string, char> encoding_map);
    void create_intermediate_file(std::unordered_map<char, std::string> encoding_map_inverse, std::string binary_store_string);

private:
    std::priority_queue<std::shared_ptr<node>, std::vector<std::shared_ptr<node> >, compare> q;
    std::string content;
};

#endif
