#include <iostream>
#include <cstring>
class Employee {
private:
    char* name;
    int age;
    char* workplace;
    bool isMarried;

    void copy(const Employee& other) {
        setName(other.name);
        setAge(other.age);
        setWorkplace(other.workplace);
        setIsMarried(other.isMarried);
    }
    void destroy() {
        delete[] name;
        delete[] workplace;
    }
public:
    Employee() {
        name = nullptr;
        age = 0;
        workplace = nullptr;
        isMarried = false;
    }

    Employee(const Employee& other) {
        copy(other);
    }

    Employee& operator=(const Employee& other) {
        if(this != &other) {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Employee() {
        destroy();
    }

    void setName(const char* name) {
        if(this->name != nullptr) {
            delete[] this->name;
        }
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    const char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Employee::age = age;
    }

    void setWorkplace(const char* workplace) {
        if(this->workplace != nullptr) {
            delete[] this->workplace;
        }
        this->workplace = new char[strlen(workplace) + 1];
        strcpy(this->workplace, workplace);
    }

    const char *getWorkplace() const {
        return workplace;
    }

    bool isMarried1() const {
        return isMarried;
    }

    void setIsMarried(bool isMarried) {
        Employee::isMarried = isMarried;
    }
};

int main() {
    Employee e;
    std::cout << e.getAge() << std::endl;

    Employee b = e;
    return 0;
}







