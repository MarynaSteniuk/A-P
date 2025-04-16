#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main() 
{
    int n, i, j;
    cout<<"n: "; 
    cin>>n;
    int** A=new int*[n]; 
    for (i=0; i<n; i++) 
	{
        A[i]=new int[n]; 
    }
    srand(time(0));
    cout<<"Matrix A:"<<endl;
    for (i=0; i<n; i++) 
	{
        for (j=0; j<n; j++) 
		{
            *(*(A+i)+j)=rand()%201-100;
            cout<<*(*(A+i)+j)<<" "; 
        }
        cout << endl;
    }
    int positive=0, negative=0, zero=0; 
    double pSum=0, nSum=0; //суми додатних і від’ємних чисел
    for (i=0; i<n; i++) 
	{
        for (j=0; j<n; j++) 
		{
            int v=*(*(A+i)+j); //отримуємо значення елемента матриці
            if (v>0) 
			{
                pSum=pSum+v; //додавання додатного числа до суми
                positive++;  //збільшення кількості додатних чисел
            } 
			else if (v<0) 
			{
                nSum=nSum+v;
                negative++;
            } 
			else 
			{
                zero++;
            }
        }
    }
    
double positiveAvg, negativeAvg; //розрахунок середнього значення додатних і від’ємних чисел
if (positive>0) 
	{
    positiveAvg=pSum/positive;
    } 
	else 
	{
    positiveAvg=0; //якщо немає додатних чисел то середнє=0
    }
    
if (negative>0) 
	{
    negativeAvg=nSum/negative;
    } 
	else 
	{
    negativeAvg=0;
    }
    
    cout<<"Average of positive numbers: "<<positiveAvg<<endl;
    cout<<"Average of negative numbers: "<<negativeAvg<<endl;
    cout<<"Number of zeros: "<<zero<<endl;
    
    for (i=0; i<n; i++) 
	{
        delete[] A[i]; 
    }
    delete[] A; 
    return 0;
}

