#pragma once
#include "../enums/RoleType.h"

struct Employee {
    char name[30];
    unsigned age;
    RoleType roleType;
    char email[50];
    char phoneNumber[15];

    void print() {
        printf("Employee: %s\nAge: %d\nRole: %s\nEmail: %s\nPhone: %s\n\n",
                this->name,
                this->age,
                getRoleType(this->roleType),
                this->email,
                this->phoneNumber);
    }
};