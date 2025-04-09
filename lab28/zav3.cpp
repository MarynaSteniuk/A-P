#include <iostream>   
#include <ctime>      
#include <stdlib.h>   
#include <cmath>      
#include <fstream>    

using namespace std;  
void sortarr(int *arr, int n) //������� ��� ���������� ������ � ������� ��������
{
	int t; 
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++) //�������� ����� ���� ��������
		{
			if(arr[j] < arr[j+1])  //���� ��������� ������� ������ ������ ������
			{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int n, i, j;
	cout << "Input nxn: "; 
	cin >> n; 
	int **a = new int*[n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	cout << "Matrix: " << endl;	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			a[i][j] = rand() % 900 + 100; // ��������� ��������� ����� �� 100 �� 999
			cout << a[i][j] << " ";    
		}
		cout << endl;
	}		

	for(i = 0; i < n; i++)  //������� ������ ����� ������� � ������� ��������
	{
		sortarr(a[i], n); 
	}
	cout << endl << "New Matrix: " << endl;	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	ofstream file("zavd3.txt"); //�������� � ����
	if(file.is_open()){
		file << "Sort Matrix: " << endl;	
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				file << a[i][j] << " ";
			}
			file << endl;
		}
		file.close(); 
	}
	for (i = 0; i < n; i++)
		delete [] a[i]; 
	delete [] a;        
	return 0; 
}

