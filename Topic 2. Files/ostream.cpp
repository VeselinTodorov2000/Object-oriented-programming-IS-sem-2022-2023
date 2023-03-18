#include <iostream>
#include <fstream>

int main() {
    std::fstream file;//("File.txt",
                      //std::ios_base::out |
                      //std::ios_base::trunc);

    file.open("File.txt");

    if(file.is_open()) {
        file << "Hello Ivan!" << std::endl;
    }
    if(file) {
        file << "Hello Ivan!" << std::endl;
    }

    file.close();

    return 0;
}