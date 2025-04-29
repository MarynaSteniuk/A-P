#include <iostream>
#include <string>
using namespace std;

class Student {  //базовий клас "Школяр"
protected:
    string name;
    int yearOfBirth;
    char gender;

public:
    Student() : name(""), yearOfBirth(2000), gender('M') {}    //конструктор за замовчуванням
    int calculateAge(int currentYear)   //обчислюємо вік
	{
        return currentYear-yearOfBirth;
    }
//введення даних
    void inputData() 
	{
        cout<<"Vvedit PIP: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Vvedit rik narogennia: ";
        cin>>yearOfBirth;
        cout<<"Vvedit stat (M/F): ";
        cin>>gender;
    }
//виведення даних
    void displayData() 
	{
        cout<<"PIP: "<<name<<endl;
        cout<<"Rik narogennia: "<<yearOfBirth<<endl;
        cout<<"Stat: "<<gender<<endl;
    }
};

class Worker : public Student { //похідний клас "Працівник"
private:
    double salary;
    string workplace;

public:
    Worker(string n, int yob, char g, double s, string wp) : salary(s), workplace(wp)  //параметризований конструктор
	{
        name=n;
        yearOfBirth=yob;
        gender=g;
    }
//введення даних
    void input() 
	{
        inputData(); //виклик успадкованого методу
        cout<<"Vvedit zarplaty: ";
        cin>>salary;
        cout<<"Vvedit misce robotu: ";
        cin.ignore();
        getline(cin, workplace);
    }
//виведення даних
    void display() 
	{
        displayData();
        cout<<"Zarplata: "<<salary<<endl;
        cout<<"Misce robotu: "<<workplace<<endl;
    }
    void displayAge(int currentYear) 
	{
        cout<<"Vik: "<<calculateAge(currentYear)<< endl;
    }
};

int main() {
    Worker w("Petrenko Ivan Ivanovuch", 1995, 'M', 15000, "Zavod");
    w.display();
    w.displayAge(2025); 
    cout << "\nNew pracivnuk:\n";
    Worker w2("", 0, 'M', 0, ""); //створення працівника
    w2.input();
    w2.display();
    w2.displayAge(2025);
    return 0;
}
