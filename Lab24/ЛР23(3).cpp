#include <iostream>

float third(float* a, float* b, float* c, float* d) {
  if (*a == *b || *a==*c || *a == *d || *b==*c || *b == *d || *c == *d) {
    std::cout << "the data is not unique" << std::endl;
  }

  float average = (*a + *b + *c + *d) / 4;
  std::cout << "average: " << average << std::endl;

  float* minimum = a;
  float* maximum = a;

  if (*b < *minimum) minimum = b;
  if (*c < *minimum) minimum = c;
  if (*d < *minimum) minimum = d;

  if (*b > *maximum) maximum = b;
  if (*c > *maximum) maximum = c;
  if (*d > *maximum) maximum = d;

  std::cout << "not minimum and not maximum: ";
  if (a != minimum && a != maximum) 
    std::cout << *a << " ";
  if (b != minimum && b != maximum) 
    std::cout << *b << " ";
  if (c != minimum && c != maximum) 
    std::cout << *c << " ";
  if (d != minimum && d != maximum) 
    std::cout << *d << " ";

  return 0;
}

int main() {
  float a, b, c, d;
  std::cout << " enter a: ";
  std::cin >> a;
  std::cout << " enter b: ";
  std::cin >> b;
  std::cout << " enter c: ";
  std::cin >> c;
  std::cout << " enter d: ";
  std::cin >> d;
  third(&a,&b,&c,&d);

  return 0;
}
