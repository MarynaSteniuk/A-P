#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    string lastName; // прізвище
    string department; // відділ
    int yearOfEmployment; // рік працевлаштування
    float salary; // зарплата
    float bonus; // премія

public:
    Employee(); // конструктор за замовчуванням
    Employee(string ln, string dep, int year, float sal); // конструктор із параметрами
    void input(); // введення даних
    void output() const; // виведення даних
    void calculateBonus(int currentYear); // розрахунок премії

    // гетери
    int getYearOfEmployment() const;
    float getSalary() const;
    float getBonus() const;
};

// Глобальна функція для розрахунку середнього стажу
float calculateAverageExperience(const Employee employees[], int size, int currentYear);

#endif
