#include <iostream>
using namespace std;
void find(int* arr, int n) 
{
    int k=0; 
    cout << "Elements larger than their left neighbor are located at positions: "; //��������, ����� �� ����� �����, ���������� � ��������:
    for (int i=1; i<n; i++) 
	{ 
        if (*(arr+i)>*(arr+i-1)) 
		{ 
            cout<<i+1<<" "; 
            k++;
        }
    }
    cout<<endl;
    cout<<"Number of such elements:"<<k<<endl; //ʳ������ ����� ��������:
}
int main() 
{
    int n;
    cout<<"Enter the number of array elements: "; //������ ������� �������� ������:
    cin>>n;
    if (n<=1) 
	{
        cout<<"An array must contain at least 2 elements."<<endl; //����� �� ������ �������� 2 ��������.
        return 1;
    }
    int* arr=new int[n];
    cout<<"Enter the elements of the array:"<<endl; //������ �������� ������:
    for (int i=0; i<n; i++) 
	{
        cin >> *(arr+i); 
    }
    find(arr, n); 
    delete[] arr; 
    return 0;
}

