#include <iostream>
#include "Vector.h"

int main() {
    Vector v;
    v.push_back(3);
    v.push_back(4);
//    for(int elem : v) {
//        std::cout << elem;
//    }
    for(Vector::Iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it;
    }
    return 0;
}
