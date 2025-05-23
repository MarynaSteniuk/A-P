#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

//абстрактний клас "Фігура"
class Figure {
public:
    virtual double area() const = 0; //віртуальна функція для обчислення площі
    virtual double perimeter() const = 0; //віртуальна функція для обчислення периметру
    virtual ~Figure() = default;  //віртуальний деструктор
};

class Rectangle : public Figure {
private:
    double width;  //ширина
    double height; //висота

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height; //площа=ширина×висота
    }

    double perimeter() const override {
        return 2 * (width + height); //периметр=2×(ширина+висота)
    }
};

class Triangle : public Figure {
private:
    double a, b, c; //сторони трикутника

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}
    double area() const override {
        double s = (a + b + c) / 2; //напівпериметр
        return sqrt(s * (s - a) * (s - b) * (s - c)); //формула Герона
    }

    double perimeter() const override {
        return a + b + c; //периметр=сума сторін
    }
};

class Circle : public Figure {
private:
    double radius; 

public:
    Circle(double r) : radius(r) {}

    double area() const override 
	{
        return M_PI * radius * radius; //площа=π×r²
    }

    double perimeter() const override 
	{
        return 2 * M_PI * radius; //периметр=2×π×r
    }
};
int main() 
{
    vector<shared_ptr<Figure>> figures; //вектор для зберігання об'єктів типу "Фігура"
    //додавання різних фігур до вектора
    figures.push_back(make_shared<Rectangle>(5.0, 10.0));
    figures.push_back(make_shared<Triangle>(3.0, 4.0, 5.0));
    figures.push_back(make_shared<Circle>(7.0));
    for (const auto& figure : figures) //виведення площі та периметру кожної фігури
	{
        cout << "Area: " << figure->area() << ", Perimeter: " << figure->perimeter() << endl;
    }
    return 0;
}
