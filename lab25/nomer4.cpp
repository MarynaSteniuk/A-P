#include <iostream>
using namespace std;
void find(int* arr, int n) 
{
    int k=0;
    cout<<"Addresses of elements less than 0: "<<endl; //Адреси елементів, менших за 0
    for (int i=0; i<n; i++) 
	{
        if (*(arr+i)<0) 
		{ 
            cout<<(arr+i)<<endl;
            k++;
        }
    }
    cout<<"Number of elements less than 0: "<<k<<endl; //Кількість елементів, менших за 0
}
int main() 
{
    int n;
    cout<<"Enter the number of array elements: "; //Введіть кількість елементів масиву
    cin>>n;
    if (n<=0) 
	{
        cout<<"Array must contain at least one element."<<endl; //Масив повинен містити хоча б один елемент
        return 1;
    }
    int* arr=new int[n];
    cout<<"Enter the elements of the array: "<<endl; //Введіть елементи масиву
    for (int i=0; i<n; i++) 
	{
        cin>>*(arr+i); 
    }
    find(arr, n);
    delete[] arr; 
    return 0;
}

