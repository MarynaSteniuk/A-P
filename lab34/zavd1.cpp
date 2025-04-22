#include <iostream>
#include <iomanip>
using namespace std;

class Time 
{
private:
    int hours; 
    int minutes; 
    int seconds; 
public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {} //конструктор із параметрами (за замовчуванням 0)
    ~Time() {} //деструктор класу
    void inputTime()    //метод для введення часу з клавіатури
	{
        cout << "Vvedit chas (hours minutes seconds): ";
        cin >> hours >> minutes >> seconds;
    }
    void displayTime() const {   //метод для виведення часу у форматі ГГ:ХХ:СС
        cout << setfill('0') << setw(2) << hours << ":"<< setw(2) << minutes << ":"<< setw(2) << seconds << endl; // setw(2) це ширина 2 цифри Setfill для 0 перед цифрою
    }
//перевантаження операції '+' для додавання часу
    Time operator+(const Time &t) const {
        int totalSeconds = (hours + t.hours) * 3600 + (minutes + t.minutes) * 60 + (seconds + t.seconds);
        return Time(totalSeconds / 3600, (totalSeconds / 60) % 60, totalSeconds % 60);
    }
//перевантаження операції '-' для віднімання часу
    Time operator-(const Time &t) const {
        int totalSeconds = (hours * 3600 + minutes * 60 + seconds) - (t.hours * 3600 + t.minutes * 60 + t.seconds);
        if (totalSeconds < 0) totalSeconds = 0;
        return Time(totalSeconds / 3600, (totalSeconds / 60) % 60, totalSeconds % 60);
    }
//перевантаження операції '>' для порівняння часу
    bool operator>(const Time &t) const {
        return (hours * 3600 + minutes * 60 + seconds) > (t.hours * 3600 + t.minutes * 60 + t.seconds);
    }
//перевантаження операції '<' для порівняння часу
    bool operator<(const Time &t) const {
        return (hours * 3600 + minutes * 60 + seconds) < (t.hours * 3600 + t.minutes * 60 + t.seconds);
    }
//перевантаження операції '==' для перевірки рівності часу
    bool operator==(const Time &t) const {
        return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
    }
};

int main() {
    //створення двох об'єктів часу
    Time t1(15, 30, 15);
    Time t2;
    t2.inputTime();
    //демонстрація операцій над об'єктами часу
    Time t3 = t1 + t2;
    Time t4 = t1 - t2;
    cout << "Chas 1: ";
    t1.displayTime();
    cout << "Chas 2: ";
    t2.displayTime();
    cout << "Suma: ";
    t3.displayTime();
    cout << "Riznuzia: ";
    t4.displayTime();
    cout << "Chas 1 > Chas 2: " << (t1 > t2 ? "Yes" : "No") << endl;
    cout << "Chas 1 < Chas 2: " << (t1 < t2 ? "Yes" : "No") << endl;
    cout << "Chas 1 == Chas 2: " << (t1 == t2 ? "Yes" : "No") << endl;

    return 0;
}
