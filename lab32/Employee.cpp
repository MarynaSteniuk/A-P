#include "Employee.h"
#include <iostream>
using namespace std;
//конструктор за замовчуванням
Employee::Employee() {
    lastName = "Nevidomo";
    department = "Nevidomo";
    yearOfEmployment = 2000;
    salary = 0.0;
    bonus = 0.0;
}
//конструктор із параметрами
Employee::Employee(string ln, string dep, int year, float sal) {
    lastName = ln;
    department = dep;
    yearOfEmployment = year;
    salary = sal;
    bonus = 0.0;
}
//метод для введення даних
void Employee::input() {
    cout << "Prizvuche: ";
    cin >> lastName;
    cout << "Viddil: ";
    cin >> department;
    cout << "Pik pracevlashtyvana: ";
    cin >> yearOfEmployment;
    cout << "Zarplata: ";
    cin >> salary;
}
//метод для виведення даних
void Employee::output() const {
    cout << "Prizvuche: " << lastName<< " Viddil: " << department<< " Pik pracevlashtyvana: " << yearOfEmployment<< " Zarplata: " << salary<< " Premia: " << bonus << endl;
}
//метод для розрахунку премії
void Employee::calculateBonus(int currentYear) {
    int experience = currentYear - yearOfEmployment;
    if (experience < 10) {
        bonus = 0.1 * salary;
    } else if (experience <= 25) {
        bonus = 0.25 * salary;
    } else {
        bonus = 0.4 * salary;
    }
}
//гетери
int Employee::getYearOfEmployment() const { return yearOfEmployment; }
float Employee::getSalary() const { return salary; }
float Employee::getBonus() const { return bonus; }
//глобальна функція для розрахунку середнього стажу
float calculateAverageExperience(const Employee employees[], int size, int currentYear) {
    int totalExperience = 0;
    for (int i = 0; i < size; i++) {
        totalExperience += currentYear - employees[i].getYearOfEmployment();
    }
    return static_cast<float>(totalExperience) / size;
}
