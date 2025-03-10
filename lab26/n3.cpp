#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() 
{
    int n, i, j;
    cout<<"Matrix (n): "; 
    cin>>n;
    int**A=new int*[n]; 
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
            *(*(A+i)+j)=rand()%100+1;
            cout<<*(*(A+i)+j)<<" ";
        }
        cout<<endl;
    }
    int* minI=new int[n]; 
    for (i=0; i<n; i++) 
	{
        int minIndex=0; 
        for (j=1; j<n; j++) 
		{
            if (*(*(A+i)+j)<*(*(A+i)+minIndex)) 
			{ 
                minIndex=j;
            }
        }
        *(minI+i)=minIndex;
    }
    cout<<"Indices of minimum elements in each row:"<<endl;
    for (i=0; i<n; i++) 
	{
        cout<<*(minI+i)<<" "; 
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

