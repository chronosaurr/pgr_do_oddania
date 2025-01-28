#include <iostream>
#include <cmath>

class Rectangle {
private:
    double a; // Bok a
    double b; // Bok b

public:
    Rectangle(double a, double b) {
        this->a = a;
        this->b = b;
    }
    double obliczPole() {
        return a * b;
    }
    double obliczPrzekatna() {
        return sqrt(a * a + b * b);
    }
};

int main() {
    double a, b;
    std::cout << "Podaj bok a: ";
    std::cin >> a;
    std::cout << "Podaj bok b: ";
    std::cin >> b;

   
    Rectangle rectangle(a, b);
    double pole = rectangle.obliczPole();
    double przekatna = rectangle.obliczPrzekatna();

    
    std::cout << "Pole prostokąta: " << pole << std::endl;
    std::cout << "Przekątna prostokąta: " << przekatna << std::endl;

    return 0;
}
