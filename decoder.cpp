#include <fstream>
#include "decoder.h"
using namespace std;

void decoder::create_decoded_file() {
    file_reader file("intermediate.txt");
    string content = file.read();
    ofstream decoded_file("decoded.txt");
    string intermediate;
    for (int start = 0; start < content.length(); ++start) {
        intermediate += content[start];
        auto it = store.find(intermediate);
        if (it != store.end()) {
            decoded_file << store[intermediate];
            intermediate = "";
        }
    }
}
