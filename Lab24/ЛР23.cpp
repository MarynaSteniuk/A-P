#include <iostream>

using namespace std;

int main() 
{
	setlocale (LC_CTYPE,"ukr");
    float a=2.5, c=4.7;
    float *p; 
    p=&a;
    *p=*p*3;
    *p=*p+c;
    p=&c;
    cout<<"Адреса змінної a: "<<&a<<endl;
    cout<<"Адреса змінної c: "<<&c<<endl;
    cout<<"Адреса вказівника p: "<<&p<<endl;
    cout<<"Адреса, на яку вказує p: "<<p<<endl;
    cout<<"Значення змінної a: "<<a<<endl;
    cout<<"Значення змінної c: "<<c<<endl;
    cout<<"Значення, на яке вказує p: "<<*p<<endl;
    return 0;
}

