#include <iostream>
#include "Employee.h"
#include "Vacation.h"
#include <vector>
using namespace std;
int main() 
{
    vector<Employee> employees = {
        Employee("Petrenko", "IT", 2010, 15000),
        Employee("Ivanenko", "HR", 2005, 14000),
        Employee("Shevchenko", "Finance", 1995, 20000)
    };
    cout << "Dani pro pracivnykiv:\n";
    for (const auto& emp : employees) 
	{
        emp.output();
    }
    //аналіз відділів
    cout << "\nAnaliz viddiv:\n";
    analyzeDepartments(employees);
    //створення відпусток
    vector<Vacation> vacations;
    for (const auto& emp : employees) 
	{
        vacations.emplace_back(emp);
    }
    cout << "\nVidpustky pracivnykiv:\n";
    for (const auto& vac : vacations) {
        vac.displayVacation();
    }
    return 0;
}
