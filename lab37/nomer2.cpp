#include <iostream>
#include <string>
using namespace std;

class Engine {                //базовий клас "Двигун"
protected:                    //поля доступні для похідних класів (Car і Truck), але недоступні для зовнішнього коду
    int power;                //потужність
    string serialNumber;      //заводський номер

public:
    Engine() : power(0), serialNumber("") {}  //за замовчуванням
    Engine(int p, string sn) : power(p), serialNumber(sn) {}  //параметризований 
    ~Engine()  //деструктор
	{
        cout<<"Dvugyn z nomerom "<<serialNumber<<" vudaleno.\n";
    }
    void input() 
	{
        cout<<"Vvedit potygnist dvudyna: ";
        cin>>power;
        cout<<"Vvedit zavodskui nomer: ";
        cin.ignore();
        getline(cin, serialNumber);
    }
    void display() 
	{
        cout<<"Potygnist: "<<power<< endl;
        cout<<"Zavodskui nomer: "<<serialNumber<<endl;
    }
};
class Car : public Engine {     //наслідування через public: відкриті та захищені члени базового класу залишаються відповідно відкритими та захищеними у похідному класі
protected:                     //поля доступні для класу "Вантажівка"
    string brand;              //марка 
    double price;              //ціна

public:
    Car() : brand(""), price(0) {}
    Car(int p, string sn, string b, double pr) : Engine(p, sn), brand(b), price(pr) {}
    ~Car() 
	{
        cout<<"Avto marku "<<brand<<" vudaleno.\n";
    }
    void inputCar() 
	{
        input();
        cout<<"Vvedit marky: ";
        getline(cin, brand);
        cout<<"Vvedit price: ";
        cin>>price;
    }
    void displayCar() 
	{
        display();
        cout<<"Marka: "<<brand<<endl;
        cout<<"Price: "<<price<<endl;
    }
};


class Truck : public Car {  //наслідування через public: відкриті та захищені члени класу "Автомобіль" залишаються відповідно відкритими та захищеними у класі "Вантажівка"
private:      //поле доступне тільки методам класу "Вантажівка"
    int vagkopiduomnist;    //вантажопідйомність

public:
    Truck() : vagkopiduomnist(0) {}
    Truck(int p, string sn, string b, double pr, int vp) : Car(p, sn, b, pr), vagkopiduomnist(vp) {}
    ~Truck() 
	{
        cout<<"Vantagivka marku "<<brand<<" vudalena.\n";
    }
    void inputTruck() 
	{
        inputCar();
        cout<<"Vvedit vagkopiduomnist (kg): ";
        cin>>vagkopiduomnist;
    }
    void displayTruck() 
	{
        displayCar();
        cout<<"Vagkopiduomnist: "<<vagkopiduomnist<<" kg"<<endl;
    }
};
int main() 
{
    Truck trucks[3]; //масив вантажівок
    for (int i=0; i<3; ++i) 
	{
        cout<<"\Vvedit dani dla vantagivku #"<<i+1<<":\n";
        trucks[i].inputTruck();
    }
    cout<<"\nDani:\n";
    for (int i=0; i<3; ++i) 
	{
        cout<<"\nVantagivka #"<<i+1<<":\n";
        trucks[i].displayTruck();
    }
    cout << "\nPruklad:\n"; //конструктор з параметрами
    Truck t1(300, "SN12345", "Volvo", 150000, 2000);
    t1.displayTruck();
    return 0;
}
