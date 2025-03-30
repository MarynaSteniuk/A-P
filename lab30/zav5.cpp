#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stdarg.h>

using namespace std;

void index(int a[], int b[], int n, ...)
{
	int i, t;
	int *array = new int[n];
	int index = 0;
	
	va_list arg_list; //va_list - тип даних, arg_list - вказівник
	va_start (arg_list, n); //Передаєм вказівник, та задаєм останній точно заданий параметр(n)
	while ((t=va_arg(arg_list, int))!= -1) 
	{
		if(a[t] != b[t])
			array[index++] = t;
	}	
	va_end (arg_list);
	
	for(i=0; i<index; i++){
		cout<<array[i]<<" ";
	}
	
	delete[] array;
}

int main()
{
	int n = 12;
	
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
	index(a, b, n, 1, 4, 5, 9, 10, -1);
	
	delete[] a;
	delete[] b;
	
	return 0;
}
