#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>

using namespace std;

bool descending(int **a, int n, int j){ //checking if a column is sorted in descending order
	int i;
		for(i=1;i<n;i++){
			if(a[i][j]>a[i-1][j]){
				return false;
			}
		}
	return true;
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
			a[i][j]=rand()% 100;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int countdis=0;
	for(j=0;j<n;j++){
		if(descending(a,n,j)){ //add the number and use the function
			countdis++;
		}
	}	
	cout<<"Count numbers: "<<countdis<<endl;
	
	for (i=0; i<n; i++)
		delete []a[i];
	delete []a;
	
	return 0;
}
