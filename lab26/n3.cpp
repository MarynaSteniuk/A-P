#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() 
{
    int n, i, j;
    cout<<"Matrix (n): "; 
    cin>>n;
    int**A=new int*[n]; //динамічне виділення пам’яті для двовимірного масиву
    for (i=0; i<n; i++) 
	{
        A[i]=new int[n]; //виділення пам’яті для кожного рядка
    }
    srand(time(0));
    cout<<"Matrix A:"<<endl;
    for (i=0; i<n; i++) 
	{
        for (j=0; j<n; j++) 
		{
            *(*(A+i)+j)=rand()%100+1;
            cout<<*(*(A+i)+j)<<" ";
        }
        cout<<endl;
    }
    int* minI=new int[n]; //для збереження індексів мінімальних елементів
    for (i=0; i<n; i++) //знаходимо індекси min елементів у кожному рядку
	{
        int minIndex=0; //min індекс для рядка 
        for (j=1; j<n; j++) 
		{
            if (*(*(A+i)+j)<*(*(A+i)+minIndex)) //якщо поточний елемент менший за елемент на поточному мінімальному індексі
			{ 
                minIndex=j; //то оновлюємо min індекс
            }
        }
        *(minI+i)=minIndex; //зберігаємо індекс мінімального елемента для рядка `i`
    }
    cout<<"Indices of minimum elements in each row:"<<endl;
    for (i=0; i<n; i++) 
	{
        cout<<*(minI+i)<<" "; //виведення індексу мінімального елемента рядка
    }
    cout<<endl;
    delete[] minI;
    for (i=0; i<n; i++) 
	{
        delete[] A[i]; 
    }
    delete[] A; 
    return 0;
}

