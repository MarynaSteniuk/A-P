#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <stdlib.h>

using namespace std;

char **array(int n) //creating a dynamic matrix
{	
	int i;
	char **a = new char*[n];
	for(i=0;i<n;i++){
		a[i] = new char[n];
	}
	return a;
}

char randomVowel() //random vowel and consonant generation
{
    const char a[] = {'A', 'E', 'I', 'O', 'U'};
    return tolower(a[rand() % 5]);
}

char randomConsonant()
{
    const char a[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M',
                      'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    return tolower(a[rand() % 21]);
}

void fillMatrix(char **a, int n) //matrix filling
{
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i == j || i+j == n-1){
				a[i][j] = randomVowel();
			} else {
				a[i][j] = randomConsonant();
			}
		}
	}
}

void print(char **a, int n) //output matrix
{
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
			cout<<endl;
	}
}

int main()
{
	srand(time(NULL));
	int n, i, j;
	cout<<"Input nxn: "; cin>>n;
	
	char **c = array(n);
	fillMatrix(c,n);
	print(c,n);
	
	char b[1000];
	cout<<"Enter a word to search: "; cin>>b;
	int len = strlen(b);
	
	int ii[n][3], jj[n][3], ic = 0, jc = 0;
	bool found = false;
	for(i=0;i<n;i++){ //search for a word in strings
		for(j=0;j<=n-len;j++){
			int k;
				for(k=0;k<len;k++){
					if(c[i][j+k] != b[k]){
						break;
					}
				}
			if(k == len){
				ii[ic][0] =  i;
				ii[ic][1] = j;
				ii[ic][2] = j+len-1;
				ic++;
				found = true;
			}
		}
	}
	for(j=0;j<n;j++){ //search for a word in columns
		for(i=0;i<=n-len;i++){
			int k;
				for(k=0;k<len;k++){
					if(c[i+k][j] != b[k]){
						break;
					}
				}
			if(k == len){
				jj[jc][0] = j;
				jj[jc][1] = i;
				jj[jc][2] = i+len-1;
				jc++;
				found = true;
			}
		}
	}
	if(found){ //output of the result
		cout<<"Your word on row '"<<b<<"' : ";
		for(i=0;i<ic;i++){
			cout<<ii[i][0] + 1<<","<<ii[i][1]<<" and "<<ii[i][0] + 1<<","<<ii[i][2];
		}
		cout<<endl;
		cout<<"Your word on column '"<<b<<"' : ";
		for(j=0;j<jc;j++){
			cout<<jj[j][0] + 1<<","<<jj[j][1]<<" and "<<jj[j][0] + 1<<","<<jj[j][2];
		}
	} else {
		cout<<"Word not found!";
	}
	
	for(i=0;i<n;i++){
		delete[] c[i];
	}
	delete[] c;
	
	return 0;
}
