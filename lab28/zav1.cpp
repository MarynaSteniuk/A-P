#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	srand(time(NULL));
	int n, i, j;
	
	cout<<"Input nxn: "; cin>>n;
	
	int **a=new int*[n];
	for (i=0; i<n; i++)
		a[i]=new int[n];
		
	cout<<"Matrix: "<<endl;	
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			a[i][j]=rand()% 100;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int countall, suma=0;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			countall++;
			suma+=a[i][j]; //looking for the number and sum of all elements
		}
	}
	cout<<"Count all numbers: "<<countall;
	cout<<endl<<"Suma all numbers: "<<suma<<endl; //output for verification
	
	double avg=(suma*1.0)/(double)countall; // find the average value
	cout<<"Average: "<<avg<<endl;
	
	int *countRow= new int[n]; // introduce a dynamic array
	
	for (i=0; i<n; i++){
		countRow[i]=0;
		for (j=0; j<n; j++){
			if(a[i][j]<avg){
				countRow[i]++;
			}
		}
	}
	
	
	cout<<endl;
	cout<<"Result: "<<endl;
	for(i=0;i<n;i++){
		cout<<"Row "<<i+1<<": "<<countRow[i]<<endl; //result output
	}
	
	ofstream file("Zavd1.txt"); // write to file
	if(file.is_open()){
		for(i=0;i<n;i++){
		file<<"Row "<<i+1<<": "<<countRow[i]<<endl;
		}
	
	file.close();
	}
	
	
	for (i=0; i<n; i++)
		delete []a[i];

	delete []a;
	delete []countRow;
	
	return 0;
}
