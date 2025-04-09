#include <iostream>   
#include <ctime>      
#include <stdlib.h>   
#include <cmath>      
#include <fstream>    

using namespace std; 

int main()
{
	srand(time(NULL)); // генератор випадкових чисел 
	
	int n, i, j; 
	cout << "Input nxn: "; 
	cin >> n; 
	int **a = new int*[n]; // динамічне виділення пам'яті під матрицю
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
	// підраховуємо загальну кількість елементів і їх суми
	int countall = 0, suma = 0;
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			countall++;         // збільшуємо лічильник елементів
			suma += a[i][j];    // додаємо значення до загальної суми
		}
	}
	cout << "Count all numbers: " << countall;
	cout << endl << "Suma all numbers: " << suma << endl;
	double avg = (suma * 1.0) / (double)countall; // обчислюємо середнє арифметичне всіх елементів
	cout << "Average: " << avg << endl;
	int *countRow = new int[n];  // створення динамічного масиву для зберігання кількості елементів менших за середнє у кожному рядку
	for (i = 0; i < n; i++) // заповнення масиву countRow: для кожного рядка рахуємо кількість елементів, менших за середнє
	{
		countRow[i] = 0; 
		for (j = 0; j < n; j++) 
		{
			if (a[i][j] < avg) 
			{
				countRow[i]++; // збільшуємо лічильник, якщо елемент менший за середнє
			}
		}
	}
	cout << endl;
	cout << "Result: " << endl;
	for (i = 0; i < n; i++) 
	{
		cout << "Row " << i + 1 << ": " << countRow[i] << endl;  // виводимо скільки елементів у кожному рядку менше середнього значення
	}
	ofstream file("Zavd1.txt");  // записуємо результати у файл "Zavd1.txt"
	if (file.is_open()) 
	{
		for (i = 0; i < n; i++) {
			file << "Row " << i + 1 << ": " << countRow[i] << endl;
		}
		file.close(); 
	}
	for (i = 0; i < n; i++)
		delete[] a[i]; 
	delete[] a; 
	delete[] countRow; 
	return 0; 
}

