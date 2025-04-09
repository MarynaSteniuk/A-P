#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int *fillArray(int a[], int n) //функція заповнення масива
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i] = rand() % 100; //Генеруємо масив за заданими значеннями 
	}
	return a; // Повертаємо вказівник на масив
}

int *fillTwoArray(int a[], int n, int i1 = 4, int i2 = 10) //функція для створення нового масиву з елементів основного масиву за індексами від i1 до i2
{
	int i;
	int count = 0, index = 0;
	for(i=i1;i<=i2;i++) //Рахуємо кількість чисел в заданому діапазоні
	{
		count++; //підраховуємо кількість елементів від i1 до i2
	}
	int *new_array = new int[count]; //Створюємо новий динамічний масив для збереження елементів з діапазону
	
	for(i=i1;i<=i2;i++) //заповнюємо новий масив значеннями з основного масиву
	{
		new_array[index++] = a[i];  //копіюємо значення з основного масиву до нового
	}
	return new_array; //повертаємо вказівник на новий масив
}

int main()
{
	srand(time(NULL));
	int i;
	int n = 12;
	int *array = new int[n];
	int *p1 = fillArray(array, n); //заповнюємо масив випадковими числами
	cout<<"Array in the range 100: ";
	for(i=0;i<n;i++)
	{
		cout<<*p1<<" "; //виводимо значення масиву через вказівник
		p1++;
	}

	int *p2 = fillTwoArray(array, n); //створюємо новий масив з елементів діапазону від індексів 4 до 10
	cout<<endl<<"New array from index range 4 and 10: ";
	for(i=0;i<7;i++)
	{
		cout<<*p2<<" "; //виводимо новий масив
		p2++;
	}
	delete[] array;
	return 0;
}
