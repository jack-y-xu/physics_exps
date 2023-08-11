#include "Instance.h"

#define DEBUG(a) {std::cout << #a << " is " << a << '\n';}

int main(int argc, char** argv) {
    try {
        DEBUG(argc);
        if (argc != 4) {
            throw std::runtime_error("Invalid number of arguments.");
        }
        Instance instance(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
        instance.run();
    } catch (std::runtime_error e) {
        std::cerr << e.what() << '\n';
        std::cerr << "Usage: ./program [Ini file path: str] [nEvents: uint] [visualize: 0/1]";
    }
}
