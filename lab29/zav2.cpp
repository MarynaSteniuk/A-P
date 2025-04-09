#include <iostream>   
#include <cstring>    
#include <cctype>     
#include <ctime>      
#include <stdlib.h>   
using namespace std;

char **array(int n) //функція для створення динамічної матриці
{	
	int i;
	char **a = new char*[n];
	for(i = 0; i < n; i++)
	{
		a[i] = new char[n];
	}
	return a;
}
char randomVowel() //функція генерує випадкову голосну літеру 
{
    const char a[] = {'A', 'E', 'I', 'O', 'U'};
    return tolower(a[rand() % 5]);
}
char randomConsonant() //функція генерує випадкову приголосну літеру
{
    const char a[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M','N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    return tolower(a[rand() % 21]);
}
void fillMatrix(char **a, int n) //заповнюємо матрицю
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i == j || i + j == n - 1) // головна або побічна діагональ
			{ 
				a[i][j] = randomVowel();
			} else {
				a[i][j] = randomConsonant();
			}
		}
	}
}
void print(char **a, int n) //виводимо матрицю
{
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	srand(time(NULL)); 
	int n, i, j;
	cout << "Input nxn: "; cin >> n; 
	char **c = array(n);   
	fillMatrix(c, n);      
	print(c, n);           
	char b[1000]; //масив для введеного слова
	cout << "Enter a word to search: "; 
	cin >> b;
	int len = strlen(b); // довжина слова
	int ii[n][3], jj[n][3]; // масиви для зберігання координат знайденого слова в рядках та стовпцях
	int ic = 0, jc = 0;     // лічильники знайдених слів
	bool found = false;
	for(i = 0; i < n; i++) //пошук слова у кожному рядку матриці
	{
		for(j = 0; j <= n - len; j++) //рухаємось по рядку
		{ 
			int k;
			for(k = 0; k < len; k++)
			{
				if(c[i][j + k] != b[k]) //перевіряємо чи послідовність співпадає
				{ 
					break;
				}
			}
			if(k == len) //якщо всі символи співпали
			{ 
				ii[ic][0] = i;           // номер рядка
				ii[ic][1] = j;           // початкова позиція слова
				ii[ic][2] = j + len - 1; // кінцева позиція слова
				ic++;
				found = true;
			}
		}
	}
	for(j = 0; j < n; j++) //пошук слова у кожному стовпці матриці
	{
		for(i = 0; i <= n - len; i++)
		{
			int k;
			for(k = 0; k < len; k++)
			{
				if(c[i + k][j] != b[k])
				{
					break;
				}
			}
			if(k == len)
			{
				jj[jc][0] = j;           // номер стовпця
				jj[jc][1] = i;           // початкова позиція
				jj[jc][2] = i + len - 1; // кінцева позиція
				jc++;
				found = true;
			}
		}
	}
	if(found)
	{
		cout << "Your word on row '" << b << "' : ";
		for(i = 0; i < ic; i++)
		{
			cout << ii[i][0] + 1 << "," << ii[i][1] << " and " << ii[i][0] + 1 << "," << ii[i][2] << " ";
		}
		cout << endl;
		cout << "Your word on column '" << b << "' : ";
		for(j = 0; j < jc; j++)
		{
			cout << jj[j][0] + 1 << "," << jj[j][1] << " and " << jj[j][0] + 1 << "," << jj[j][2] << " ";
		}
	} else {
		cout << "Word not found!";
	}
	for(i = 0; i < n; i++)
	{
		delete[] c[i];
	}
	delete[] c;
	return 0;
}

