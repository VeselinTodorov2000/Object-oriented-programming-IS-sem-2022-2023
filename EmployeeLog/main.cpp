#include <iostream>

#include "repository/FileAccess.cpp"

int main() {
    Employee employees[3];
    employees[0] = {"Ivan Petrov",
                    20,
                    RoleType::DEVELOPER,
                    "ivan.petrov@gmail.com",
                    "0888333666"};
    employees[1] = {"Dimitar Popov",
                    33,
                    RoleType::DEVOPS,
                    "dimitar.popov@gmail.com",
                    "0888333667"};
    employees[2] = {"Ludmila Ivanova",
                    26,
                    RoleType::QUALITY_ASSURANCE,
                    "ludmila.ivanova@yahoo.com",
                    "0888333662"};
    FileAccess f;
    f.addEmployee(employees[0]);
    f.addEmployee(employees[1]);
    f.addEmployee(employees[2]);

    f.printAllEmployees();

    Employee updatedEmployee = employees[1];
    ++updatedEmployee.age;
    updatedEmployee.roleType = RoleType::DEVOPS;

    f.deleteEmployeeByName(employees[0].name);
    f.printAllEmployees();
    return 0;
}
