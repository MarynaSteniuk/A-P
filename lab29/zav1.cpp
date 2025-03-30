#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>


using namespace std;

int main()
{
	int i, word = 1000;
	char **c = new char*[word];
	int n = 0;
	
	ifstream file("Zavd1.txt"); //reads a text file
	if(file.is_open()){
		for(i=0;i<word;i++){
			c[i] = new char[1000];
			if(!(file >> c[i])){
				break;
			}
		}
	n = i;
	file.close();
	}
	
	cout<<"Words in file: "; //output the read file for verification
	for(i=0;i<n;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	
	char **a = new char*[word]; //create a new dynamic character array
	int threeC = 0; //and its counter 
		
	for(i=0;i<n;i++){
		if(strlen(c[i]) == 3){ //if there are 3 letters, then we point to a new array
			a[threeC++] = c[i];
		}
	}	
	
	cout<<"3-letter words: ";
	for(i=0;i<threeC;i++){
		cout<<a[i]<<" "; //output rezult
	}
	cout<<endl;
	
	char **b = new char*[word];
	int upperC = 0;
	
	for(i=0;i<n;i++){
		if(!isupper(c[i][0])){ //if the word does not start with a capital letter, it is added to a separate array
			b[upperC++] = c[i];	
		}
	}
	
	cout<<"Words not start uppercase: ";
	for(i=0;i<upperC;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	
	char d[1000];
	cout<<"Enter word to search: "; cin>>d; //
	
	for(i=0;d[i];i++){
		d[i] = tolower(d[i]);
	}
	
	int searchC = 0, j;
	for(i=0;i<n;i++){ //finding the number of identical words
		char t[1000];
		strcpy(t, c[i]);
			for(j=0;t[j];j++){
				t[j] = tolower(t[j]);
			}
				if(strcmp(t, d) == 0){ 
					searchC++;
				}
				
	}
	
	cout<<"Number of repetitions: "<<searchC;
	
	for(i=0;i<word;i++){
		delete[] c[i];
	}
	delete[] c;
	delete[] a;
	delete[] b;
	
	return 0;
}
