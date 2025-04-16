#include <iostream>   
#include <fstream>    
#include <cstring>    
#include <cctype>     
using namespace std;
int main()
{
	int i, word = 1000; 
	char **c = new char*[word]; 
	int n = 0; //лічильник прочитаних слів
	ifstream file("Zavd1.txt");
	if(file.is_open()){
		for(i = 0; i < word; i++){
			c[i] = new char[1000]; //виділяємо пам'ять під одне слово
			if(!(file >> c[i])){   //якщо файл не може прочитати більше слів — зупиняємо цикл
				break;
			}
		}
		n = i; //зберігаємо фактичну кількість зчитаних слів
		file.close(); 
	}
	cout << "Words in file: "; //виводимо 
	for(i = 0; i < n; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	char **a = new char*[word]; //створюємо масив для слів з трьома літерами
	int threeC = 0; 
	for(i = 0; i < n; i++)
	{
		if(strlen(c[i]) == 3)
		{ 
			a[threeC++] = c[i]; 
		}
	}	
	cout << "3-letter words: ";
	for(i = 0; i < threeC; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	char **b = new char*[word]; //створюємо масив для слів, що не починаються з великої літери
	int upperC = 0;
	for(i = 0; i < n; i++){
		if(!isupper(c[i][0]))
		{
			b[upperC++] = c[i]; 
		}
	}
	cout << "Words not start uppercase: ";
	for(i = 0; i < upperC; i++){
		cout << b[i] << " ";
	}
	cout << endl;
	char d[1000]; 
	cout << "Enter word to search: "; 
	cin >> d;
	for(i = 0; d[i]; i++)
	{
		d[i] = tolower(d[i]); //переведення введеного слова у нижній регістр
	}
	
	int searchC = 0, j;
	for(i = 0; i < n; i++)
	{
		char t[1000];
		strcpy(t, c[i]); //копіюємо слово з файлу
		for(j = 0; t[j]; j++){
			t[j] = tolower(t[j]); 
		}
		if(strcmp(t, d) == 0) //якщо однакові збільшуємо лічильник
		{ 
			searchC++;
		}
	}
	cout << "Number of repetitions: " << searchC;
	for(i = 0; i < word; i++){
		delete[] c[i]; 
	}
	delete[] c; 
	delete[] a;
	delete[] b;
	
	return 0;
}

