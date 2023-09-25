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

private:
    std::priority_queue<std::shared_ptr<node>, std::vector<std::shared_ptr<node> >, compare> q;
    std::string content;
};
