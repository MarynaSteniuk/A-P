#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
using namespace std;
class Employee {
private:
    string lastName;       //прізвище співробітника
    string department;     //відділ
    int yearOfEmployment;  //рік працевлаштування
    float salary;          //зарплата
    float bonus;           //премія
public:
    Employee(); //конструктор за замовчуванням
    Employee(string ln, string dep, int year, float sal); //конструктор із параметрами
    void input(); //введення даних
    void output() const; //виведення даних
    void calculateBonus(int currentYear);  //метод для розрахунку премії
    //дружні функції
    friend float calculateAverageExperience(const vector<Employee>& employees, int currentYear);     //обчислення середнього стажу
    friend void sortEmployeesByExperience(vector<Employee>& employees);    //сортування співробітників за стажем
    friend void analyzeDepartments(const vector<Employee>& employees); //аналіз відділів (кількість працівників та загальна зарплата)
    //гетери
    string getDepartment() const;
    float getSalary() const;
    int getYearOfEmployment() const;
    float getBonus() const;
};

#endif
