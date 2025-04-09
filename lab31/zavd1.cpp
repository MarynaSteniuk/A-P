#include <iostream>
using namespace std;

class Flat 
{
private:
    string address; //адреса квартири
    int floor;      //поверх
    int rooms;      //кількість кімнат
    float area;     //площа

public:
    Flat() //конструктор за замовчуванням
	{
        address = "Nevidomo";
        floor = 1;
        rooms = 2;
        area = 55;
    }
    Flat(string a, int f) //параметризований конструктор (тільки адреса і поверх)
	{
        address = a;
        floor = f;
        rooms = 2;
        area = 55;
    }

    void input() //введення даних
	{
        cout << "Adresa: ";
        cin >> address;
        cout << "Poverx: ";
        cin >> floor;
        cout << "Kilkist kimnat: ";
        cin >> rooms;
        cout << "Plosha: ";
        cin >> area;
    }
    void output()  //виведення даних 
	 {
        cout << "Adresa: " << address << ", Poverx: " << floor<< ", Kimnat: " << rooms << ", Plosha: " << area << " m" << endl;
    }

    //гетери які потрібні для фільтрації
    int getRooms()
	{ 
	return rooms;
	}
    float getArea()
	{ 
	return area; 
	}
    int getFloor()
	{ 
	return floor; 
	}
};

int main() {
    const int N = 3;         //кількість квартир
    Flat flats[N];           //масив об'єктів класу
    for (int i = 0; i < N; i++)  //введення даних
	{
        cout << "Kvartura #" << i + 1 << endl;
        flats[i].input();
    }
    cout << "\n Kvartura z 2 kimnatamu:\n"; //виведення квартир з певною кількістю кімнат
    for (int i = 0; i < N; i++) 
	{
        if (flats[i].getRooms() == 2)
            flats[i].output();
    }
    cout << "\n Kvarturu z plosheu 40 m i poverxom 2-5:\n"; //виведення квартир з площею до 40 м та поверхами від 2 до 5
    for (int i = 0; i < N; i++) 
	{
        if (flats[i].getArea() <= 40 && flats[i].getFloor() >= 2 && flats[i].getFloor() <= 5)
            flats[i].output();
    }
    return 0;
}

