#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() 
{
    int n, i, j, max, min;
    cout<<"Enter the dimension of the matrix n: ";
    cin>>n;
    int A[n][n];
	srand(time(0));
	cout << "Matrix: "<<endl;
    for (i=0; i<n; i++) 
	{
        for (j=0; j<n; j++) 
		{
            *(*(A+i)+j)=rand()%100+1;
            cout<<*(*(A+i)+j)<<" ";
        }
        cout<<endl;
	}
    max=*(*(A+0)+0);  
    min=*(*(A+0)+(n-1)); 
    for (i=0; i<n; i++) 
	{
        if (*(*(A+i)+i)>max) 
            max=*(*(A+i)+i);
        if (*(*(A+i)+(n-i-1))<min) 
            min=*(*(A+i)+(n-i-1));
    }
    cout<<"Difference: "<<max-min<<endl;
    return 0;
}
