#include <iostream>
using namespace std;
float A(float* a, float* b, float* c, float* d) 
{
  if (*a == *b || *a==*c || *a == *d || *b==*c || *b == *d || *c == *d) 
  {
    cout << "the data is not unique" << endl;
  }

  float average = (*a + *b + *c + *d) / 4;
  cout << "average: " << average << endl;

  float* minimum = a;
  float* maximum = a;

  if (*b < *minimum) minimum = b;
  if (*c < *minimum) minimum = c;
  if (*d < *minimum) minimum = d;

  if (*b > *maximum) maximum = b;
  if (*c > *maximum) maximum = c;
  if (*d > *maximum) maximum = d;

  cout << "not minimum and not maximum: ";
  if (a != minimum && a != maximum) 
    cout << *a << " ";
  if (b != minimum && b != maximum) 
    cout << *b << " ";
  if (c != minimum && c != maximum) 
    cout << *c << " ";
  if (d != minimum && d != maximum) 
    cout << *d << " ";

  return 0;
}

int main() {
  float a, b, c, d;
  cout << " enter a: ";
  cin >> a;
  cout << " enter b: ";
  cin >> b;
  cout << " enter c: ";
  cin >> c;
  cout << " enter d: ";
  cin >> d;
  A(&a,&b,&c,&d);
  return 0;
}
