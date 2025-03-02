#include <iostream>
using namespace std;
void find(double* arr, int n) 
{
    for (int i = 0; i < n - 2; i++) 
	{ 
        if (*(arr + i) > *(arr + i + 1) && *(arr + i + 1) > *(arr + i + 2)) 
		{
            cout << "Falling area: " << *(arr + i) << ", " << *(arr + i + 1) << ", " << *(arr + i + 2) << endl;
        }
    }
}
int main() 
{
    int n;
    cout << "Number of array elements: ";
    cin >> n;
    if (n < 3) 
	{
        cout << "The array must have at least 3 elements." << endl;
        return 1;
    }
    double* arr = new double[n];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) 
	{
        cin >> *(arr + i); 
    }
    find(arr, n); 
    delete[] arr; 
    return 0;
}

