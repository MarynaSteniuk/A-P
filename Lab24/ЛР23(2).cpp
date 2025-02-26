#include <iostream>
using namespace std;
int main() 
{
	setlocale (LC_CTYPE,"ukr");
    int a, b, c;
    int *pmin;
    int *pmax; 
    cout<<"¬вед≥ть 3 числа: ";
    cin>>a>>b>>c;
    pmin = &a;
    if (b<*pmin)
	pmin=&b;
    if (c<*pmin)
	pmin=&c;
    pmax=&a;
    if (b>*pmax) 
	pmax=&b;
    if (c>*pmax) 
	pmax=&c;
    cout << "min: " << *pmin << endl;
    cout << "&min: " << pmin << endl;
    cout << "max: " << *pmax << endl;
    cout << "&max: " << pmax << endl;
    return 0;
}

