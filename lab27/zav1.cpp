#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int Three(double* arr, int size) // функція для підрахунку кількості елементів, що не кратні трьом
{
    int c = 0;
    for (int i = 0; i < size; i++) 
	{
        if ((int)arr[i] % 3 != 0) 
		{
            c++;
        }
    }
    return c;
}

int main() 
{
    srand(time(0));
    int n, m, i;
    cout << "Rozmir masuvy a: ";
    cin >> n;
    cout << "Rozmir masuvy b: ";
    cin >> m;
    double* a = new double[n];
    double* b = new double[m];
    cout << "Masuv a: ";
    for ( i = 0; i < n; i++) 
	{
        a[i] = rand() % 100; // випадкові числа від 0 до 99
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Masuv b: ";
    for ( i = 0; i < m; i++) 
	{
        b[i] = rand() % 100;
        cout << b[i] << " ";
    }
    cout << endl;
    int A=Three(a, n);// підрахунок кількості елементів, що не кратні трьом
    int B=Three(b, m);// підрахунок кількості елементів, що не кратні трьом
    if (A > B) 
	{
        cout << "a: ";
        for (i = 0; i < n; i++) 
		{
             cout << a[i] << " ";  
        }
    } else if (B > A) 
	{
        cout << "b: ";
        for (i = 0; i < m; i++) 
		{
            cout << b[i] << " ";
        }
    } 
	else 
	{
        cout << "Kilkist rivna.";
    }
    cout << endl;
    delete[] a;
    delete[] b;
    return 0;
}

