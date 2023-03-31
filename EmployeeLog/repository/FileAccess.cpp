#pragma once

#include "../models/Employee.h"
#include <fstream>
#include <iostream>
#include <cstring>

struct FileAccess {
public:
    static void printAllEmployees() {
        unsigned numberOfEmployees = findNumberOfEmployees();
        Employee currentEmployee;
        std::fstream file(FILENAME, std::ios::in | std::ios::binary);
        for (int i = 0; i < numberOfEmployees; i++) {
            file.read((char *) &currentEmployee, sizeof(Employee));
            currentEmployee.print();
        }
        file.close();
    }

    static void addEmployee(const Employee &employee) {
        std::fstream file(FILENAME, std::ios::out | std::ios::binary | std::ios::app);
        file.write((char*)&employee, sizeof(Employee));
        file.close();
    }

    static void updateEmployeeByName(const Employee &employee) {
        std::fstream file(FILENAME, std::ios::out | std::ios::in | std::ios::binary);
        Employee currentEmployee;
        file.seekg(0);
        while(file.read((char*)&currentEmployee, sizeof(Employee))
        && strcmp(currentEmployee.name, employee.name) != 0)
        {}

        if(strcmp(currentEmployee.name, employee.name) == 0) {
            file.seekp(file.tellg()-sizeof(Employee));
        }
        file.write((char*)&employee, sizeof(Employee));
        file.close();
    }

    static void deleteEmployeeByName(const char* name) {
        unsigned numberOfEmployees = findNumberOfEmployees();
        Employee employees[100];
        std::fstream input(FILENAME, std::ios::in | std::ios::binary);
        for (int i = 0; i < numberOfEmployees; i++) {
            input.read((char *) &employees[i], sizeof(Employee));
        }
        input.close();

        std::fstream output(FILENAME, std::ios::out | std::ios::binary);
        output.seekp(0);
        for(int i = 0; i <= numberOfEmployees; i++) {
            if(strcmp(employees[i].name, name) != 0) {
                output.write((char*) &employees[i], sizeof(Employee));
            }
        }
        output.close();
    }
private:
    constexpr static const char FILENAME[30] = "../File.bin";

    static unsigned findNumberOfEmployees() {
        std::fstream file(FILENAME, std:: ios::in | std::ios::binary);
        if (file.is_open()) {
            file.seekg(0, std::ios::end);
            unsigned numberOfEmployees = file.tellg() / sizeof(Employee);
            file.close();
            return numberOfEmployees;
        }
        return 0;
    }
};