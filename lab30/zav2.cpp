#include <iostream>

using namespace std;

float paralel(float a, float b=1, float c=1) //Створюємо функцію знаходження площи, та вписуємо два вже заданих значення
{
	return 2*((a*b) + (b*c) + (a*c));
}

int main()
{
	float x, y, z;
	
	cout<<"Input length, width, height: ";	cin>>x>>y>>z;
	
	//Виводимо можливі варіанти використання функції
	cout<<"Surface area for all given values: ";
	cout<<paralel(x, y, z);
	cout<<endl;
	
	cout<<"Surface area by two given values (length, width): ";
	cout<<paralel(x, y);
	cout<<endl;
	
	cout<<"Surface area by one given values (length): ";
	cout<<paralel(x);
	
	return 0;
}
