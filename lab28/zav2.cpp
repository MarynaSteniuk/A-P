#include <iostream>   
#include <ctime>      
#include <stdlib.h>   
#include <cmath>      
using namespace std; 

bool descending(int **a, int n, int j) // функція перевіряє, чи стовпчик матриці відсортований за спаданням
{
	int i;
	for(i = 1; i < n; i++)
	{
		if(a[i][j] > a[i-1][j]) // якщо поточний елемент більший за попередній то це не спадання
		{
			return false;
		}
	}
	return true; // якщо не знайшли порушень то стовпчик є спадним
}

int main()
{
	srand(time(NULL)); 
	int n, i, j; 
	cout << "Input nxn: "; 
	cin >> n;
	int **a = new int*[n]; // створення динамічного матриці
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	cout << "Matrix: " << endl;	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100; 
			cout << a[i][j] << " "; 
		}
		cout << endl; 
	}
	int countdis = 0; 
	for(j = 0; j < n; j++) 	// перевіряяємо кожний стовпець на спадання за допомогою функції descending()
	{
		if(descending(a, n, j))  // якщо стовпець спадний
		{ 
			countdis++;          // збільшуємо лічильник
		}
	}
	cout << "Count numbers: " << countdis << endl; 	
	for (i = 0; i < n; i++)
		delete [] a[i]; 
	delete [] a;        
	return 0;
}

