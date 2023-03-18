#include <iostream>
#include <fstream>
#include <cassert>

int main() {
    std::ifstream input("File.txt");

    char name[20];
//    if(input.is_open()) {
//        input >> name;
//    }

//    if(input.is_open()) {
//        input.getline(name, 20);
//    }

//    if(input.is_open()) {
//        char c = input.get();
//        assert(c == 'H');
//        c = input.get();
//        assert(c != 'e');
//    }

//    if(input.is_open()) {
//        char c = input.peek();
//        assert(c == 'H');
//        c = input.peek();
//        assert(c != 'e');
//    }

//    char c;
//    while(!input.eof()) {
//        c = input.get();
//        std::cout << c << "\n";
//    }

//    while(input.getline(name, 20)) {
//        std::cout << name << std::endl;
//    }

//    std::cout << name << std::endl;
    return 0;
}