#include <iostream>
#include <cstdlib> 
#include <time.h>   
using namespace std;

int main() {
    int n, i, j;
    cout<<"n: ";
    cin>>n; 
    int** A = new int*[n];
    for (int i = 0; i < n; i++) 
	{
        A[i] = new int[n]; 
	}
    srand(time(0));
    cout<<"Matrix: "<<endl;
    for(i=0; i<n; i++) //���� �� ������ �������
	{
        for (j=0; j<n; j++) //���� �� �������� �������
		{
            *(*(A+i)+j)=rand()%100+1;
            cout<<*(*(A+i)+j)<<" ";
        }
        cout<<endl;
    }
    cout << "New matrix: "<<endl;
    for(i=0; i<n; i++) //���� �� ������ �������
	{
        if (i%2==0) 
		{
            for(j=0; j<n; j++) // ��������� �������� � ������� �������
                cout<<*(*(A+i)+j)<< " ";
        } 
		else 
		{
            for(j=n-1; j>=0; j--)// ��������� �������� � ���������� �������
                cout<<*(*(A+i)+j)<<" ";
        }
        cout<<endl;// ���������� �� ����� ����� ���� ��������� ������ �����
    }
    for (int i = 0; i < n; i++) 
	{
        delete[] A[i];
    }
    delete[] A;
    return 0;
}
