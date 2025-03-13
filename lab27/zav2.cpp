#include <iostream>
#include <cstdlib>

using namespace std;


void newB(double* a, int n, double*& b, int& m) // ������� ��� ��������� ������ ������ b, ���� ������ ����� a, ���� ����� n, ��������� �� ����� b �� ������� �������� � b (m)
{
    m = 0; 
    for (int i = 1; i < n; i=i+2) // ��������� ������� ������ �������� �� �������� �������� � a, ���������� ���� �������� �� �������� �������� 
	{ 
        if ((int)a[i] % 2 == 0) // ����������, �� ������� ������
		{ 
            m++; // �������� �������� m
        }
    }
    b = new double[m]; // �������� ���'��� ��� ������ b ������� m
    int k = 0; // ��� ������ � ����� b
    for (int i = 1; i < n; i += 2) // ����� ������ �������� � a � ����� b
	{
        if ((int)a[i] % 2 == 0) 
		{ 
            b[k++] = a[i]; // ���� �� ������ �� ������ ���� �� b
        }
    }
}

int main() 
{
    int n; 
    cout << "Vvedit rozmir masuv a: ";
    cin >> n;
    double* a = new double[n]; //�������� ���'��� ��� ������ a
    cout << "Masuv a: ";
    for (int i = 0; i < n; i++) 
	{
        a[i] = rand() % 100; //��������� ����������� ����� �� 0 �� 99
        cout << a[i] << " "; 
    }
    cout << endl;
    double* b; //����� b ��� ���������� ������ ��������
    int m; 
    newB(a, n, b, m);
    cout << "Masuv b: ";
    for (int i = 0; i < m; i++) 
	{
        cout << b[i] << " ";
    }
    cout << endl;
    delete[] a; 
    delete[] b; 
    return 0;    
}

