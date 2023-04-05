#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void getId() {
        std::cout << 3;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s = Singleton::getInstance();
    s->getId();
    return 0;
}






