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
    Student students[3] = {
            {1, "Ivan Ivanov",    5.0},
            {2, "Petar Stoyanov", 4.2},
            {3, "Traicho Petrov", 2}
    };

//    std::ofstream out("../Student.bin", std::ios::binary);
//
//    for(int i = 0; i < 3; i++) {
//        out.write((char*)&students[i], sizeof (Student));
//    }
//    out.close();

    Student students2[3];
    std::ifstream input("../Student.bin", std::ios::binary);
    for(int i = 0; i < 3; i++) {
        input.read((char*)&students2[i], sizeof (Student));
    }

    assert(strcmp(students2[2].name, "Traicho Petrov") == 0);
    input.close();






//    std::fstream output("Students.txt", std::ios::out);

//    for (int i = 0; i < 3; i++) {
//        output << students[i].fn << std::endl
//               << students[i].name << std::endl
//               << students[i].grade << std::endl;
//    }
//
//    output.close();
//    Student students2[3];
//    std::ifstream input("Students.txt");
//
//    for (int i = 0; i < 3; i++) {
//        input >> students2[i].fn;
//        input.get();
//        input.getline(students2[i].name, 30);
//        input >> students2[i].grade;
//        input.get();
//    }
//
//    assert(strcmp(students2[2].name, "Traicho Petrov") == 0);
    return 0;
}







