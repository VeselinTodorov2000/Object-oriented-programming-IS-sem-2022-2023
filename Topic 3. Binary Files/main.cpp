#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>

struct Student {
    int fn;
    char name[30];
    double grade;
};

int main() {
    const char FILENAME[30] = "../File.bin";
    std::fstream file(FILENAME, std::ios::out |
                                        std::ios::binary);
    //write text to binary file
    char greeting[10] = "Hello!";
    file.write(greeting, sizeof(greeting));
    file.close();

    //write object to binary file
    Student student[3] = {
            {1, "Ivan Ivanov", 5.20},
            {2, "Georgi Nikolov", 4.30},
            {3, "Maria Petrova", 2.00},
    };
    file.open(FILENAME, std::ios::out |
                        std::ios::binary);
    for(int i = 0; i < 3; i++) {
        file.write((char*)&student[i], sizeof(Student));
    }
    file.close();

    //read object from binary file
    Student student2[3];

    file.open(FILENAME, std::ios::in |
                        std::ios::binary);
    for(int i = 0; i < 3; i++) {
        file.read((char*)&student[i], sizeof(Student));
    }
    file.close();
    assert(strcmp(student2[2].name, "Maria Petrova"));
}
