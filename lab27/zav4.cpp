#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findMin(int* arr, int s) // функція для знаходження мінімального елемента в масиві
{
    int min=arr[0];  // початкове значення мінімуму
    for (int i=1; i<s; i++) 
	{
        if (arr[i] < min) 
		{
            min = arr[i];
        }
    }
    return min;
}

int findMax(int* arr, int s) // функція для знаходження максимального елемента в масиві
{
    int max=arr[0];  // початкове значення максимуму
    for (int i=1; i<s; i++) 
	{
        if (arr[i]>max) 
		{
            max=arr[i];
        }
    }
    return max;
}

int main() 
{
    srand(time(0)); 
    int n;
    cout<<"Vvedit rozmir masuvy a: ";
    cin>>n;
    int* a = new int[n];  
    cout<<"Masuv: " << endl;
    for (int i=0; i<n; i++) 
	{
        a[i]=rand()%6-2;  // Генерація числа від -2 до 3
        cout<<a[i]<<" ";
    }
    cout << endl;
    int* b = new int[2 * n];    // створюємо новий масив b, в який будемо вставляти елементи, масив b може бути вдвічі більшим для вставок
    int m = 0; // кількість елементів у масиві b
    for (int i = 0; i < n; i++) // проходимо через масив a
	{
        if (a[i]<0) 
		{
            int min=findMin(a, i); // знаходимо мінімум до поточного елемента
            int max=findMax(a, i); // знаходимо максимум до поточного елемента
            b[m++]=min+max;   // вставляємо суму мінімуму та максимуму в масив b
        }
        b[m++]=a[i]; // вставляємо поточне число в масив b
    }
    cout<<"New masuv b: " << endl;
    for (int i=0; i<m; i++) 
	{
        cout<<b[i]<<" ";
    }
    cout << endl;
    delete[] a;
    delete[] b;
    return 0;
}

