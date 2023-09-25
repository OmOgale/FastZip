#ifndef NODE_H
#define NODE_H

#include <memory>
#include <vector>

class node {
public:
    node(int val, char key): val(val), key(key), left(nullptr), right(nullptr) {};
    char get_key();
    int get_val();
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;

private:
    int val;
    char key;
};

#endif
