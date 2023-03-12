#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

struct Triangle {
    Point a;
    Point b;
    Point c;

    double perimeter() const {
        return sideA() + sideB() + sideC();
    }

    double area() const {
        double a = sideA();
        double b = sideB();
        double c = sideC();
        double p = perimeter() / 2;

        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    double sideA() const {
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    }

    double sideB() const {
        return sqrt((a.x - c.x)*(a.x - c.x) + (a.y - c.y)*(a.y - c.y));
    }

    double sideC() const {
        return sqrt((b.x - c.x)*(b.x - c.x) + (b.y - c.y)*(b.y - c.y));
    }
};

int main() {
    Triangle *t = new Triangle{{0, 0},
                               {3, 0},
                               {0, 4}};

    std::cout << t->perimeter() << std::endl;
    std::cout << t->area() << std::endl;

    delete t;
    return 0;
}