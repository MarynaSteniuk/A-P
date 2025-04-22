#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Matrix 
{
private:
    int data[2][2]; //зберігає елементи матриці
public:
    void fillRandom(int min=0, int max=9)//метод для заповнення матриці випадковими числами 
	{
        srand(time(0));
        for (int i=0; i<2; ++i) { //цикл для рядків матриці
            for (int j=0; j<2; ++j) {  //вкладений цикл для стовпців матриці
                data[i][j]=min+rand()%(max-min+1); //випадкове число в діапазоні [min, max] та присвоюємо його елементу матриці
            }
        }
    }
    void display() const { //метод для виведення матриці на екран
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                cout<<data[i][j]<< " ";
            }
            cout<<endl;
        }
    }
    //перевантаження операції '+' для додавання матриць
    friend Matrix operator+(const Matrix &m1, const Matrix &m2) 
	{
        Matrix result; //об'єкт result для збереження результату додавання
        for (int i=0; i<2; ++i) //цикл для рядків матриці
		{
            for (int j=0; j<2; ++j) //вкладений цикл для стовпців матриці
			{
                result.data[i][j]=m1.data[i][j]+m2.data[i][j]; //додаємо відповідні елементи двох матриць і записуємо результат у result
            }
        }
        return result;
    }
    //перевантаження операції '-' для віднімання матриць
    friend Matrix operator-(const Matrix &m1, const Matrix &m2) 
	{
        Matrix result;
        for (int i=0; i<2; ++i) 
		{
            for (int j=0; j<2; ++j) 
			{
                result.data[i][j]=m1.data[i][j]-m2.data[i][j];
            }
        }
        return result;
    }
    //перевантаження операції '*' для множення матриць
    friend Matrix operator*(const Matrix &m1, const Matrix &m2) {
        Matrix result;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                result.data[i][j]=0;             //ініціалізуємо поточний елемент матриці result як 0
                for (int k=0; k<2; ++k) {      //вкладений цикл для обчислення суми добутків
                    result.data[i][j]+=m1.data[i][k]*m2.data[k][j]; //виконуємо множення відповідних елементів рядка матриці m1 і стовпця матриці m2 додаючи результат до поточного елемента результатуючої матриці
                }
            }
        }
        return result;
    }
    //перевантаження операції '==' для перевірки рівності матриць
    friend bool operator==(const Matrix &m1, const Matrix &m2) {
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                if (m1.data[i][j]!=m2.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() 
{
    Matrix m1, m2;
    m1.fillRandom();
    m2.fillRandom();
    cout<<"Matrix 1:\n";
    m1.display();
    cout<<"Matrix 2:\n";
    m2.display();
    //демонстрація операцій над матрицями
    Matrix m3=m1+m2;
    cout<<"Suma:\n";
    m3.display();
    Matrix m4=m1-m2;
    cout<<"Riznuzia:\n";
    m4.display();
    Matrix m5=m1*m2;
    cout<<"Dobytok:\n";
    m5.display();
    cout<<"Matrix 1 == Matrix 2: "<<(m1==m2 ? "Yes":"No")<<endl;
    return 0;
}
