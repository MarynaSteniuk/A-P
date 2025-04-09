#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stdarg.h>
using namespace std;
void index(int a[], int b[], int n, ...) //функція для пошуку індексів елементів, де значення у масивах a і b не збігаються
{                                        //функція приймає два масиви, їх розмір та змінну кількість параметрів
	int i, t;
	int *array = new int[n];
	int index = 0;
	va_list arg_list; //va_list - тип даних, arg_list - вказівник
	va_start (arg_list, n); //Передаєм вказівник, та задаєм останній точно заданий параметр(n)
	while ((t=va_arg(arg_list, int))!= -1) //цикл для обробки всіх переданих індексів
	{                                      //отримуємо значення параметра та перевіряємо, чи не є він -1
		if(a[t] != b[t]) //якщо елементи масивів не збігаються на даному індексі то додаємо індекс до нового масиву
			array[index++] = t;
	}	
	va_end (arg_list); //завершуємо роботу зі списком
	
	for(i=0; i<index; i++)
	{
		cout<<array[i]<<" "; //виводимо індекси
	}
	delete[] array;
}
int main()
{
	int n = 12; //розмір масивів
	int *a = new int[n];
	int *b = new int[n];
	cout<<"Enter the value of the first array: ";
	for(int i=0;i<n;i++){
		cin>>a[i]; // 13 4 2 28 34 7 10 21 43 50 37 11
	}
	cout<<"Enter the value of the following array: ";
	for(int i=0;i<n;i++){
		cin>>b[i]; // 5 4 12 3 30 7 11 14 45 49 37 15
	}
	cout<<"Indices where numbers do not match: ";
	index(a, b, n, 1, 4, 5, 9, 10, -1); //передаємо індекси, де треба порівняти елементи, та -1 як маркер кінця
	delete[] a;
	delete[] b;
	return 0;
}
