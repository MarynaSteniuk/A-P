#include <iostream>
#include "Employee.h"
#include "Employee.cpp"
using namespace std;

int main() 
{
    const int N = 3;
    Employee employees[N]; // масив об'єктів класу Employee
    int currentYear = 2025; // поточний рік
    //створення об'єкта з параметрами
    Employee *defauoltEmp = new Employee();
    defauoltEmp->output();
	Employee emp("Petrenko", "IT", 2020, 15000);
    cout << "\nDani pro pracivnuka, stworeno za dopomogoyu konstruktoru z parametramy:\n";
    emp.output();
    //введення даних для масиву співробітників
    for (int i = 0; i < N; i++) {
        cout << "Pracivnuk #" << i + 1 << endl;
        employees[i].input();
        employees[i].calculateBonus(currentYear);
    }
    //виведення даних про співробітників
    cout << "\nDani pro pracivnukiv:\n";
    for (int i = 0; i < N; i++) {
        employees[i].output();
    }
    //обчислення середнього стажу роботи
    float averageExperience = calculateAverageExperience(employees, N, currentYear);
    cout << "\nSeredniu stag robotu: " << averageExperience << " rokiv" << endl;
    //сортування співробітників за стажем роботи
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (employees[j].getYearOfEmployment() > employees[j + 1].getYearOfEmployment()) {
                swap(employees[j], employees[j + 1]);
            }
        }
    }
    //виведення відсортованих співробітників
    cout << "\nVidsortovani pracivnuku za stagem robotu:\n";
    for (int i = 0; i < N; i++) {
        employees[i].output();
    }
    return 0;
}
