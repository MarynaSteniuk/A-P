#include "Employee.h"
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
Employee::Employee() : lastName("Nevidomo"), department("Nevidomo"), yearOfEmployment(2000), salary(0.0), bonus(0.0) {} //конструктор за замовчуванням
Employee::Employee(string ln, string dep, int year, float sal) : lastName(ln), department(dep), yearOfEmployment(year), salary(sal), bonus(0.0) {} //конструктор із параметрами
//введення даних співробітника
void Employee::input()
{
    cout << "Prizvuche: ";
    cin >> lastName;
    cout << "Viddil: ";
    cin >> department;
    cout << "Rik pracevlashtyvanna: ";
    cin >> yearOfEmployment;
    cout << "Zarplata: ";
    cin >> salary;
}
//виведення даних співробітника
void Employee::output() const 
{
    cout << "Prizvuche: " << lastName<< ", Viddil: " << department<< ", Rik pracevlashtyvanna: " << yearOfEmployment<< ", Зарплата: " << salary<< ", Премія: " << bonus << endl;
}
//розрахунок премії на основі стажу
void Employee::calculateBonus(int currentYear) 
{
    int experience = currentYear - yearOfEmployment;
    if (experience < 10) 
	{
        bonus = 0.1 * salary;
    } 
	else if (experience <= 25) 
	{
        bonus = 0.25 * salary;
    } 
	else 
	{
        bonus = 0.4 * salary;
    }
}
//гетери для доступу до приватних полів
string Employee::getDepartment() const { return department; }
float Employee::getSalary() const { return salary; }
int Employee::getYearOfEmployment() const { return yearOfEmployment; }
float Employee::getBonus() const { return bonus; }
//дружня функція для обчислення середнього стажу
float calculateAverageExperience(const vector<Employee>& employees, int currentYear) 
{
    int totalExperience = 0; //змінна для збереження загального стажу роботи всіх співробітників
    for (const auto& employee : employees) { //проходимо через кожного співробітника у векторі
        totalExperience += currentYear - employee.yearOfEmployment; //додаємо стаж роботи співробітника (поточний рік мінус рік працевлаштування)
    }
    return static_cast<float>(totalExperience) / employees.size(); //загальний стаж ділимо на кількість співробітників
}
//дружня функція для сортування співробітників за стажем
void sortEmployeesByExperience(vector<Employee>& employees) {
    sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.yearOfEmployment < b.yearOfEmployment;
    });
}
//дружня функція для аналізу відділів
void analyzeDepartments(const vector<Employee>& employees) {
    map<string, pair<int, float>> departmentData;
    // Збираємо дані по кожному відділу
    for (const auto& employee : employees) {
        departmentData[employee.department].first++;        //кількість працівників
        departmentData[employee.department].second += employee.salary; //загальна зарплата
    }
    //виводимо результати аналізу
    for (const auto& [department, data] : departmentData) 
	{
        cout << "Viddil: " << department<< ", K-t pracivnukiv: " << data.first<< ", Zagalna zarplata: " << data.second << endl;
    }
}

