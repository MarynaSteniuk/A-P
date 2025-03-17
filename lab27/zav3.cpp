#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void F(double* b, int& size, double k) // функція для вставки елементів у масив b у впорядкованому порядку
{
    int t=size;
    while (t>0 && b[t-1]>k) 
	{
        b[t]=b[t-1];
        t--;
    }
    b[t]=k;
    size++;
}

int main() 
{
    int n;
    cout<<"Vvedit rozmir masuvy a: ";
    cin>>n;
    double* a=new double[n];
    cout<<"Vvedit elementu masuvy a: "<<endl;
    for (int i=0; i<n; i++) 
	{
        cin>>a[i];
    }
    double* b = new double[n]; // масив b має максимальний можливий розмір n
    int m=0; // фактична кількість елементів у масиві b
    for (int i=0; i<n; i++) 
	{
        if ((int)a[i] % 2 == 0) // Перевірка, чи ціла частина парна
		{ 
            F(b, m, a[i]); // Додавання елемента у впорядкованому порядку
        }
    }

    cout << "Masuv b:"<<endl;
    for (int i=0; i<m; i++) 
	{
        cout<<b[i]<<" ";
    }
    cout<<endl;
    delete[] a;
    delete[] b;
    return 0;
}

