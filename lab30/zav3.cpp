#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int *fillArray(int a[], int n, int min=1, int max=50) //функц≥€ заповненн€ масива
{
	int i, j;
	
	for(i=0;i<n;i++)
	{
		bool uniqueness; //«наченн€ контролюЇ, чи Ї нове згенероване значенн€ ун≥кальним.
		do
		{
			uniqueness = true;
			a[i] = rand() % ((max - min) + 1)+ min; //√енеруЇмо масив за заданими значенн€ми 
			for(j=0;j<i;j++)
			{
				if(a[i] == a[j])
				{
					uniqueness = false;
				}
			}
		}
		while(uniqueness == false); //якщо згенероване число  вже ≥снуЇ, встановлюЇтьс€ false, ≥ цикл  повторюЇтьс€
	}
	
	return a;
}

int *fillTwoArray(int a[], int m=8) //функц≥€ заповненн€ масива
{
	int i, j;
	
	int *b = new int[m];
	
	for(i=0;i<m;i++)
	{
		bool uniqueness; //«наченн€ контролюЇ, чи Ї нове згенероване значенн€ ун≥кальним.
		do
		{
			uniqueness = true;
			b[i] = a[rand() % 12]; //√енеруЇмо новий масив використовуючи основний масив
			for(j=0;j<i;j++)
			{
				if(b[i] == b[j])
				{
					uniqueness = false;
				}
			}
		}
		while(uniqueness == false); //якщо згенероване число  вже ≥снуЇ, встановлюЇтьс€ false, ≥ цикл  повторюЇтьс€
	}
	
	return b;
}

int main()
{
	srand(time(NULL));
	int i;
	int n = 12;
	
	int *array = new int[n];

	int *p1 = fillArray(array, n);
	cout<<"Array in the range 1 to 50: ";
	for(i=0;i<n;i++){
		cout<<*p1<<" ";
		p1++;
	}
	
	int *p2 = fillTwoArray(array);
	cout<<endl<<"Randomly generated array of 8 values from the previous array: ";
	for(i=0;i<8;i++){
		cout<<*p2<<" ";
		p2++;
	}

	delete[] array;
	
	return 0;
}
