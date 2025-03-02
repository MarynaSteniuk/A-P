#include <iostream>
using namespace std;
double* F(double* a, int& n) // ������� ��� ������� ���� ������� �����, �������� 5, ���� ��������� �������� 
{
    for (int i=0; i<n; i++) 
	{
        if (int(*(a+i))%5==0) 
		{ 
            double sum=0;
            for (int j=0; j<=i; j++) 
			{
                sum=sum+*(a+j);
            }

            double* newA=new double[n+1];
            for (int j=0; j<=i; j++) 
			{
                *(newA+j)=*(a+j);
            }
            *(newA+i+1)=sum;
            for (int j=i+1; j<n; j++) 
			{
                *(newA+j+1)=*(a+j);
            }
            delete[] a;
            a=newA; 
            n++;          
            i++;          
        }
    }
    return a; 
}
int main() 
{
    int n;
    cout<<"Enter the number of array elements: "; //������ ������� �������� ������
    cin>>n;
    if (n<=0) 
	{
        cout<<"Array must contain at least one element."<<endl; //����� ������� ������ ���� � ���� �������
        return 1;
    }
    double* a=new double[n]; 
    cout<<"Enter the elements of the array:"<<endl; //������ �������� ������
    for (int i=0; i<n; i++) 
	{
        cin>>*(a+i);
    }
    a=F(a, n); 
    cout<<"New array:"<<endl;
    for (int i=0; i<n; i++) 
	{
        cout<<*(a+i)<<" ";
    }
    cout<<endl;
    delete[] a; 
    return 0;
}

