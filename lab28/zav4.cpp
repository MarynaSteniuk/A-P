#include <iostream>   
#include <ctime>      
#include <stdlib.h>   

using namespace std;  
bool comparisonnum(int numb) //функція для перевірки чи цифри двозначного числа однакові
{
	int n1 = numb / 10;   
	int n2 = numb % 10;   
	return n1 == n2;      // повертає true якщо цифри однакові
}
bool column(int **a, int n, int j) //функція для перевірки чи в вказаному стовпчику хоча б один елемент має однакові цифри
{
	for(int i = 0; i < n; i++)
	{
		if(comparisonnum(a[i][j]))
		{ 
			return true;
		}
	}
	return false; 
}
int main()
{
	srand(time(NULL));
	int n, i, j;
	
	cout << "Input nxn: "; 
	cin >> n; 
	int **a = new int*[n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	cout << "Matrix: " << endl;	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			a[i][j] = rand() % 90 + 10; // випадкові числа від 10 до 99
			cout << a[i][j] << " ";
		}
		cout << endl;
	}		
	int suma = 0; 
	for(j = 0; j < n; j++)  //проходимося по кожному стовпцю
	{
		if(!column(a, n, j)) // якщо у стовпці немає чисел з однаковими цифрами
		{ 
			for(i = 0; i < n; i++){
				suma = suma + a[i][j]; 
			}
		}	
	}

	cout << "Suma: " << suma;
	for (i = 0; i < n; i++)
		delete [] a[i]; 
	delete [] a;        
	return 0; 
}

