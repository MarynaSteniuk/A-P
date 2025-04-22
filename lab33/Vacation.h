#ifndef VACATION_H
#define VACATION_H

#include "Employee.h"
#include <string>
using namespace std;
class Vacation {
private:
    Employee employee; //співробітник
    string startDate; //дата початку
    int duration; //тривалість відпустки
    string endDate; //дата закінчення
    void calculateDuration(); //обчислення тривалості
public:
    Vacation(const Employee& emp, string start = "01.07.2021"); //конструктор
    void displayVacation() const; //вивід інформації
};

#endif
