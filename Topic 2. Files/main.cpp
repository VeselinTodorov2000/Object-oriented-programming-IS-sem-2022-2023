#include <iostream>
#include <cstring>

struct A {
private:
    char name[30];
    bool isMale;

public:
    A(const char* _name, bool _isMale){
        setName(_name);
        isMale = _isMale;
    }

    char* getName() {
        return name;
    }

    void setName(const char* name) {
        if(name != nullptr) {
            strcpy_s(this->name, 30, name);
        }
    }
};

int main() {
    A a = A{"Ivan Ivanov", true};
    return 0;
}
