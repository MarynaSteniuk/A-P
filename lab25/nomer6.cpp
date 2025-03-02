#include <iostream>
#include <algorithm>
using namespace std;
void sort1(int* a, int n) 
{
    for (int i=0; i<n; i=i+2) 
	{
        for (int j=i+2; j<n; j=j+2) 
		{
            if (*(a+j)<*(a+i)) 
			{
                swap(*(a+i),*(a+j));
            }
        }
    }
}
void sort2(int* a, int n) 
{
    for (int i=1; i<n; i=i+2) 
	{
        for (int j=i+2; j<n; j=j+2) 
		{
            if (*(a+j)>*(a+i)) 
			{
                swap(*(a+i), *(a+j));
            }
        }
    }
}
int main() 
{
    int n;
    cout<<"Enter the number of array elements: ";
    cin>>n;
    if(n<=0) 
	{
        cout<<"Array must contain at least one element."<<endl;
        return 1;
    }
    int* a=new int[n];
    cout<<"Enter the elements of the array:"<<endl;
    for (int i=0; i<n; i++) 
	{
        cin>>*(a+i);
    }
    sort1(a, n); 
    sort2(a, n);  
    cout<<"New array:"<<endl;
    for (int i=0; i<n; i++) 
	{
        cout<<*(a+i)<<" ";
    }
    cout<<endl;
    delete[] a;
    return 0;
}

