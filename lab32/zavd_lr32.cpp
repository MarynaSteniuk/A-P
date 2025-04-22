#include <iostream>
#include <string>
using namespace std;

//оголошуємо клас Employee
class Employee {
private:
    string lastName; //прізвище
    string department; //відділ
    int yearOfEmployment; //рік працевлаштування
    float salary; //зарплата
    float bonus; //премія

public:
	Employee() //конструктор за замовчуванням
	{
        lastName="Невідомо";
        department="Невідомо";
        yearOfEmployment=2000;
        salary=0.0;
        bonus=0.0;
    }
    Employee(string ln, string dep, int year, float sal) //конструктор із параметрами
	{
        lastName=ln;
        department=dep;
        yearOfEmployment=year;
        salary=sal;
        bonus=0.0;
    }
    void input() //введення даних
	{
        cout<<"Prizvuche: "; 
        cin>>lastName;
        cout<<"Viddil: ";
        cin>>department;
        cout<<"Pik pracevlashtyvana: ";
        cin>>yearOfEmployment;
        cout<<"Zarplata: ";
        cin>>salary;
    }
    void output() const //виведення даних
	{
        cout<<"Prizvuche: "<<lastName<<" Viddil: "<<department<<" Pik pracevlashtyvana: "<<yearOfEmployment<<" Zarplata: "<<salary<<" Premia: "<< bonus << endl;
    }

    //розрахунок премії
    void calculateBonus(int currentYear) {
        int experience = currentYear - yearOfEmployment;
        if (experience < 10) {
            bonus = 0.1 * salary;
        } else if (experience <= 25) {
            bonus = 0.25 * salary;
        } else {
            bonus = 0.4 * salary;
        }
    }
//гетери для отримання даних
    int getYearOfEmployment() const { return yearOfEmployment; }
    float getSalary() const { return salary; }
    float getBonus() const { return bonus; }
};
//функція для розрахунку середнього стажу роботи
float calculateAverageExperience(const Employee employees[], int size, int currentYear) {
    int totalExperience = 0;
    for (int i = 0; i < size; i++) {
        totalExperience += currentYear - employees[i].getYearOfEmployment();
    }
    return static_cast<float>(totalExperience) / size; //перетворюємо totalExperience з int у float щоб зберегти десяткову частину результату
}

int main() {
    const int N = 3; 
    Employee employees[N]; //масив об'єктів класу Employee
    int currentYear=2025; //поточний рік
    Employee emp("Petrenko", "IT", 2010, 15000); // створення об'єкта з параметрами
    cout << "\nDani pro pracivnuka, stworeno za dopomogoyu konstruktoru z parametramy:\n";
    emp.output(); // вивід даних створеного об'єкта

    for (int i=0; i<N; i++) //введення даних для співробітників 
	{
        cout<<"Pracivnuk #"<<i+1<< endl;
        employees[i].input();
        employees[i].calculateBonus(currentYear);
    }
    cout << "\nDani pro pracivnukiv:\n";     // виведення даних про співробітників
    for (int i=0; i<N; i++) 
	{
        employees[i].output();
    }
    float averageExperience=calculateAverageExperience(employees, N, currentYear);   //обчислення середнього стажу роботи
    cout<<"\nSeredniu stag robotu: "<<averageExperience<<" rokiv"<<endl;
    //сортування масиву співробітників за стажем роботи (за зростанням) 
    for (int i=0; i<N-1; i++) //проходимо по всіх елементах масиву крім останнього
	 {
        for (int j=0; j<N-i-1; j++) //порівнює пари сусідніх елементів
		{
            if (employees[j].getYearOfEmployment() > employees[j + 1].getYearOfEmployment()) //якщо рік працевлаштування співробітника j більший ніж у співробітника j + 1  то j має менший стаж
			{
                swap(employees[j], employees[j + 1]);  //нового співробітника переміщуємо вправо
            }
        }
    }
    cout << "\nVidsortovani pracivnuku za stagem robotu:\n";  //виведення відсортованих співробітників
    for (int i=0; i<N; i++) 
	{
        employees[i].output();
    }
    return 0;
}

