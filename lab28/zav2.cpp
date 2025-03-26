#include <iostream>
using namespace std;

bool F(int* c, int n) 
{ 
    for (int i = 1; i < n; i++)
        if (c[i] > c[i - 1]) 
		return false; 
    return true;
}

int Fks(int** A, int n) 
{ 
    int count = 0;
    for (int j = 0; j < n; j++) 
	{ 
        int* a = new int[n];
        for (int i = 0; i < n; i++) 
            a[i] = A[i][j]; 
        if (F(a, n)) 
		count++; 
        delete[] a; 
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int** A = new int*[n]; 
    for (int i = 0; i < n; i++) 
	{
        A[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> A[i][j]; 
    }
    cout << Fks(A, n) << endl; 
    for (int i = 0; i < n; i++) 
	delete[] A[i]; 
    delete[] A;
    return 0;
}
