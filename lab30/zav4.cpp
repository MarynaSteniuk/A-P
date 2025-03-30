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

	return a;
}

int *fillTwoArray(int a[], int n, int i1 = 4, int i2 = 10) //функція заповнення масива
{
	int i;
	int count = 0, index = 0;
	for(i=i1;i<=i2;i++) //Рахуємо кількість чисел в заданому діапазоні
	{
		count++;
	}
	int *new_array = new int[count]; //Створюємо новий динамічний масив
	
	for(i=i1;i<=i2;i++)
	{
		new_array[index++] = a[i]; //Заповнюємо його значеннями з масиву
	}
	
	return new_array;
}

int main()
{
	srand(time(NULL));
	int i;
	int n = 12;
	
	int *array = new int[n];

	int *p1 = fillArray(array, n);
	cout<<"Array in the range 100: ";
	for(i=0;i<n;i++){
		cout<<*p1<<" ";
		p1++;
	}
	
	int *p2 = fillTwoArray(array, n);
	cout<<endl<<"New array from index range 4 and 10: ";
	for(i=0;i<7;i++){
		cout<<*p2<<" ";
		p2++;
	}
	

	delete[] array;
	
	return 0;
}
