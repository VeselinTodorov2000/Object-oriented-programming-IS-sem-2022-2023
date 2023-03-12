#pragma once

struct Person {
    char name[30];
    int age;
    char workplace[50];
    bool isMan;

    int getAge() const {
        return age;
    }
};