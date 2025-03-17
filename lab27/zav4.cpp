#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findMin(int* arr, int s) // ������� ��� ����������� ���������� �������� � �����
{
    int min=arr[0];  // ��������� �������� ������
    for (int i=1; i<s; i++) 
	{
        if (arr[i] < min) 
		{
            min = arr[i];
        }
    }
    return min;
}

int findMax(int* arr, int s) // ������� ��� ����������� ������������� �������� � �����
{
    int max=arr[0];  // ��������� �������� ���������
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
        a[i]=rand()%6-2;  // ��������� ����� �� -2 �� 3
        cout<<a[i]<<" ";
    }
    cout << endl;
    int* b = new int[2 * n];    // ��������� ����� ����� b, � ���� ������ ��������� ��������, ����� b ���� ���� ����� ������ ��� �������
    int m = 0; // ������� �������� � ����� b
    for (int i = 0; i < n; i++) // ��������� ����� ����� a
	{
        if (a[i]<0) 
		{
            int min=findMin(a, i); // ��������� ����� �� ��������� ��������
            int max=findMax(a, i); // ��������� �������� �� ��������� ��������
            b[m++]=min+max;   // ���������� ���� ������ �� ��������� � ����� b
        }
        b[m++]=a[i]; // ���������� ������� ����� � ����� b
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

