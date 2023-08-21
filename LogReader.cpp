#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

int main() {
    const std::string filename = "log.txt";

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return 1;
    }

    file.seekg(0, std::ios::end);
    std::streampos startPos = file.tellg();

    while (true) {
        file.open(filename);
        file.seekg(0, std::ios::end);
        std::streampos endPos = file.tellg();

        if (endPos > startPos) {
            file.seekg(startPos);
            std::string line;
            
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }

            startPos = endPos;
        }

        file.close();
    }

    return 0;
}
