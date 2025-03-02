#include <iostream>
using namespace std;

double findMinEvenIndex(double* arr, int n) 
{
    double minEven; 
    bool hasEvenIndex = false; 
    for (int i = 1; i < n; i=i+2) 
	{ 
        if (!hasEvenIndex || *(arr + i) < minEven) 
		{ 
            minEven = *(arr + i); 
            hasEvenIndex = true;  
        }
    }
    if (!hasEvenIndex) 
	{
        cout << "There are no elements with even numbers in the array." << endl;
        return 0; 
    }
    return minEven; 
}

int main() 
{
    int n;
    cout << "Number of array elements: ";
    cin >> n;
    if (n <= 0) 
	{
        cout << "The number of elements must be greater than 0." << endl;
        return 1;
    }
    double* arr = new double[n];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) 
	{
        cin >> *(arr + i); 
    }
    double minEven = findMinEvenIndex(arr, n);
    if (minEven != 0) {
        cout << "Minimum element with even numbers: " << minEven << endl;
    }
    delete[] arr;
    return 0;
}

