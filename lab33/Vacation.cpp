#include "Vacation.h"
#include <iostream>
using namespace std;
Vacation::Vacation(const Employee& emp, string start) : employee(emp), startDate(start) 
{
    calculateDuration();
    endDate = "Data + " + to_string(duration) + " dniv"; //обчислення дати закінчення 
}
void Vacation::calculateDuration() {
    int experience = 2025 - employee.getYearOfEmployment(); //досвід
    if (experience < 10 && employee.getSalary() < 12000) {
        duration = 14; //тривалість
    } else if (experience > 25 && employee.getSalary() > 25000) {
        duration = 28;
    } else {
        duration = 21;
    }
}
void Vacation::displayVacation() const {
    cout << "Spivrobitnyk: ";
    employee.output();
    cout << "Pochatok: " << startDate<< ", Trivalist: " << duration<< " dniv, Zakincennia: " << endDate << endl;
}
