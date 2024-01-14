#include <iostream>
using namespace std;
//класс Fraction(Дробь)
class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cout << "Ошибка: знаменатель не может быть равен 0!" << "\n";
        }
        simplify();
    }
    void simplify() {
        int gcd = gcd_recursive(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    int gcd_recursive(int a, int b) {
        if (b == 0) return a;
        return gcd_recursive(b, a % b);
    }
    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }
    Fraction operator-(const Fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "Ошибка: деление на ноль!" << "\n";
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    Fraction& operator++() {
        numerator += denominator;
        simplify();
        return *this;
    }
    Fraction operator++(int) {
        Fraction temp(*this);
        ++(*this);
        return temp;
    }
    void display() const {
        cout << numerator << "/" << denominator;
    }
    operator double() const {
        return static_cast<double>(numerator) / denominator;
    }
    Fraction operator*(int value) const {
        int new_num = numerator * value;
        return Fraction(new_num, denominator);
    }
    friend Fraction operator*(int value, const Fraction& fraction) {
        return fraction * value;
    }
};
int main()
{
    setlocale(LC_ALL, "RUS");
    Fraction a(5, 2);
    Fraction b(5, 6);

    Fraction product1 = a * b;
    cout << "Произведение двух дробей: ";
    product1.display();
    cout << "\n";

    Fraction product2 = a * 3;
    cout << "Умножение дроби на целое число: ";
    product2.display();  
    cout << "\n";

    Fraction product3 = 4 * b;
    cout << "Умножение целого числа на дробь: ";
    product3.display();  
    cout << "\n";
}
