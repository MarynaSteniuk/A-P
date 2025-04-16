#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() 
{
    int n, i, j, max, min;
    cout<<"Enter the dimension of the matrix n: ";
    cin>>n;
    int** A = new int*[n];
    for (int i = 0; i < n; i++) 
	{
        A[i] = new int[n]; 
	}
	srand(time(0));
	cout << "Matrix: "<<endl;
    for (i=0; i<n; i++) 
	{
        for (j=0; j<n; j++) 
		{
            *(*(A+i)+j)=rand()%100+1;
            cout<<*(*(A+i)+j)<<" "; //�������� �������� �������� A[i][j]
        }
        cout<<endl;
	}
    max=*(*(A+0)+0);  // ������ max ��������� ������� �������� ������� �� ������� ������� A[0][0]
    min=*(*(A+0)+(n-1)); //������ min ��������� ������� �������� ������ ������� A[0][n-1]
    for (i=0; i<n; i++) 
	{
        if (*(*(A+i)+i)>max) //���������� �� ������� ������� ������� ������ �� max
            max=*(*(A+i)+i); //���� �������� max
        if (*(*(A+i)+(n-i-1))<min) //���������� �� ������� ������ ������� ������ �� min
            min=*(*(A+i)+(n-i-1)); //����� �������� min
    }
    cout<<"Difference: "<<max-min<<endl;
    for (int i = 0; i < n; i++) 
	{
        delete[] A[i];
    }
    delete[] A;
    return 0;
}
