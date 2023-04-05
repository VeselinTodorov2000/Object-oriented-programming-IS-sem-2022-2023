#include <iostream>
#include <cstring>

enum DriverLicenceExceptionType {
    ILLEGAL = 16,
    WITH_PASSAGER = 17,
};

//void getDriverLicence(int age) {
//    try {
//        if(age <= 16) {
//            throw ILLEGAL;
//        } else if(age == 17) {
//            throw WITH_PASSAGER;
//        } else if (age >= 18) {
//            std::cout << "You are allowed to drive" << std::endl;
//        }
//    } catch (DriverLicenceExceptionType driverLicenceExceptionType) {
//        if(driverLicenceExceptionType == ILLEGAL) {
//            std::cout << "You are underage" << std::endl;
//        } else {
//            std::cout << "You need a passager" << std::endl;
//        }
//    } catch (std::domain_error* exception) {
//        std::cout << exception->what() << std::endl;
//    }
//}

class Employee {
private:
    char name[30];

public:
    explicit Employee(const char *name);

    friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
};

std::ostream& operator<<(std::ostream& out, const Employee& employee) {
    out << employee.name;
    return out;
}

Employee::Employee(const char *name) {
    strcpy(this->name, name);
}

int main() {
    Employee e("Ivan Ivanov");
    std::cout << e << std::endl;
//    operator<<(std::cout, e);




    return 0;
}





