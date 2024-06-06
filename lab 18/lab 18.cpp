#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Vector {
private:
    T x;
    T y;

public:
    // Конструктор
    Vector(T x = 0, T y = 0) : x(x), y(y) {}

    // Метод для отримання довжини вектора
    T length() const {
        return sqrt(x * x + y * y);
    }

    // Перевантаження оператора віднімання
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y);
    }

    // Перевантаження операторів порівняння за довжиною
    bool operator<(const Vector& other) const {
        return this->length() < other.length();
    }

    bool operator>(const Vector& other) const {
        return this->length() > other.length();
    }

    // Перевантаження оператора виводу
    friend ostream& operator<<(ostream& os, const Vector& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int main() {
    Vector<double> v1(3.0, 4.0);
    Vector<double> v2(1.0, 2.0);

    cout << "Vector v1: " << v1 << endl;
    cout << "Vector v2: " << v2 << endl;

    Vector<double> v3 = v1 - v2;
    cout << "v1 - v2 = " << v3 << endl;

    if (v1 < v2) {
        cout << "v1 is shorter than v2" << endl;
    }
    else if (v1 > v2) {
        cout << "v1 is longer than v2" << endl;
    }
    else {
        cout << "v1 is equal in length to v2" << endl;
    }

    return 0;
}