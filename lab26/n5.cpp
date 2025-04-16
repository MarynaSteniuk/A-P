#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main() 
{
    int n, i, j;
    cout<<"n: ";
    cin>>n;
    int** A=new int*[n]; //динамічне виділення пам'яті для двовимірного масиву 
    for (i=0; i<n; i++) 
	{
        A[i]=new int[n]; //виділення пам'яті для кожного рядка
    }
    srand(time(0));
    cout<<"Matrix A:"<<endl;
    for (i=0; i<n; i++) 
	{
        for (j=0; j<n; j++) 
		{
            *(*(A+i)+j)=rand()%201-100; //випадкове число [-100, 100]
            cout<<*(*(A+i)+j)<<" "; 
        }
        cout<<endl;
    }
    int* mainD=new int[n]; //виділення пам'яті для одновимірного масиву (головна діагональ)
    for (i=0; i<n; i++) 
	{
        mainD[i]=*(*(A+i)+i); //елемент головної діагоналі A[i][i]
    }
    for (i=0; i<n-1; i++) //сортування масиву
	{
        for (j=0; j<n-i-1; j++) 
		{
            if (mainD[j]>mainD[j+1]) //порівнюємо сусідні елементи
			{
                int t=mainD[j]; //обмінюємо елементи якщо вони в неправильному порядку
                mainD[j]=mainD[j+1];
                mainD[j+1]=t;
            }
        }
    }
    for (i=0; i<n; i++) //заміна елементів головної діагоналі матриці відсортованими значеннями
	{
        *(*(A+i)+i)=mainD[i]; //встановлення нового значення для A[i][i]
    }
    cout<<"Matrix A after sorting main diagonal:"<<endl; //виведення матриці після сортування головної діагоналі
    for (i=0; i<n; i++) 
	{
        for (j=0; j<n; j++) 
		{
            cout<<*(*(A+i)+j)<<" "; 
        }
        cout<<endl;
    }
    delete[] mainD; 
    for (i=0; i<n; ++i) 
	{
        delete[] A[i]; 
    }
    delete[] A; 
    return 0;
}

