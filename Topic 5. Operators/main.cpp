#include <iostream>
#include <cassert>

class Age {
private:

    int age;
    bool overEightteen;

public:
    Age(int age) {
       this->age = age;
       this->overEightteen = age >= 18;
    }

    Age& operator=(const Age& other) {
        this->age = other.age;
        this->overEightteen = other.overEightteen;
    }

    Age operator+(const Age& other) {
        return Age(age + other.age);
    }

    bool operator==(const Age& other) {
        return this->age == other.age &&
                this->isOverEightteen() == other.isOverEightteen();
    }

    bool operator!=(const Age& other) {
        return !(*this == other);
    }

    Age& operator++() {
        this->age++;
        this->overEightteen = age >= 18;
    }

    void operator()(int age) {
        std::cout << "Hello " << age << std::endl;
    }

    int getAge() const {
        return age;
    }

    bool isOverEightteen() const {
        return overEightteen;
    }
};

int main() {
    Age a(15);
    Age b(16);
    assert(!a.isOverEightteen());
    assert(!b.isOverEightteen());

    Age c = a.operator+(b);
    Age d = a + b;

    assert(c.getAge() == 31);
    assert(c.isOverEightteen());
    assert(d.getAge() == 31);
    assert(d.isOverEightteen());

    assert(c == d);
    ++c;
    assert(c != d);

    c.operator()(3);
    c (3);
    return 0;
}
