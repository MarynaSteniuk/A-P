#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
using namespace std;

class Employee {
private:
    string lastName; //прізвище
    string department; //відділ
    int yearOfEmployment; //рік працевлаштування
    float salary; //зарплата
    float bonus; //премія
public:
    Employee(); //конструктор за замовчуванням
    Employee(string ln, string dep, int year, float sal); //конструктор із параметрами
    void input(); //введення даних
    void output() const; //виведення даних
    void calculateBonus(int currentYear); //розрахунок премії
    //дружні функції
    friend float calculateAverageExperience(const vector<Employee>& employees, int currentYear);
    friend void sortEmployeesByExperience(vector<Employee>& employees);
    friend void analyzeDepartments(const vector<Employee>& employees);
    //гетери
    string getDepartment() const;
    float getSalary() const;
    int getYearOfEmployment() const;
    float getBonus() const;
};

#endif
