#include <iostream>
#include "Colour.cpp"
#include "struct.cpp"

int main() {
    //Basic operations
    Colour colour = BLUE; //BLUE
//    std::cin >> colour; //забранена операция
    std::cout << colour << std::endl; //0

    colour = (Colour) 2; //YELLOW
    colour = (Colour) 10; //Възможно е, но няма стойност

    //Boolean operations
    Colour red = RED;
    std::cout << (red == BLUE) << std::endl; //false
    std::cout << (red != GREEN) << std::endl; //true

    std::cout << (red == 12); //Не се препоръчва


//
//    Структури
//

//Създаване
    Person p1;
    Person p2 = {"Ivan",
                 20,
                 "FMI",
                 true};


//Достъп до елементите
    std::cin >> p1.isMan;
    std::cout << p2.age << std::endl;

    p2.getAge(); //20

    //Указател
    Person* p3 = new Person{"Maria",
                            19,
                            "Sofarma LTD",
                            false};
    //Достъп
    p3->age = 20;
    (*p3).age = 20;
}
