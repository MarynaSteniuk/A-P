#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

bool comparisonnum(int numb){ //function for finding identical numbers
	int n1 = numb/10;
	int n2 = numb%10;
	return n1 == n2;
}

bool column(int **a, int n, int j){ //function to check if a column contains the same numbers
	int i;
		for(i=0;i<n;i++){
			if(comparisonnum(a[i][j])){
				return true;
			}
		}
	return false;
}

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
			a[i][j]=rand()% 90 + 10;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}		

	int suma=0;
	for(j=0;j<n;j++){
		if(!column(a,n,j)){
			for(i=0;i<n;i++){
				suma=suma+a[i][j]; //add the amount if the condition is met
			}
		}	
	}
	
	cout<<"Suma: "<<suma;
	
	for (i=0; i<n; i++)
		delete []a[i];
	delete []a;
	
	return 0;
}
