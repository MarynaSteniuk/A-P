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
        cout<<endl;
    }
    int* mainD=new int[n];
    for (i=0; i<n; i++) 
	{
        mainD[i]=*(*(A+i)+i); 
    }
    for (i=0; i<n-1; i++) 
	{
        for (j=0; j<n-i-1; j++) 
		{
            if (mainD[j]>mainD[j+1]) 
			{
                int t=mainD[j];
                mainD[j]=mainD[j+1];
                mainD[j+1]=t;
            }
        }
    }
    for (i=0; i<n; i++) 
	{
        *(*(A+i)+i)=mainD[i];
    }
    cout<<"Matrix A after sorting main diagonal:"<<endl;
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

