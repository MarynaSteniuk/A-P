#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
    int n;
    cout << "Vvedit rozmir matruci n: ";
    cin >> n;
    int** A = new int*[n]; // Виділення пам'яті для матриці
    for (int i = 0; i < n; ++i)
        A[i] = new int[n];
    cout << "Vvedit elementu matruci:\n";  // Введення елементів матриці
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    double sum = 0; // Обчислення середнього арифметичного
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            sum += A[i][j];
    double avg = sum / (n * n);
    int* result = new int[n];    // Виділення пам'яті для масиву результатів
    for (int i = 0; i < n; ++i)   // Обчислення кількості елементів менших за середнє
	{
        result[i] = 0;
        for (int j = 0; j < n; ++j) 
		{
            if (A[i][j] < avg)
                ++result[i];
        }
    }
    ofstream outFile("result.txt"); // Запис результатів у файл
    for (int i = 0; i < n; ++i) 
	{
        outFile << "Radoc " << i + 1 << ": " << result[i]<<endl;
    }
    outFile.close();
    for (int i = 0; i < n; ++i)  // Вивільнення пам'яті
        delete[] A[i];
    delete[] A;
    delete[] result;
    cout << "Rezultat zapucano y fail result.txt\n";
    return 0;
}

