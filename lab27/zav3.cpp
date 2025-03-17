#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void F(double* b, int& size, double k) // ������� ��� ������� �������� � ����� b � �������������� �������
{
    int t=size;
    while (t>0 && b[t-1]>k) 
	{
        b[t]=b[t-1];
        t--;
    }
    b[t]=k;
    size++;
}

int main() 
{
    int n;
    cout<<"Vvedit rozmir masuvy a: ";
    cin>>n;
    double* a=new double[n];
    cout<<"Vvedit elementu masuvy a: "<<endl;
    for (int i=0; i<n; i++) 
	{
        cin>>a[i];
    }
    double* b = new double[n]; // ����� b �� ������������ �������� ����� n
    int m=0; // �������� ������� �������� � ����� b
    for (int i=0; i<n; i++) 
	{
        if ((int)a[i] % 2 == 0) // ��������, �� ���� ������� �����
		{ 
            F(b, m, a[i]); // ��������� �������� � �������������� �������
        }
    }

    cout << "Masuv b:"<<endl;
    for (int i=0; i<m; i++) 
	{
        cout<<b[i]<<" ";
    }
    cout<<endl;
    delete[] a;
    delete[] b;
    return 0;
}

