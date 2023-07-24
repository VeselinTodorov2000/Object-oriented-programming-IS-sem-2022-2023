#include <iostream>
#include <cmath>
#include <vector>

class A {
public:
    virtual void greet() = 0; //pure virtual method
};

class B : public A {
public:
    void greet() {
        std::cout << "Hello from B" << std::endl;
    }
};

//Figure example
class Figure {
public:
    virtual double perimeter() = 0;
    virtual double area() = 0;
};

class Triangle : public Figure {
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double perimeter() override {
        return a + b + c;
    }

    double area() override {
        double halfPerimeter = perimeter() / 2;
        return sqrt(halfPerimeter * (halfPerimeter - a) *
                        (halfPerimeter - b) * (halfPerimeter - c));
    }
};

class Rectangle : public Figure {
private:
    double a, b;
public:
    Rectangle(double a, double b) : a(a), b(b) {}

    double perimeter() override {
        return 2*a + 2*b;
    }

    double area() override {
        return a*b;
    }

};

class Circle : public Figure {
private:
    double r;
public:
    Circle(double r) : r(r) {}

    double perimeter() override {
        return 2*3.14*r;
    }

    double area() override {
        return 3.14*r*r;
    }
};

class D {
    D() {

    }
};





int main() {
    Figure* first = new Triangle(3,4,5); //6
    Figure* second = new Rectangle(4,5); //20
    Figure* third = new Circle(0); //0

    std::vector<Figure*> figures;
    figures.push_back(first);
    figures.push_back(second);
    figures.push_back(third);
    for(Figure* figure : figures) {
        std::cout << figure->area() << std::endl;
    }

    D d = D();
    return 0;
}










