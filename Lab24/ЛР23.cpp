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
    cout<<"������ ����� a: "<<&a<<endl;
    cout<<"������ ����� c: "<<&c<<endl;
    cout<<"������ ��������� p: "<<&p<<endl;
    cout<<"������, �� ��� ����� p: "<<p<<endl;
    cout<<"�������� ����� a: "<<a<<endl;
    cout<<"�������� ����� c: "<<c<<endl;
    cout<<"��������, �� ��� ����� p: "<<*p<<endl;
    return 0;
}

