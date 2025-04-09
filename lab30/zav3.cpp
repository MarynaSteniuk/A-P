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
			a[i] = rand() % ((max - min) + 1)+ min; //√енеруЇмо масив за заданими значенн€ми в д≥апазон≥ в≥д min до max
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
			b[i] = a[rand() % 12]; //√енеруЇмо новий масив використовуючи основний масив значенн€ беретьс€ випадковим чином ≥з 12-елементного масиву a[]
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

	int *p1 = fillArray(array, n); //генеруЇмо масив з 12 ун≥кальних випадкових чисел в д≥апазон≥ 1Ц50
	cout<<"Array in the range 1 to 50: ";
	for(i=0;i<n;i++){
		cout<<*p1<<" "; //¬иводимо цей масив, використовуючи покажчик p1
		p1++;
	}
	
	int *p2 = fillTwoArray(array); //—творюЇмо новий масив з 8 ун≥кальних елемент≥в, вз€тих випадково з array
	cout<<endl<<"Randomly generated array of 8 values from the previous array: ";
	for(i=0;i<8;i++){
		cout<<*p2<<" "; //¬иводимо цей масив за допомогою покажчика p2
		p2++;
	}

	delete[] array;
	
	return 0;
}
