#include <iostream>

using namespace std;

int main() 
{
	setlocale (LC_CTYPE,"ukr");
float third(float* a, float* b, float* c, float* d) {
if (*a == *b|| *a == *с || *a == *d || *b==*c || *b==*d || *c == *d) {
cout<< "вхідні числа не є унікальними"<<endl;
}
float average = (*a + *b + *c + *d) / 4;
cout<<"Середнє значення: "<<average<<endl;
float* minNumber = a;
float* maxNumber = a;
if (*b < *minNumber) minNumber = b;
if (*c < *minNumber) minNumber = c;
if (*d < *minNumber) minNumber = d;
if (*b > *maxNumber) maxNumber = b;
if (*c > *maxNumber) maxNumber = c;
if (*d > *maxNumber) maxNumber = d;
cout << "два числа != мінімальні і максимальні: ";
if (a != minNumber && a != maxNumber)
cout<< *a<< " ";
if (b != minNumber && b != maxNumber)
cout<<*b<<" ";
if (c != minNumber && c != maxNumber)
cout<<*c<<" ";
if (d != minNumber && d != maxNumber)
cout << *d<<" ";
return 0;
}
