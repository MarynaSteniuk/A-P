#include <iostream>
#include <cstdlib>

using namespace std;


void newB(double* a, int n, double*& b, int& m) // функція для створення нового масиву b, вона приймає масив a, його розмір n, посилання на масив b та кількість елементів у b (m)
{
    m = 0; 
    for (int i = 1; i < n; i=i+2) // підрахунок кількості парних елементів на непарних позиціях у a, перебираємо лише елементи на непарних індексах 
	{ 
        if ((int)a[i] % 2 == 0) // перевіряємо, чи елемент парний
		{ 
            m++; // збільшуємо лічильник m
        }
    }
    b = new double[m]; // виділяємо пам'ять для масиву b розміром m
    int k = 0; // для запису в масив b
    for (int i = 1; i < n; i += 2) // запис парних елементів з a у масив b
	{
        if ((int)a[i] % 2 == 0) 
		{ 
            b[k++] = a[i]; // якщо ел парний то додаємо його до b
        }
    }
}

int main() 
{
    int n; 
    cout << "Vvedit rozmir masuv a: ";
    cin >> n;
    double* a = new double[n]; //виділяємо пам'ять для масиву a
    cout << "Masuv a: ";
    for (int i = 0; i < n; i++) 
	{
        a[i] = rand() % 100; //генерація випадкового числа від 0 до 99
        cout << a[i] << " "; 
    }
    cout << endl;
    double* b; //масив b для збереження парних елементів
    int m; 
    newB(a, n, b, m);
    cout << "Masuv b: ";
    for (int i = 0; i < m; i++) 
	{
        cout << b[i] << " ";
    }
    cout << endl;
    delete[] a; 
    delete[] b; 
    return 0;    
}

