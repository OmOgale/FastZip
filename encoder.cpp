#include "encoder.h"
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <iostream>

void encoder::build_queue() {
    std::unordered_map<char, int> freq;
    for (char c : this->content) {
        if (c == '\n') {
            continue; 
        }
        freq[c]++; 
    }
    for (auto i : freq) {
        auto n = std::make_shared<node>(i.second, i.first);
        this->q.push(n);
    }
}

std::shared_ptr<node> encoder::make_tree() {
    while (this->q.size() != 1) {
        auto n1 = q.top();
        q.pop();
        auto n2 = q.top();
        q.pop();
        auto parent_val = n1->get_val() + n2->get_val();
        auto parent = std::make_shared<node>(parent_val, '*');
        parent->left = n1;
        parent->right = n2;
        q.push(parent);
    }
    return q.top();
}
void traverse(std::unordered_map<std::string, char>& store,
        std::shared_ptr<node> root,
        std::string sequence) {
    if (root == nullptr) {
        return; 
    } else if (root->left == nullptr && root->right == nullptr) {
        store[sequence] = root->get_key();
    }
    traverse(store, root->left, sequence + "0"); 
    traverse(store, root->right, sequence + "1");
}

std::unordered_map<std::string, char> encoder::get_codes(std::shared_ptr<node> root) {
    std::unordered_map<std::string, char> store;
    traverse(store, root, ""); 
    return store;
}
