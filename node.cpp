#include "node.h"
#include <memory>

char node::get_key() {
    return this->key;
}

int node::get_val() {
    return this->val;
}
